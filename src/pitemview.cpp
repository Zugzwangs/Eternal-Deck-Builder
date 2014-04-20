#include "pitemview.h"
#include "mainwindow.h"
#include "Global.h"
#include <QDrag>
#include <QPushButton>

//*******************************************************************************************************
//                                  LES VIEWS
//*******************************************************************************************************

// RESULT VIEWS
PItemView::PItemView(QWidget *parent) : QTableView(parent)
{
setSelectionMode(SingleSelection);
setSelectionBehavior(SelectRows);
setAcceptDrops(true);
setDropIndicatorShown(true);
setDragEnabled(true);
setDragDropOverwriteMode(false);
setDragDropMode(DragOnly);
setSortingEnabled(true);
setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void PItemView::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
        { startPos = event->pos(); }
    QTableView::mousePressEvent(event);
}

void PItemView::mouseMoveEvent(QMouseEvent *event)
{
    if(event->buttons() & Qt::LeftButton)
    {
        int distance = (event->pos() - startPos).manhattanLength();
        if (distance >= QApplication::startDragDistance())
        { startDrag(); }
    }
    QTableView::mouseMoveEvent(event);
}

void PItemView::startDrag()
{
QModelIndexList CurrentSelection = selectedIndexes();
QModelIndex CurrentIndex;
QString PathDragIcone;
QDir DossierAppli;
QImage IconeDrag;
QString TempData;
QMimeData *DraggedData = new QMimeData;
QDrag *Drag = new QDrag(this);

DossierAppli.setPath(QCoreApplication::applicationDirPath());
if (DossierAppli.cd("Cartes"))
    { PathDragIcone = DossierAppli.absolutePath(); }
PathDragIcone = PathDragIcone + "/" + "Vtes_Grelarge.gif";

//On enregistre toutes les données de la carte dans le drag
CurrentIndex = CurrentSelection.first();
for (int i=0; i<=this->model()->columnCount(); i++)
    {
    TempData.append(CurrentIndex.model()->index(CurrentIndex.row(),i).data(Qt::DisplayRole).toString() + "\n");
    }

DraggedData->setText(TempData);

if (IconeDrag.load(PathDragIcone))
{Drag->setPixmap(QPixmap::fromImage(IconeDrag));}
Drag->setMimeData(DraggedData);
Drag->exec(Qt::CopyAction);
}

void PItemView::dragLeaveEvent(QDragLeaveEvent *event)
{
    /*MMh pas tres utile ; à jeter peut etre*/
}

// DECK VIEW
PTreeView::PTreeView(QWidget *parent) : QTreeView(parent)
{
setVisible(true);
setDragDropOverwriteMode(false);
setHeaderHidden("true");
setAnimated(true);
setIndentation(10);
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

//*******************************************************************************************************
//                                  LES MODELES DE DONNEES
//*******************************************************************************************************

// MODEL DE DONNEES DES TABLES SQL
PSqlTableModel::PSqlTableModel(QObject *parent) : QSqlTableModel()
{
}

// MODEL DE DONNEES DU DECK
PTreeModel::PTreeModel() : QStandardItemModel()
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

//*******************************************************************************************************
//                                  LES DELEGATES
//*******************************************************************************************************

// DELEGATE CRYPT
PDelegateCryptResult::PDelegateCryptResult(QObject *parent) : QStyledItemDelegate(parent)
{
PathImages = QCoreApplication::applicationDirPath() + "/Images/";
}

void PDelegateCryptResult::paint(QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index ) const
{
switch(index.column())
    {
    case 8: // CASE CLAN
        {
        // setup du contexte de dessin
        QStyleOptionViewItemV4 opt(option);
        QStyledItemDelegate::initStyleOption(&opt, index);
        opt.text = "";
        const QWidget *widget = option.widget;
        QStyle *style = widget ? widget->style() : QApplication::style();

        // setup du peintre
        painter->save();
        painter->setRenderHint(QPainter::Antialiasing);
        painter->setClipRect(opt.rect, Qt::ReplaceClip);

        // prise en charge de l'état hightlighted
        if ( opt.state & QStyle::State_Selected )
            {
            painter->setBrush( option.palette.highlightedText() );
            // prend en charge l'affichage du focus
            style->drawControl(QStyle::CE_ItemViewItem, &opt, painter, widget);
            }

        // dessin du clan
        QString clan = index.data().toString() + ".gif";
        QPixmap clanPixmap(":/icons/clan/" + clan);
        QRect target(opt.rect.x()+15, opt.rect.center().y()-15, 30, 30);
        painter->drawPixmap(target, clanPixmap);
        painter->restore();
        }break;

    case 9: // CASE GROUPING
        {
        // setup du contexte de dessin
        QStyleOptionViewItemV4 opt(option);
        QStyledItemDelegate::initStyleOption(&opt, index);
        opt.text = "";
        const QWidget *widget = option.widget;
        QStyle *style = widget ? widget->style() : QApplication::style();

        // setup du peintre
        painter->save();
        painter->setRenderHint(QPainter::Antialiasing);
        painter->setClipRect(opt.rect, Qt::ReplaceClip);

        // prise en charge de l'état hightlighted
        if ( opt.state & QStyle::State_Selected )
            {
            painter->setPen(Qt::white);
            painter->setBrush( option.palette.highlightedText() );
            // prend en charge l'affichage du focus
            style->drawControl(QStyle::CE_ItemViewItem, &opt, painter, widget);
            }
        else
            {
            painter->setPen( QPen(option.palette.foreground(), 0) );
            painter->setBrush(qvariant_cast<QBrush>(index.data(Qt::ForegroundRole)));
            }

        // dessin grouping
        painter->drawText(opt.rect, Qt::AlignCenter, index.data().toString());
        painter->restore();

        } break;

    case 10: // CASE CAPACITY
        {
        // setup du contexte de dessin
        QStyleOptionViewItemV4 opt(option);
        QStyledItemDelegate::initStyleOption(&opt, index);
        opt.text = "";
        const QWidget *widget = option.widget;
        QStyle *style = widget ? widget->style() : QApplication::style();

        // setup du peintre
        painter->save();
        painter->setRenderHint(QPainter::Antialiasing);
        painter->setClipRect(opt.rect, Qt::ReplaceClip);

        // prise en charge de l'état hightlighted
        if ( opt.state & QStyle::State_Selected )
            {
            painter->setPen(Qt::white);
            painter->setBrush( option.palette.highlightedText() );
            // prend en charge l'affichage du focus
            style->drawControl(QStyle::CE_ItemViewItem, &opt, painter, widget);
            }
        else
            {
            painter->setPen( QPen(option.palette.foreground(), 0) );
            painter->setBrush(qvariant_cast<QBrush>(index.data(Qt::ForegroundRole)));
            }

        // dessin capacity
        painter->drawText(opt.rect, Qt::AlignCenter, index.data().toString());
        painter->restore();

        } break;

    case 11: // CASE DISCIPLINES
        {
        // setup du contexte de dessin
        QStyleOptionViewItemV4 opt(option);
        QStyledItemDelegate::initStyleOption(&opt, index);
        opt.text = "";
        const QWidget *widget = option.widget;
        QStyle *style = widget ? widget->style() : QApplication::style();

        // setup du peintre
        painter->save();
        painter->setRenderHint(QPainter::Antialiasing);
        painter->setClipRect(opt.rect, Qt::ReplaceClip);

        // prise en charge de l'état hightlighted
        if ( opt.state & QStyle::State_Selected )
            {
            painter->setBrush( option.palette.highlightedText() );
            // prend en charge l'affichage du focus
            style->drawControl(QStyle::CE_ItemViewItem, &opt, painter, widget);
            }

        // dessins des disciplines
        QRect rect(opt.rect);
        QString NomIconeDiscipline;
        QString Disciplines = index.data().toString();
        QStringList ListeDisciplines = Disciplines.split(" ",QString::SkipEmptyParts);
        for (int i=0; i<ListeDisciplines.size(); i++)
            {
            if (ListeDisciplines.at(i) < ListeDisciplines.at(i).toLower())
                {
                QRect target( rect.x()+i*25+10, rect.center().y()-11, 22, 22 );
                NomIconeDiscipline = ListeDisciplines.at(i).toLower() + "-sup.png";
                QPixmap PixmapCourante(":/icons/disc/" + NomIconeDiscipline);
                painter->drawPixmap(target, PixmapCourante);
                }
            else
                {
                QRect target( rect.x()+i*25+10, rect.center().y()-11, 22, 22 );
                NomIconeDiscipline = ListeDisciplines.at(i) + ".png";
                QPixmap PixmapCourante(":/icons/disc/" + NomIconeDiscipline);
                painter->drawPixmap(target, PixmapCourante);
                }
            }

        painter->restore();
        } break;

    default: QStyledItemDelegate::paint(painter, option, index);
    }

}

QSize PDelegateCryptResult::sizeHint(const QStyleOptionViewItem & option, const QModelIndex & index ) const
{
    switch(index.column())
        {

        case 11:
                {
                QStringList ListeDisciplines = index.data().toString().split(" ", QString::SkipEmptyParts);
                return(QSize( ListeDisciplines.count()*25+20, 40) );
                } break;

        default: return QStyledItemDelegate::sizeHint(option, index);
        }
}

// DELEGATE BIBLIO
PDelegateCardResult::PDelegateCardResult(QObject *parent) : QStyledItemDelegate(parent)
{
PathImages = QCoreApplication::applicationDirPath() + "/Images/";
}


void PDelegateCardResult::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    switch(index.column())
        {

        case 7: // CASE CARD TYPE
            {
            // setup du contexte de dessin
            QStyleOptionViewItemV4 opt(option);
            QStyledItemDelegate::initStyleOption(&opt, index);
            opt.text = "";
            const QWidget *widget = option.widget;
            QStyle *style = widget ? widget->style() : QApplication::style();

            // setup du peintre
            painter->save();
            painter->setRenderHint(QPainter::Antialiasing);
            painter->setClipRect(opt.rect, Qt::ReplaceClip);

            // prise en charge de l'état hightlighted
            if ( opt.state & QStyle::State_Selected )
                {
                painter->setBrush( option.palette.highlightedText() );
                // prend en charge l'affichage du focus
                style->drawControl(QStyle::CE_ItemViewItem, &opt, painter, widget);
                }

            // dessin du type de cartes
            QString NomIconeTypeCarte;
            QRect rect(opt.rect);
            QString TypesCarte = index.data().toString();
            QStringList ListeTypesCarte = TypesCarte.split(" / ",QString::SkipEmptyParts);
            for (int i=0; i<ListeTypesCarte.size(); i++)
                {
                QRect target(rect.x()+i*25+10,rect.center().y()-11, 22.0, 22.0);
                NomIconeTypeCarte = ListeTypesCarte.at(i) + ".gif";
                QPixmap PixmapCourante(":/icons/type/" + NomIconeTypeCarte);
                painter->drawPixmap(target, PixmapCourante);
                }

            painter->restore();
            } break;

        case 9: // CASE CLAN
            {
            // setup du contexte de dessin
            QStyleOptionViewItemV4 opt(option);
            QStyledItemDelegate::initStyleOption(&opt, index);
            opt.text = "";
            const QWidget *widget = option.widget;
            QStyle *style = widget ? widget->style() : QApplication::style();

            // setup du peintre
            painter->save();
            painter->setRenderHint(QPainter::Antialiasing);
            painter->setClipRect(opt.rect, Qt::ReplaceClip);

            // prise en charge de l'état hightlighted
            if ( opt.state & QStyle::State_Selected )
                {
                painter->setBrush( option.palette.highlightedText() );
                // prend en charge l'affichage du focus
                style->drawControl(QStyle::CE_ItemViewItem, &opt, painter, widget);
                }

            // dessin du clan
            QString clan = index.data().toString() + ".gif";
            QPixmap clanPixmap(":/icons/clan/" + clan);
            QRect target(opt.rect.x()+15, opt.rect.center().y()-15, 30, 30);
            painter->drawPixmap(target, clanPixmap);

            painter->restore();
            }break;

        case 11: // CASE DISCIPLINES
            {
            // setup du contexte de dessin
            QStyleOptionViewItemV4 opt(option);
            QStyledItemDelegate::initStyleOption(&opt, index);
            opt.text = "";
            const QWidget *widget = option.widget;
            QStyle *style = widget ? widget->style() : QApplication::style();

            // setup du peintre
            painter->save();
            painter->setRenderHint(QPainter::Antialiasing);
            painter->setClipRect(opt.rect, Qt::ReplaceClip);

            // prise en charge de l'état hightlighted
            if ( opt.state & QStyle::State_Selected )
                {
                painter->setBrush( option.palette.highlightedText() );
                // prend en charge l'affichage du focus
                style->drawControl(QStyle::CE_ItemViewItem, &opt, painter, widget);
                }

            // dessin des disciplines
            QRect rect(opt.rect);
            QString NomIconeDiscipline;
            QString Disciplines = index.data().toString();
            QStringList ListeDisciplines = Disciplines.split(" ",QString::SkipEmptyParts);
            for (int i=0; i<ListeDisciplines.size(); i++)
                {
                int j = VtesInfo::DisciplinesList.indexOf( ListeDisciplines.at(i) );
                if ( j > 0 )
                    {
                    QRect target(rect.x()+i*25+10, rect.center().y()-11, 22.0, 22.0);
                    NomIconeDiscipline = VtesInfo::DisciplinesSigleList.at(j) + ".png";
                    QPixmap PixmapCourante(":/icons/disc/" + NomIconeDiscipline);
                    painter->drawPixmap(target, PixmapCourante);
                    }
                }

            painter->restore();
            } break;

        case 13: // CASE POOL COST
            {
            // setup du contexte de dessin
            QStyleOptionViewItemV4 opt(option);
            QStyledItemDelegate::initStyleOption(&opt, index);
            opt.text = "";
            const QWidget *widget = option.widget;
            QStyle *style = widget ? widget->style() : QApplication::style();

            // setup du peintre
            painter->save();
            painter->setRenderHint(QPainter::Antialiasing);
            painter->setClipRect(opt.rect, Qt::ReplaceClip);

            // prise en charge de l'état hightlighted
            if ( opt.state & QStyle::State_Selected )
                {
                painter->setPen(Qt::white);
                painter->setBrush( option.palette.highlightedText() );
                // prend en charge l'affichage du focus
                style->drawControl(QStyle::CE_ItemViewItem, &opt, painter, widget);
                }
            else
                {
                painter->setPen( QPen(option.palette.foreground(), 0) );
                painter->setBrush(qvariant_cast<QBrush>(index.data(Qt::ForegroundRole)));
                }

            // dessin pool cost
            painter->drawText(opt.rect, Qt::AlignCenter, index.data().toString());
            painter->restore();

            } break;

        case 14: // CASE BLOOD COST
            {
            // setup du contexte de dessin
            QStyleOptionViewItemV4 opt(option);
            QStyledItemDelegate::initStyleOption(&opt, index);
            opt.text = "";
            const QWidget *widget = option.widget;
            QStyle *style = widget ? widget->style() : QApplication::style();

            // setup du peintre
            painter->save();
            painter->setRenderHint(QPainter::Antialiasing);
            painter->setClipRect(opt.rect, Qt::ReplaceClip);

            // prise en charge de l'état hightlighted
            if ( opt.state & QStyle::State_Selected )
                {
                painter->setPen(Qt::white);
                painter->setBrush( option.palette.highlightedText() );
                // prend en charge l'affichage du focus
                style->drawControl(QStyle::CE_ItemViewItem, &opt, painter, widget);
                }
            else
                {
                painter->setPen( QPen(option.palette.foreground(), 0) );
                painter->setBrush(qvariant_cast<QBrush>(index.data(Qt::ForegroundRole)));
                }

            // dessin blood cost
            painter->drawText(opt.rect, Qt::AlignCenter, index.data().toString());
            painter->restore();

            } break;

        default: QStyledItemDelegate::paint(painter, option, index);
        }
}

QSize PDelegateCardResult::sizeHint(const QStyleOptionViewItem & option, const QModelIndex & index ) const
{
    switch(index.column())
        {

        case 7:
            {
            QStringList ListeTypesCarte = index.data().toString().split(" / ",QString::SkipEmptyParts);
            return( QSize(ListeTypesCarte.size()*25+20, 40) );
            } break;

        case 11:
            {
            QStringList ListeDisciplines = index.data().toString().split(" ",QString::SkipEmptyParts);
            return( QSize(ListeDisciplines.size()*25+20, 40) );
            } break;

        default: return QStyledItemDelegate::sizeHint(option, index);
        }
}

// DELEGATE DECK
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

//*******************************************************************************************************
//                                  LES ITEMS
//*******************************************************************************************************
