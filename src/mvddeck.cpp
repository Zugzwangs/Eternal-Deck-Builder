#include "mvddeck.h"
#include "Global.h"

#include <QApplication>
#include <QPainter>
#include <QPushButton>
#include <QDebug>

/*****************************************************************************************/
/*   MODEL                                                                               */
/*****************************************************************************************/
PTreeModel::PTreeModel(QObject *parent) : QStandardItemModel(parent)
{
// metadatas are stored into a QMap
meta_list.insert("name","choose a name");
meta_list.insert("author","naruto[666]");
meta_list.insert("description","more lame than this, you die");

QStandardItem *RootItem = this->invisibleRootItem();

itemCrypt = new SortItem("CRYPTE");
itemLib   = new SortItem("BIBLIOTHEQUE");
itemSide  = new SortItem("SIDE");

RootItem->appendRow( itemCrypt );
RootItem->appendRow( itemLib );
RootItem->appendRow( itemSide );
}

void PTreeModel::AddCardItem(QStringList strL)
{
// We create the new CardItem object
CardItem* newCard = new CardItem(strL);

// Checkout the kind of cards
QString CardCat = newCard->data(Qt::UserRole).toString();
QString CardName = newCard->data(Qt::DisplayRole).toString();
SortItem* Category;
if ( CardCat == "Vampire" || CardCat == "Imbued" )
    { Category = itemCrypt; }
else
    { Category = itemLib; }

// Checkout if this card already exists in the list
CardItem* TempItem;
for ( int i=0; i<Category->rowCount(); i++ )
    {
    TempItem = dynamic_cast<CardItem *>( Category->child(i) );
    if ( TempItem->data(Qt::DisplayRole).toString() == CardName )
        {
        TempItem->Increment();
        delete newCard;
        return;
        }
    }

// the card is not there, so we add it in the right SortItem
Category->appendRow(newCard);
}


/*****************************************************************************************/
/*  META MAPPER                                                                          */
/*****************************************************************************************/
WidgetMetaMapper::WidgetMetaMapper(QObject *parent) : QObject(parent)   {}

void WidgetMetaMapper::SetModel( PTreeModel* mdl )
{
    model = mdl;
}

bool WidgetMetaMapper::AddWidget( QWidget* w, QString metadata )
{
    if ( model->meta_list.contains(metadata) )
        {
        connect( w, SIGNAL(textChanged(QString)), this, SLOT(synchroDatas(QString)) );
        w->setAccessibleName(metadata);
        w->setProperty("text", model->meta_list.value(metadata));
        return true;
        }
    else
        return false;
}

bool WidgetMetaMapper::RemoveWidget()
{
    return true;
}

void WidgetMetaMapper::synchroDatas(QString newData)
{
    QString crt_meta = sender()->property("setAccessibleName").toString();
    model->meta_list.insert(crt_meta, newData );
}


/*****************************************************************************************/
/*  VIEW                                                                                 */
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
deckModel = dynamic_cast<PTreeModel*>(model);
}

void PTreeView::fakeDrop(QStringList StrL)
{
    // query deck model to add a new card item:
    qDebug() << "PLZ ADD THIS CARD FOR ME DUDE";
    deckModel->AddCardItem(StrL);
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

SortItem::~SortItem()   {}

int SortItem::type() const  { return (VtesInfo::ItemSortType); }

//
CardItem::CardItem(QStringList strL) : QStandardItem(strL[1])
{
    setText(strL[1]);
    setData( strL[1], Qt::DisplayRole );
    setData( strL[7], Qt::UserRole );
    setData( 1, Qt::UserRole+1 );
    setData( strL, Qt::UserRole+2 );
}
void CardItem::Increment()
{
    setData( data(Qt::UserRole+1).toInt()+1, Qt::UserRole+1 );
}


CardItem::~CardItem()   {}

int CardItem::type() const  { return VtesInfo::ItemCardType; }


/*****************************************************************************************/
/*  PROXY MODEL                                                                          */
/*****************************************************************************************/









