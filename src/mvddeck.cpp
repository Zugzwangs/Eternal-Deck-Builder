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

/* GESTION DES METADONNEES DU DECK A VOIR PLUS TARD !!!
nom+format+commentaire+perfs+avatar+ ...
caler toutes les données dans le invisible root item serait peut etre sympa avec un Qdatamapper vers un formulaire
pour gerer tout ca !
*itemMeta = new SortItem("METADONNEES");
RootItem->appendRow( itemMeta );
QList<MetaItem *> ListItemMeta;
ListItemMeta.append( new MetaItem("Nom") );
ListItemMeta.append( new MetaItem("Auteur") );
ListItemMeta.append( new MetaItem("Commentaires") );
itemMeta->appendColumn(ListItemMeta);*/

RootItem->appendRow( new SortItem("CRYPTE") );
RootItem->appendRow( new SortItem("BIBLIOTHEQUE") );
RootItem->appendRow( new SortItem("SIDE") );
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

    // we've got the list of datas, we need to figure out the card's category and name
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

    if ( index.isValid() && index.data().toString() == "" )
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
    this->setEditable(false);
    this->setData( this->data(Qt::DisplayRole), Qt::UserRole );
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
    this->setEditable(true);
    this->setData( this->data(Qt::DisplayRole) , Qt::ToolTipRole );
    this->setData( this->data(Qt::DisplayRole) , Qt::UserRole );
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
