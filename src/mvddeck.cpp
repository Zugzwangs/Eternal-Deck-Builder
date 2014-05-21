#include "mvddeck.h"
#include "Global.h"

#include <QApplication>
#include <QPainter>
#include <QPushButton>
#include <QDebug>
#include <QMimeData>
#include <QHeaderView>
#include <QLineEdit>
#include <QPlainTextEdit>
#include <QSpinBox>
#include <QComboBox>

/*****************************************************************************************/
/*   MODEL                                                                               */
/*****************************************************************************************/
PTreeModel::PTreeModel(QObject *parent) : QStandardItemModel(parent)
{
    setupModel();
}

void PTreeModel::setupModel()
{
    modified = false;
    // setup metadatas into a QMap
    for (int i=0; i<VtesInfo::MetasList.count(); i++)
        meta_list.insert( VtesInfo::MetasList.at(i), "0" );
    for (int i=0; i<VtesInfo::VipedList.count(); i++)
        meta_list.insert( VtesInfo::VipedList.at(i), "0" );

    // setup item structure
    QStandardItem *RootItem = this->invisibleRootItem();
    itemCrypt = new SortItem("CRYPTE");
    itemLib   = new SortItem("BIBLIOTHEQUE");
    itemSide  = new SortItem("SIDE");
    RootItem->appendRow( itemCrypt );
    RootItem->appendRow( itemLib );
    RootItem->appendRow( itemSide );
}

void PTreeModel::clearDeck()
{
    modified = false;
    clearMeta();
    itemCrypt->removeRows(0, itemCrypt->rowCount());
    itemLib->removeRows(0, itemLib->rowCount());
    itemCrypt->resetCount();
    itemLib->resetCount();

    emit DeckCleared();
}

void PTreeModel::clearMeta()
{
    QMap<QString, QString>::iterator i;
    for ( i=meta_list.begin(); i!=meta_list.end(); i++)
        {
        i.value() = "";
        }
}

QString PTreeModel::deckName()
{
    QMap<QString, QString>::const_iterator i;
    i= meta_list.find(VtesInfo::MetasList[VtesInfo::indexName]);
    return i.value();
}

bool PTreeModel::isModified()
{
    return modified;
}

void PTreeModel::setUnmodified()
{
    modified = false;
}

void PTreeModel::loadDeck() // ??? mauvais design ???
{
    clearDeck();
    modified = false;
}

void PTreeModel::AddCardItem(QStringList strL, int number)
{
    modified = true;

    if ( number < 1 || number > 255)
        number = 1;

    if (strL.count() < 7) // améliorer la robustesse si on recupere une QStringList incomplète!
        {
        qDebug() << "manque d'informations sur la carte à ajouter !!";
        return;
        }
// Checkout the type of card
QString CardName = strL[1];
QString CardCat = strL[7];
SortItem* Category;

    if ( CardCat == "Vampire" || CardCat == "Imbued" )
        {
        Category = itemCrypt;
        CryptCardItem* TempItem = FindCryptCard( CardName );
        if ( TempItem )
            {
            for (int i=1; i<=number; i++)
                IncrementCardItem( TempItem->index() );
            }
        else
            {
            // the card is not already in the deck => we create it
            CryptCardItem* newCard = new CryptCardItem(strL);
            Category->appendRow(newCard);
            Category->Increment();
            for (int i=1; i<number; i++)
                newCard->Increment();

            emit DeckChanged( Category->index() );
            delete TempItem;
            }
        }

    else // LIBRARY CARD CASE
        {
        Category = itemLib;
        LibraryCardItem* TempItem = FindLibraryCard( CardName );
        if ( TempItem )
            {
            for (int i=1; i<=number; i++)
                IncrementCardItem( TempItem->index() );
            }
        else
            {
            // the card is not already in the deck => we create it
            LibraryCardItem* newCard = new LibraryCardItem(strL);
            Category->appendRow(newCard);
            Category->Increment();
            for (int i=1; i<number; i++)
                {
                newCard->Increment();
                }
            emit DeckChanged( Category->index() );
            delete TempItem;
            }
        }
    return;
}

void PTreeModel::IncrementCardItem( QModelIndex Idx )
{
    if ( itemFromIndex(Idx)->type() == VtesInfo::CryptItemType )
        {
        dynamic_cast<CryptCardItem *>(itemFromIndex(Idx))->Increment();
        }
    else
        dynamic_cast<LibraryCardItem *>(itemFromIndex(Idx))->Increment();

    emit CardItemChanged( Idx );
    emit DeckChanged(Idx.parent());
}

void PTreeModel::DecrementCardItem( QModelIndex Idx )
{
    if ( itemFromIndex(Idx)->type() == VtesInfo::CryptItemType )
        {
        dynamic_cast<CryptCardItem *>(itemFromIndex(Idx))->Decrement();;
        }
    else
        {
        dynamic_cast<LibraryCardItem *>(itemFromIndex(Idx))->Decrement();;
        }

    emit CardItemChanged( Idx );
    emit DeckChanged(Idx.parent());
}

void PTreeModel::RemoveCardITem( QModelIndex Idx )
{
    if (Idx.parent().isValid() )
        {
        int ex = Idx.data(VtesInfo::ExemplairRole).toInt();
        removeRow( Idx.row(), Idx.parent() );
        SortItem *dady = dynamic_cast<SortItem *>(itemFromIndex( Idx.parent() ));
        dady->Decrement(ex);
        emit DeckChanged( Idx.parent() );
        }
}

void PTreeModel::setVipedMeta( QString metaName, int value )
{
    modified = true;
    meta_list.insert( metaName, QString::number(value) );
}

void PTreeModel::setMeta(QString metaName, QString value)
{
    modified = true;
    meta_list.insert( metaName, value );
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
/*                                                                                       */
/*****************************************************************************************/
StatsModel::StatsModel(int rows, int columns, QObject *parent) : QStandardItemModel(rows, columns, parent)
{
}

void StatsModel::clearData(int columns, bool all)
{
    if ( all )
        {
        for (int i=0; i<rowCount(); i++)
            {
            for (int j=0; j<columnCount(); j++)
                {
                QModelIndex temp_index = index(i, columns);
                if ( temp_index.isValid() )
                    {
                    setData( temp_index, 0, Qt::DisplayRole );
                    }
                }
            }
        }
    else
        {
        for (int i=0; i< rowCount(); i++)
            {
            QModelIndex temp_index = index(i, columns);
            if ( temp_index.isValid() )
                {
                setData( temp_index, 0, Qt::DisplayRole );
                }
            }
        }
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
    if ( w && model->meta_list.contains(metadata) )
        {
        // 'tatoo' the widget with metadata
        w->setProperty("meta", metadata);

        if ( qobject_cast<QLineEdit *>(w) )
            connect( w, SIGNAL(textChanged(QString)), this, SLOT(syncLineEdit(QString)) );
        else
            {
            if ( qobject_cast<QPlainTextEdit *>(w) )
                connect( w, SIGNAL(textChanged()), this, SLOT(syncPlainTextEdit()) );
            else
                {
                if ( qobject_cast<QSpinBox *>(w) )
                    connect( w, SIGNAL(valueChanged(const QString &)), this, SLOT(syncSpinBox(const QString &)) );
                else
                    {
                    if ( qobject_cast<QComboBox *>(w) )
                        connect( w, SIGNAL(currentTextChanged(const QString &)), this, SLOT(syncComboBox(const QString &)) );
                    }
                }
            }
        return true;
        }
    else
        return false;
}

bool WidgetMetaMapper::RemoveWidget()
{
    return true;
}

void WidgetMetaMapper::syncLineEdit(QString newData)
{
    QString crt_meta = sender()->property("meta").toString();
    if ( !crt_meta.isNull() )
        model->setMeta( crt_meta, newData );
}

void WidgetMetaMapper::syncPlainTextEdit()
{
    QString crt_meta = sender()->property("meta").toString();
    if ( !crt_meta.isNull() )
        {
        QPlainTextEdit *w = qobject_cast<QPlainTextEdit *>( sender() );
        QTextDocument *doc = w->document();
        model->setMeta( crt_meta, doc->toPlainText() );
    }
}

void WidgetMetaMapper::syncSpinBox(const QString & txt)
{
    QString crt_meta = sender()->property("meta").toString();
    if ( !crt_meta.isNull() )
        {
        model->setMeta( crt_meta, txt );
    }
}

void WidgetMetaMapper::syncComboBox(const QString & newData)
{
    QString crt_meta = sender()->property("meta").toString();
    if ( !crt_meta.isNull() )
        {
        model->setMeta( crt_meta, newData );
    }
}

/*****************************************************************************************/
/*  VIEW                                                                                 */
/*****************************************************************************************/
PTreeView::PTreeView(QWidget *parent) : QTreeView(parent)
{
    setVisible(true);
    setDragDropOverwriteMode(false);
    header()->setStretchLastSection(true);
    setHeaderHidden("true");
    setAnimated(true);
    setIndentation(10);
    setSelectionMode(QAbstractItemView::SingleSelection);
    setIconSize( QSize(0,0) );
}

void PTreeView::setModel(QAbstractItemModel *model)
{
    QTreeView::setModel(model);
    deckModel = dynamic_cast<PTreeModel*>(model);
}

void PTreeView::mousePressEvent(QMouseEvent *event)
{
    QModelIndex index = indexAt(event->pos());
    if ( !index.isValid() )
        return;

    int itemType = deckModel->itemFromIndex(index)->type();

    switch ( itemType )
        {
        case VtesInfo::SortItemType:
            {
            QTreeView::mousePressEvent( event );
            }   break;

        //we add management for the nested buttons : check if user click on
        case VtesInfo::CryptItemType:
        case VtesInfo::LibraryItemType:
            {
            QTreeView::mousePressEvent( event );
            int abscisse = event->pos().x();

            if ( 350<=abscisse && abscisse<=370 )
                {
                emit request_decrement( index );
                }
            else
                {
                if ( 385<=abscisse && abscisse<=405 )
                    {
                    emit request_increment( index );
                    }
                else
                    {
                    if ( 420<=abscisse && abscisse<=440 )

                        emit request_delete( index );
                    }
                }
            }
        }
}

void PTreeView::mouseReleaseEvent(QMouseEvent *event)
{
    QTreeView::mouseReleaseEvent(event);
}

void PTreeView::fakeDrop(QStringList StrL)
{
    // query deck model to add a new card item:
    deckModel->AddCardItem(StrL);
}


/*****************************************************************************************/
/*    DECK DELEGATE                                                                           */
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
        case VtesInfo::CryptItemType   :
            {
            // setup du contexte de dessin
            QStyleOptionViewItemV4 opt(option);
            QStyledItemDelegate::initStyleOption(&opt, index);
            const QWidget *widget = option.widget;
            QStyle *style = widget ? widget->style() : QApplication::style();
            opt.icon = QIcon();

            // setup du paintre
            painter->save();
            painter->setRenderHint(QPainter::Antialiasing);
            painter->setClipRect(opt.rect, Qt::ReplaceClip);

            // dessin de la case de l'item
            opt.text = "                                                                                 ";
            if ( opt.state & QStyle::State_Selected )
                {
                //painter->setPen( QPen(option.palette.highlightedText(), 0) );
                //painter->setBrush( option.palette.highlightedText() );
                style->drawControl(QStyle::CE_ItemViewItem, &opt, painter, widget);
                }
             else
                {
                //painter->setPen( QPen(option.palette.foreground(), 0) );
                //painter->setBrush( qvariant_cast<QBrush>(index.data(Qt::ForegroundRole)) );
                style->drawControl(QStyle::CE_ItemViewItem, &opt, painter, widget);
                }

            // découpage des régions
            // affichage de la forme : [ nbExp | Name card | - | + | x ]
            QRect ExRegion( opt.rect );
            ExRegion.setRight( 60 );
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

            // dessin du nombre d'exemplaires
            style->drawItemText(painter, ExRegion, 1, opt.palette, true, " x" + index.data(VtesInfo::ExemplairRole).toString() );

            // dessin du nom de la carte
            painter->drawText( NameRegion, Qt::AlignLeft, index.data().toString());

            // dessin du bouton - (enlever exemplaire)
            QStyleOptionButton bt_rmex;
            bt_rmex.rect = btMinusRegion;
            bt_rmex.icon = QIcon(":/icons/minus.png");
            bt_rmex.iconSize = btMinusRegion.size();
            bt_rmex.features |= QStyleOptionButton::Flat;
            bt_rmex.state    |= QStyle::State_Enabled;
            style->drawControl( QStyle::CE_PushButton, &bt_rmex, painter);

            // dessin du bouton + (ajouter exemplaire)
            QStyleOptionButton bt_addex;
            bt_addex.rect = btPlusRegion;
            bt_addex.icon = QIcon(":/icons/plus.png");
            bt_addex.iconSize = btPlusRegion.size();
            bt_addex.features |= QStyleOptionButton::Flat;
            bt_addex.state    |= QStyle::State_Enabled;
            style->drawControl( QStyle::CE_PushButton, &bt_addex, painter);

            // dessin du bouton suppression carte
            QStyleOptionButton bt_delete;
            bt_delete.rect = btDeleteRegion;
            bt_delete.icon = QIcon(":/icons/delete.png");
            bt_delete.iconSize = btDeleteRegion.size();
            bt_delete.features |= QStyleOptionButton::Flat;
            bt_delete.state    |= QStyle::State_Enabled;
            style->drawControl( QStyle::CE_PushButton, &bt_delete, painter);

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
                //painter->setPen( QPen(option.palette.highlightedText(), 0) );
                painter->setBrush( option.palette.highlightedText() );
                style->drawControl(QStyle::CE_ItemViewItem, &opt, painter, widget);
                }
            else
                {
                painter->setPen( QPen(option.palette.foreground(), 0) );
                painter->setBrush( qvariant_cast<QBrush>(index.data(Qt::ForegroundRole)) );
                style->drawControl(QStyle::CE_ItemViewItem, &opt, painter, widget);
                }

            // dessin du nom de la catégorie
            painter->setFont(opt.font);
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
    QSize current_size;
    int _type = dynamic_cast<const PTreeModel * >(index.model())->itemFromIndex(index)->type();
    switch ( _type )
        {
        case VtesInfo::SortItemType:
            {
            current_size.setHeight(28);
            current_size.setWidth(100);
            } break;
        case VtesInfo::CryptItemType:
        case VtesInfo::LibraryItemType:
            {
            current_size.setHeight(25);
            current_size.setWidth(100);
            } break;
        }
    return current_size;
}


/*****************************************************************************************/
/*  ITEMS                                                                                */
/*****************************************************************************************/
SortItem::SortItem(QString txt) : QStandardItem(txt)
{
    setEditable(false);
    setSelectable(false);
    setDropEnabled(true);

    setData( QFont("Arial", 9, QFont::Bold), Qt::FontRole);
    setData( data(Qt::DisplayRole), Qt::UserRole );
    setData( 0, VtesInfo::ExemplairRole );
    setData( VtesInfo::SortItemType, VtesInfo::ItemCategoryRole);
}

void SortItem::Increment(int i)
{
    // increment the item counter (should be equal to number of child pondered by each child multipliers)
    // this is the model's responsability to correctly increment this value
    setData( data(VtesInfo::ExemplairRole).toInt()+i, VtesInfo::ExemplairRole );
}

void SortItem::Decrement(int i)
{
    if ( data(VtesInfo::ExemplairRole).toInt() > 0 )
        setData( data(VtesInfo::ExemplairRole).toInt()-i, VtesInfo::ExemplairRole );
}

void SortItem::resetCount()
{
    setData( 0, VtesInfo::ExemplairRole );
}

int SortItem::type() const  { return (VtesInfo::SortItemType); }

SortItem::~SortItem()   {}


// A CRYPT CARD ITEM
CryptCardItem::CryptCardItem(QStringList strL) : QObject(), QStandardItem()
{
    // set item properties
    setEditable(false);
    setSelectable(true);
    setDropEnabled(false);

    // we set technicals datas
    setData( 1, VtesInfo::ExemplairRole );
    setData( VtesInfo::CryptItemType, VtesInfo::ItemCategoryRole);
    QString CardName = strL[3] + ".jpg";
    path_list.initPaths();
    QString PathCartes = path_list.getCardPath();
    setData( QIcon( PathCartes + "/" + CardName), Qt::DecorationRole);

    // we set all game datas
    setData( strL[1], Qt::DisplayRole);
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

void CryptCardItem::Increment()
{
    setData( data(VtesInfo::ExemplairRole).toInt()+1, VtesInfo::ExemplairRole );
    SortItem *dady = dynamic_cast<SortItem *>( model()->itemFromIndex(index().parent()) );
    dady->Increment();
}

void CryptCardItem::Decrement()
{
    int cpt = data(VtesInfo::ExemplairRole).toInt();
    if ( cpt > 1 )
        {
        setData( data(VtesInfo::ExemplairRole).toInt()-1, VtesInfo::ExemplairRole );
        SortItem *dady = dynamic_cast<SortItem *>( model()->itemFromIndex(index().parent()) );
        dady->Decrement();
        }
    else
        {
        setData( 1, VtesInfo::ExemplairRole );
        }
}

int CryptCardItem::type() const  { return VtesInfo::CryptItemType; }

CryptCardItem::~CryptCardItem()
{
}


// A LIBRARY CARD ITEM
LibraryCardItem::LibraryCardItem(QStringList strL) : QObject(),QStandardItem()
{
    // set item properties
    setEditable(false);
    setSelectable(true);
    setDropEnabled(false);

    // we set technicals datas
    setData( 1, VtesInfo::ExemplairRole );
    setData( VtesInfo::LibraryItemType, VtesInfo::ItemCategoryRole);
    QString CardName = strL[3] + ".jpg";
    path_list.initPaths();
    QString PathCartes = path_list.getCardPath();
    setData( QIcon( PathCartes + "/" + CardName), Qt::DecorationRole);

    // we set all game datas
    setData( strL[1], Qt::DisplayRole);
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
    SortItem *dady = dynamic_cast<SortItem *>( model()->itemFromIndex(index().parent()) );
    dady->Increment();
}

void LibraryCardItem::Decrement()
{
    int cpt = data(VtesInfo::ExemplairRole).toInt();
    if ( cpt > 1 )
        {
        setData( data(VtesInfo::ExemplairRole).toInt()-1, VtesInfo::ExemplairRole );
        SortItem *dady = dynamic_cast<SortItem *>( model()->itemFromIndex(index().parent()) );
        dady->Decrement();
        }
    else
        {
        setData( 1, VtesInfo::ExemplairRole );
        }
}

int LibraryCardItem::type() const  { return VtesInfo::LibraryItemType; }

LibraryCardItem::~LibraryCardItem()
{
}


/*****************************************************************************************/
/*  QUICK DECK VIEW (partial crypt/library)                                                                           */
/*****************************************************************************************/
PartialDeckView::PartialDeckView(QWidget *parent) : QTreeView(parent)
{
    setHeaderHidden(true);
    setSelectionMode(QAbstractItemView::SingleSelection);
    setAcceptDrops(true);
    setIconSize( QSize(-1,-1) );
}

void PartialDeckView::dragEnterEvent(QDragEnterEvent *event)
{
if (event->mimeData()->hasFormat("text/plain"))
    {
    event->setDropAction(Qt::CopyAction);
    event->accept();
    }
}

void PartialDeckView::dragMoveEvent(QDragMoveEvent *event)
{
if (event->mimeData()->hasFormat("text/plain"))
    {
    event->setDropAction(Qt::CopyAction);
    event->accept();
    }
}

void PartialDeckView::dropEvent(QDropEvent *event)
{
QString TempData;
QStringList ListofData;

    // on recup les données du drop | on les split | on chope le nom de la carte
    TempData = event->mimeData()->text();
    ListofData = TempData.split("\n",QString::KeepEmptyParts);
    // query the deck model to take the card
    dynamic_cast<PTreeModel *>( model())->AddCardItem(ListofData);
}

void PartialDeckView::AddCardToDeck(QString str)
{
    QStringList ListofData = str.split("\n",QString::KeepEmptyParts);
    // query the deck model to take the card
    dynamic_cast<PTreeModel *>( model())->AddCardItem(ListofData);
}

PartialDeckView::~PartialDeckView() {}


