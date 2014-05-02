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
// Checkout the type of card
QString CardName = strL[1];
QString CardCat = strL[7];
SortItem* Category;

    if ( CardCat == "Vampire" || CardCat == "Imbued" )
        {
        Category = itemCrypt;
        CryptCardItem* newCard = new CryptCardItem(strL);
        CryptCardItem* TempItem = FindCryptCard( CardName );
        if ( TempItem )
            {
            TempItem->Increment();
            Category->Increment();
            emit CardAdded(Category->index(), TempItem->index());
            delete newCard;
            }
        else
            {
            // the card is not there, so we add it in the right SortItem
            Category->appendRow(newCard);
            Category->Increment();
            connect( newCard, SIGNAL(request_deleting(QModelIndex)), this, SLOT(RemoveCardITem(QModelIndex)) );
            emit CardAdded(Category->index(), newCard->index());
            delete TempItem;
            }
        }

    else // LIBRARY CARD CASE
        {
        Category = itemLib;
        LibraryCardItem* newCard = new LibraryCardItem(strL);
        LibraryCardItem* TempItem = FindLibraryCard( CardName );
        if ( TempItem )
            {
            TempItem->Increment();
            Category->Increment();
            emit CardAdded(Category->index(), TempItem->index());
            delete newCard;
            }
        else
            {
            // the card is not there, so we add it in the right SortItem
            Category->appendRow(newCard);
            Category->Increment();
            emit CardAdded(Category->index(), newCard->index());
            delete TempItem;
            }
        }
    return;
}

void PTreeModel::RemoveCardITem( QModelIndex Idx )
{
    QModelIndex dady = Idx.parent();
    if (dady.isValid() )
        {
        removeRow( Idx.row(), dady);
        emit CardRemoved();
        }
}

CryptCardItem* PTreeModel::FindCryptCard( QString CardName )
{

CryptCardItem* TempItem;

    for ( int i=0; i<itemCrypt->rowCount(); i++ )
        {
        TempItem = dynamic_cast<CryptCardItem *>( itemCrypt->child(i) );
        if ( TempItem->data(VtesInfo::NameRole).toString() == CardName )
            {
            return TempItem;
            }
        }
return NULL;
}

LibraryCardItem* PTreeModel::FindLibraryCard( QString CardName )
{

LibraryCardItem* TempItem;

    for ( int i=0; i<itemLib->rowCount(); i++ )
        {
        TempItem = dynamic_cast<LibraryCardItem *>( itemLib->child(i) );
        if ( TempItem->data(VtesInfo::NameRole).toString() == CardName )
            {
            return TempItem;
            }
        }
return NULL;
}

/*****************************************************************************************/
/*  THE OVER VIEW MODEL                                                                  */
/*  THE FIRST COLUMN IS ABOUT THE CRYPT STATS. EACH ROW HOLD THE NUMBER OF VAMPIRE WHERE */
/*  ROW == GENERATION                                                                    */
/*  THE SECOND COLUMN HOLDS LIBRARY STATS                                                */
/*****************************************************************************************/
StatsModel::StatsModel(QObject *parent) : QStandardItemModel(11, 2, parent)
{

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
    if ( !index.isValid() )
        return;

    int cat = index.data(VtesInfo::ItemCategoryRole).toInt();

    switch (cat)
        {
        case VtesInfo::LibraryItemType :

        case VtesInfo::CryptItemType :
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
                // prend en charge l'affichage en mode focus
                //painter->setPen(Qt::white);
                painter->setBrush( option.palette.highlightedText() );
                //style->drawControl(QStyle::CE_ItemViewItem, &opt, painter, widget);
                }
            else
                {
                painter->setPen( QPen(option.palette.foreground(), 0) );
                painter->setBrush(qvariant_cast<QBrush>(index.data(Qt::ForegroundRole)));
                }

            // dessin du nombre d'exemplaires
            style->drawItemText(painter, ExRegion, 1, opt.palette, true, "x" + index.data(VtesInfo::ExemplairRole).toString() );

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

            // dessin du bouton suppression carte
            QStyleOptionButton* bt_delete = new QStyleOptionButton();
            bt_delete->rect = btDeleteRegion;
            bt_delete->icon = QIcon(":/icons/delete.png");
            bt_delete->iconSize = btDeleteRegion.size();
            style->drawControl( QStyle::CE_PushButton, bt_delete, painter);

            // test autre méthode de dessin
            /*
            QPushButton *fock = new QPushButton();
            fock->setGeometry(btDeleteRegion);
            fock->setIcon(QIcon(":/icons/delete.png"));
            fock->setIconSize(btDeleteRegion.size());
            fock->setStyleSheet("border: none;");
            fock->render(painter);
            */

            painter->restore();
            }   break;

        case VtesInfo::SortItemType:
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
            QRect TextRegion( opt.rect );
            TextRegion.setWidth( opt.rect.width()-80 );
            QRect ExRegion( opt.rect );
            ExRegion.setLeft( TextRegion.right() );

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
            painter->drawText( TextRegion, Qt::AlignLeft, index.data().toString());

            // dessin du nombre de carte dans la catégorie
            style->drawItemText(painter, ExRegion, 1, opt.palette, true, "[" + index.data(VtesInfo::ExemplairRole).toString() + "]" );
            painter->restore();
            }   break;

        default :
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
    setEditable(false);
    setData( data(Qt::DisplayRole), Qt::UserRole );
    setData( 0, VtesInfo::ExemplairRole );
    setData( VtesInfo::SortItemType, VtesInfo::ItemCategoryRole);
}

void SortItem::Increment(int i)
{
    // increment the item counter (should be equal to number of child pondered by each child multipliers)
    // this is the responsability of the model to correctly increment this property !
    setData( data(VtesInfo::ExemplairRole).toInt()+i, VtesInfo::ExemplairRole );
}

int SortItem::type() const  { return (VtesInfo::SortItemType); }

SortItem::~SortItem()   {}


// A CRYPT CARD ITEM
CryptCardItem::CryptCardItem(QStringList strL) : QObject(), QStandardItem(strL[1])
{
    setEditable(false);
    // we set technicals datas
    setData( 1, VtesInfo::ExemplairRole );
    setData( VtesInfo::CryptItemType, VtesInfo::ItemCategoryRole);
    // we set all game datas
    setData( strL[1], VtesInfo::NameRole );
    setData( strL[2], VtesInfo::SetsRole );
    setData( strL[3], VtesInfo::ImageFileRole );
    setData( strL[4], VtesInfo::URLCarteRole );
    setData( strL[5], VtesInfo::ExpansionRole );
    setData( strL[6], VtesInfo::RarityRole );
    setData( strL[7], VtesInfo::TypeRole );
    setData( strL[8], VtesInfo::ClanRole );
    setData( strL[9], VtesInfo::GroupingRole );
    setData( strL[10], VtesInfo::CapacityRole );
    setData( strL[11], VtesInfo::DisciplineRole );
    setData( strL[12], VtesInfo::SectRole );
    setData( strL[13], VtesInfo::TitleRole );
    setData( strL[14], VtesInfo::TraitRole );
    setData( strL[15], VtesInfo::KeyWordsRole );
    setData( strL[16], VtesInfo::LimitationRole );
    setData( strL[17], VtesInfo::TextRole );
    setData( strL[18], VtesInfo::ArtistRole );
    setData( strL[19], VtesInfo::CommentaryRole );
}

void CryptCardItem::Increment() { setData( data(VtesInfo::ExemplairRole).toInt()+1, VtesInfo::ExemplairRole ); }

void CryptCardItem::Decrement()
{
    int cpt = data(VtesInfo::ExemplairRole).toInt();
    if ( cpt > 1 )
        setData( data(VtesInfo::ExemplairRole).toInt()-1, VtesInfo::ExemplairRole );
    else
        {
        setData( 0, VtesInfo::ExemplairRole );
        emit request_deleting( index() );
        }
}

int CryptCardItem::type() const  { return VtesInfo::CryptItemType; }

CryptCardItem::~CryptCardItem()   {}


// A LIBRARY CARD ITEM
LibraryCardItem::LibraryCardItem(QStringList strL) : QObject(),QStandardItem(strL[1])
{
    setEditable(false);

    // we set technicals datas
    setData( 1, VtesInfo::ExemplairRole );
    setData( VtesInfo::LibraryItemType, VtesInfo::ItemCategoryRole);

    // we set all game datas
    setData( strL[1], VtesInfo::NameRole );
    setData( strL[2], VtesInfo::SetsRole );
    setData( strL[3], VtesInfo::ImageFileRole );
    setData( strL[4], VtesInfo::URLCarteRole );
    setData( strL[5], VtesInfo::ExpansionRole );
    setData( strL[6], VtesInfo::RarityRole );
    setData( strL[7], VtesInfo::TypeRole );
    setData( strL[8], VtesInfo::SubTypeRole );
    setData( strL[9], VtesInfo::ClanRole );
    setData( strL[10], VtesInfo::CapacityRole );
    setData( strL[11], VtesInfo::DisciplineRole );
    setData( strL[12], VtesInfo::SectRole );
    setData( strL[13], VtesInfo::PCostRole );
    setData( strL[14], VtesInfo::BCostRole );
    setData( strL[15], VtesInfo::CCostRole );
    setData( strL[16], VtesInfo::TitleRole );
    setData( strL[17], VtesInfo::TraitRole );
    setData( strL[18], VtesInfo::KeyWordsRole );
    setData( strL[19], VtesInfo::LimitationRole );
    setData( strL[20], VtesInfo::TextRole );
    setData( strL[21], VtesInfo::ArtistRole );
    setData( strL[22], VtesInfo::CommentaryRole );
}

void LibraryCardItem::Increment()
{
    setData( data(VtesInfo::ExemplairRole).toInt()+1, VtesInfo::ExemplairRole );
}

void LibraryCardItem::Decrement()
{
    int cpt = data(VtesInfo::ExemplairRole).toInt();
    if ( cpt > 1 )
        setData( data(VtesInfo::ExemplairRole).toInt()-1, VtesInfo::ExemplairRole );
    else
        {
        setData( 0, VtesInfo::ExemplairRole );
        emit request_deleting( index() );
        }
}

int LibraryCardItem::type() const  { return VtesInfo::LibraryItemType; }

LibraryCardItem::~LibraryCardItem()   {}


/*****************************************************************************************/
/*  PROXY MODEL                                                                          */
/*****************************************************************************************/
CryptProxy::CryptProxy(QObject *parent) : QSortFilterProxyModel(parent)
{
    setFilterRole( Qt::UserRole );
    setFilterRegExp( QRegExp("CRYPTE|Vampire|Imbued", Qt::CaseSensitive) ); //
}

LibraryProxy::LibraryProxy(QObject *parent) : QSortFilterProxyModel(parent)
{

}







