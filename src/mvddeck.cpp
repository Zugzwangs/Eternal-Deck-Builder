#include "mvddeck.h"
#include "Global.h"

#include <QApplication>
#include <QPainter>
#include <QPushButton>

/*****************************************************************************************/
/*   MODEL                                                                               */
/*****************************************************************************************/
PTreeModel::PTreeModel(QObject *parent) : QStandardItemModel(parent)
{
QStandardItem *RootItem = this->invisibleRootItem();

itemMeta = new QStandardItem("METADONNEES");
itemMeta->setEditable(false);
RootItem->appendRow(itemMeta);

QList<QStandardItem *> ListItemMeta;
ListItemMeta.append(new QStandardItem("Nom"));
ListItemMeta.append(new QStandardItem("Auteur"));
ListItemMeta.append(new QStandardItem("Commentaires"));
for (int i=0; i<ListItemMeta.length(); i++)
    {
    //ListItemMeta.at(i)->setEditable(false);
    ListItemMeta.at(i)->setData( ListItemMeta.at(i)->data(Qt::DisplayRole) , Qt::UserRole );
    ListItemMeta.at(i)->setData("meta",Qt::UserRole+1);
    }
itemMeta->appendColumn(ListItemMeta);

itemMeta = new QStandardItem("CRYPTE");
itemMeta->setEditable(false);
RootItem->appendRow(itemMeta);

itemMeta = new QStandardItem("BIBLIOTHEQUE");
itemMeta->setEditable(false);
RootItem->appendRow(itemMeta);
}


/*****************************************************************************************/
/*  VIEW                                                                               */
/*****************************************************************************************/
PTreeView::PTreeView(QWidget *parent) : QTreeView(parent)
{
setVisible(true);
setDragDropOverwriteMode(false);
setHeaderHidden("true");
setAnimated(true);
setIndentation(10);
}

void PTreeView::setModel(QAbstractItemModel *model)
{
QTreeView::setModel(model);
}

void PTreeView::fakeDrop(QStringList StrL)
{
QString CardName;
QString CardCat;
QString Category;

    // we've got the list of datas, we need to figure out the card's category and his name
    CardName = StrL[1].trimmed();
    CardCat = StrL[7].trimmed();

    if ( CardCat == "Vampire" || CardCat == "Imbued" )
        { Category = "CRYPTE"; }
    else
        { Category = "BIBLIOTHEQUE"; }

    // Checkout if this card is already in the list
    PTreeModel *modelcourant=dynamic_cast<PTreeModel*>(this->model());
    QList<QStandardItem *> ItemPool = modelcourant->findItems(Category);
    QStandardItem* TempItem;
    for (int i=0; i<ItemPool[0]->rowCount(); i++)
        {
        TempItem = ItemPool[0]->child(i);
        if ( CardName == TempItem->text())
            {
            //if true, increment the exemplair value and exit
            TempItem->setData(TempItem->data(Qt::UserRole+2).toInt()+1,Qt::UserRole+2);
            return;
            }
        }

    // the card is not already in the model, so we add it
    QStandardItem* NouvelItem = new QStandardItem(CardName);
    NouvelItem->setData(StrL,Qt::UserRole);
    NouvelItem->setData(1,Qt::UserRole+2);
    NouvelItem->setEditable(false);
    if ( Category == "BIBLIOTHEQUE" )
        {
        NouvelItem->setData("LibraryCard",Qt::UserRole+1);
        ItemPool[0]->appendRow(NouvelItem);
        }
    else
        {
        NouvelItem->setData("CryptCard",Qt::UserRole+1);
        ItemPool[0]->appendRow(NouvelItem);
        }
}


/*****************************************************************************************/
/*    DELEGATE                                                                           */
/*****************************************************************************************/
PDelegateDeck::PDelegateDeck(QObject *parent) : QStyledItemDelegate(parent)
{
}

void PDelegateDeck::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if ( index.isValid() && index.data(Qt::UserRole+1).toString() == "meta" )
        {
        //dessin spécifique pour les métadonnées:
        // setup du contexte de dessin
        QStyleOptionViewItemV4 opt(option);
        QStyledItemDelegate::initStyleOption(&opt, index);
        const QWidget *widget = option.widget;
        QStyle *style = widget ? widget->style() : QApplication::style();

        // setup du paintre
        painter->save();
        painter->setRenderHint(QPainter::Antialiasing);
        painter->setClipRect(opt.rect, Qt::ReplaceClip);

        QRect LRegion( opt.rect );
        LRegion.setWidth( 100 );
        QRect RRegion( opt.rect );
        RRegion.setLeft( LRegion.right() );

        // dessin de la case
        opt.text = "";
        if ( opt.state & QStyle::State_Selected )
            {
            painter->setBrush( option.palette.highlightedText() );
            style->drawControl(QStyle::CE_ItemViewItem, &opt, painter, widget);
            }
        else
            {
            painter->setPen( QPen(option.palette.windowText(), 0) );
            }

        // dessin du nom de la carte
        painter->drawText( LRegion, Qt::AlignLeft, index.data(Qt::UserRole).toString());
        painter->drawText( RRegion, Qt::AlignCenter, index.data(Qt::EditRole).toString());

        painter->restore();
        }

    else if ( index.isValid() && ( index.data(Qt::UserRole+1).toString() == "CryptCard" ||  index.data(Qt::UserRole+1).toString() == "LibraryCard" ) )
        {
        // setup du contexte de dessin
        QStyleOptionViewItemV4 opt(option);
        QStyledItemDelegate::initStyleOption(&opt, index);
        const QWidget *widget = option.widget;
        QStyle *style = widget ? widget->style() : QApplication::style();

        // setup du paintre
        painter->save();
        painter->setRenderHint(QPainter::Antialiasing);
        painter->setClipRect(opt.rect, Qt::ReplaceClip);

        // découpage des régions
        // affichage de la forme : [ nbExp | Name card | - | + | x ]
        QRect ExRegion( opt.rect );
        ExRegion.setRight( 50 );
        QRect ButtonsRegion( opt.rect );
        ButtonsRegion.setLeft( ButtonsRegion.right() - 100 );
        QRect btMinusRegion( ButtonsRegion);
        btMinusRegion.setWidth( 30 );
        QRect btPlusRegion( ButtonsRegion);
        btPlusRegion.setLeft( btMinusRegion.right()+5 );
        btPlusRegion.setWidth( 30 );
        QRect btDeleteRegion( ButtonsRegion );
        btDeleteRegion.setLeft( btPlusRegion.right()+5  );
        btDeleteRegion.setWidth( 30 );
        QRect NameRegion( opt.rect );
        NameRegion.setLeft( ExRegion.right() );
        NameRegion.setRight( ButtonsRegion.left() );

        // dessin de la case
        opt.text = "";
        if ( opt.state & QStyle::State_Selected )
            {
            //painter->setPen( QPen(option.palette.highlightedText(), 0) );
            painter->setBrush( option.palette.highlightedText() );
            // prend en charge l'affichage du focus
            style->drawControl(QStyle::CE_ItemViewItem, &opt, painter, widget);
            }
        else
            {
            painter->setPen( QPen(option.palette.windowText(), 0) );
            //painter->setBrush(qvariant_cast<QBrush>(index.data(Qt::ForegroundRole)));
            }

        // dessin du nom de la carte
        painter->drawText( NameRegion, Qt::AlignLeft, index.data().toString());

        // dessin du bouton - (enlever exemplaire)
        QStyleOptionButton*  bt_rmex = new QStyleOptionButton;
        bt_rmex->rect = btMinusRegion;
        bt_rmex->icon = QIcon(":/icons/minus.png");
        bt_rmex->iconSize = btMinusRegion.size();

        style->drawControl( QStyle::CE_PushButton, bt_rmex, painter);

        // dessin du bouton + (ajouter exemplaire)
        QStyleOptionButton*  bt_addex = new QStyleOptionButton;
        bt_addex->rect = btPlusRegion;
        bt_addex->icon = QIcon(":/icons/plus.png");
        bt_addex->iconSize = btPlusRegion.size();
        style->drawControl( QStyle::CE_PushButton, bt_addex, painter);

        QPushButton *fock = new QPushButton();
        fock->setGeometry(btDeleteRegion);
        fock->setIcon(QIcon(":/icons/delete.png"));
        fock->setStyleSheet("border: none;");
        fock->render(painter);
        //fock->setIconSize(btDeleteRegion.size());

        /*QStyleOptionButton* bt_delete = new QStyleOptionButton();
        bt_delete->initFrom(fock);
        style->drawControl(QStyle::CE_PushButton, bt_delete, painter);*/

        // dessin du bouton delete
        /*QStyleOptionButton* bt_delete = new QStyleOptionButton();
        bt_delete->rect = btDeleteRegion;
        bt_delete->icon = QIcon(":/icons/delete.png");
        bt_delete->iconSize = btDeleteRegion.size();
        style->drawControl( QStyle::CE_PushButton, bt_delete, painter);*/

        // dessin du nombre d'exemplaires
        style->drawItemText(painter, ExRegion, 1, opt.palette, true, "x" + index.data(Qt::UserRole+2).toString() );

        painter->restore();
        }
    else
        {
        QStyledItemDelegate::paint(painter, option, index);
        }
}

QSize PDelegateDeck::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    return QStyledItemDelegate::sizeHint(option, index);
}


/*****************************************************************************************/
/*  ITEMS                                                                                */
/*****************************************************************************************/

//
SortItem::SortItem(QString txt) : QStandardItem(txt)
{

}

SortItem::~SortItem()
{
}

int SortItem::type() const
{
    return (VtesInfo::ItemSortType);
}

//
MetaItem::MetaItem(QString txt) : QStandardItem(txt)
{

}

MetaItem::~MetaItem()
{
}

int MetaItem::type() const
{
    return VtesInfo::ItemMetadataType;
}

//
CardItem::CardItem() : QStandardItem()
{

}

CardItem::~CardItem()
{
}

int CardItem::type() const
{
    return VtesInfo::ItemCardType;
}


/*****************************************************************************************/
/*  PROXY MODEL                                                                          */
/*****************************************************************************************/


// ??
