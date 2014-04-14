#include "pitemview.h"
#include "mainwindow.h"
#include "Global.h"
#include <QDrag>


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
setGeometry(1015,0,255,600);
setAcceptDrops(true);
setDragDropMode(DropOnly);
setDropIndicatorShown(true);
setDragDropOverwriteMode(false);
setHeaderHidden(false);
setAnimated(true);
setIndentation(10);
}

void PTreeView::dragEnterEvent(QDragEnterEvent *event)
{
if (event->mimeData()->hasFormat("text/plain"))
    {
    event->setDropAction(Qt::CopyAction);
    event->accept();
    }
}

void PTreeView::dragMoveEvent(QDragMoveEvent *event)
{
if (event->mimeData()->hasFormat("text/plain"))
    {
    event->setDropAction(Qt::CopyAction);
    event->accept();
    }
}

void PTreeView::dropEvent(QDropEvent *event)
{
QString TempData;
QString NomCarte;
QStringList ListofData;

/* On vérifie la source du drop */
if (event->source()->objectName() == "PTVCardsResults")
    {
    //On recup les données du drop | on les split | on chope le nom de la carte
    TempData = event->mimeData()->text();
    ListofData = TempData.split("\n",QString::KeepEmptyParts);
    NomCarte = ListofData[1].trimmed();

    //On vérifie si la carte n'est pas déja dans la list du deck et on la rajoute
    PTreeModel *modelcourant=dynamic_cast<PTreeModel*>(this->model());
    QList<QStandardItem *> ItemBibliotheque = modelcourant->findItems("BIBLIOTHEQUE");

    QStandardItem* TempItem;
    bool FlagCartePresente = false;
    for (int i=0; i<ItemBibliotheque[0]->rowCount(); i++)
        {
        TempItem = ItemBibliotheque[0]->child(i);
        if ( NomCarte == TempItem->text())
            {
            FlagCartePresente = true;
            TempItem->setData(TempItem->data(Qt::UserRole+2).toInt()+1,Qt::UserRole+2);
            }
        }

    if (!FlagCartePresente)
        {
        QStandardItem* NouvelItem = new QStandardItem(NomCarte);
        NouvelItem->setData(ListofData,Qt::UserRole);
        NouvelItem->setData("LibraryCard",Qt::UserRole+1);
        NouvelItem->setData(1,Qt::UserRole+2);
        NouvelItem->setEditable(false);
        ItemBibliotheque[0]->appendRow(NouvelItem);
        }
    }
else
    {
    if (event->source()->objectName() == "PTVCryptResults")
        {
        //On recup les données du drop | on les split | on chope le nom de la carte
        TempData = event->mimeData()->text();
        ListofData = TempData.split("\n",QString::KeepEmptyParts);
        NomCarte = ListofData[1].trimmed();

        //On vérifie si la carte n'est pas déja dans la list du deck et on la rajoute
        PTreeModel *modelcourant=dynamic_cast<PTreeModel*>(this->model());
        QList<QStandardItem *> ItemCrypte = modelcourant->findItems("CRYPTE");

        QStandardItem* TempItem;
        bool FlagCartePresente = false;
        for (int i=0; i<ItemCrypte[0]->rowCount(); i++)
            {
            TempItem = ItemCrypte[0]->child(i);
            if ( NomCarte == TempItem->text())
                {
                FlagCartePresente = true;
                TempItem->setData(TempItem->data(Qt::UserRole+2).toInt()+1,Qt::UserRole+2);
                }
            }

        if (!FlagCartePresente)
            {
            QStandardItem* NouvelItem = new QStandardItem(NomCarte);
            NouvelItem->setData(ListofData,Qt::UserRole);
            NouvelItem->setData("CryptCard",Qt::UserRole+1);
            NouvelItem->setData(1,Qt::UserRole+2);
            NouvelItem->setEditable(false);
            ItemCrypte[0]->appendRow(NouvelItem);
            }
        }
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
this->setColumnCount(2);

itemMeta = new QStandardItem("METADONNEES");
itemMeta->setEditable(false);
RootItem->appendRow(itemMeta);

QList<QStandardItem *> ListItemMeta;
ListItemMeta.append(new QStandardItem("Nom"));
ListItemMeta.append(new QStandardItem("Auteur"));
ListItemMeta.append(new QStandardItem("Commentaires"));
for (int i=0; i<ListItemMeta.length(); i++)
    {
    ListItemMeta.at(i)->setEditable(false);
    ListItemMeta.at(i)->setData( ListItemMeta.at(i)->data(Qt::DisplayRole) , Qt::ToolTipRole );
    //UserRole+3 sert à savoir le role de l'item => remplace le Type pour pas avoir a sousclasser
    //ListItemMeta.at(i)->setData(1,Qt::UserRole+3);
    }
itemMeta->appendColumn(ListItemMeta);

QList<QStandardItem *> chmurt2;
chmurt2.append(new QStandardItem());
chmurt2.append(new QStandardItem());
chmurt2.append(new QStandardItem());
for (int i=0; i<chmurt2.length(); i++)
    {
    chmurt2.at(i)->setData("bita mange boules de merde ta race",Qt::DisplayRole);
    chmurt2.at(i)->setData("deckMetaDonnees",Qt::UserRole);
    }
itemMeta->appendColumn(chmurt2);

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
    case 8:
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

    case 9:
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

    case 10:
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

    case 11:
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
                QRect target(rect.x()+i*25+10, rect.center().y()-11, 22, 22);
                NomIconeDiscipline = ListeDisciplines.at(i).toLower() + "-sup.png";
                QPixmap PixmapCourante(":/icons/disc/" + NomIconeDiscipline);
                painter->drawPixmap(target, PixmapCourante);
                }
            else
                {
                QRect target(rect.x()+i*25+10, rect.center().y()-11, 22, 22);
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
        case 8:  { return(QSize(60,30));  } break;
        case 9:  { return(QSize(50,30));  } break;
        case 10: { return(QSize(50,30));  } break;
        case 11: { return(QSize(150,30)); } break;
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
        case 7:
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

        case 9:
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

        case 11:
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

        case 13:
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

        case 14:
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
        case 7:  { return(QSize(70,30));  } break;
        case 11: { return(QSize(100,30)); } break;
        default: return QStyledItemDelegate::sizeHint(option, index);
        }
}

// DELEGATE DECK
PDelegateDeck::PDelegateDeck(QObject *parent) : QStyledItemDelegate(parent)
{

}

void PDelegateDeck::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{

    //  dessin custom dabs le cas d'une carte crypt/biblio
    if ( index.isValid() && ( index.data(Qt::UserRole+1).toString() == "CryptCard" ||  index.data(Qt::UserRole+1).toString() == "LibraryCard" ) )
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

        // dessin du bouton delete
        QStyleOptionButton* bt_delete = new QStyleOptionButton();
        bt_delete->rect = btDeleteRegion;
        bt_delete->icon = QIcon(":/icons/delete.png");
        bt_delete->iconSize = btDeleteRegion.size();
        style->drawControl( QStyle::CE_PushButton, bt_delete, painter);

        // dessin du nombre d'exemplaires
        style->drawItemText(painter, ExRegion, 1, opt.palette, true, "x" + index.data(Qt::UserRole+2).toString() );

        painter->restore();
        }
    else
        {
        QStyledItemDelegate::paint(painter, option, index);
        }
    //QStyledItemDelegate::paint(painter, option, index);
}

QSize PDelegateDeck::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    return QStyledItemDelegate::sizeHint(option, index);
}

//*******************************************************************************************************
//                                  LES ITEMS
//*******************************************************************************************************
