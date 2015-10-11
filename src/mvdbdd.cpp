#include "mvdbdd.h"
#include "Global.h"

#include <QApplication>
#include <QMouseEvent>
#include <QHeaderView>
#include <QDir>
#include <QMap>
#include <QMimeData>
#include <QDrag>
#include <QPainter>
#include <QDebug>

//*******************************************************************************************************
//
//*******************************************************************************************************
PSqlTableModel::PSqlTableModel(QObject *parent) : QSqlTableModel(parent)
{
}

QVariant PSqlTableModel::data(const QModelIndex &idx, int role) const
{
QString sectionName = headerData(idx.column() ,Qt::Horizontal, Qt::DisplayRole).toString();

if ( role==Qt::ToolTipRole && ( sectionName == "Clan" || sectionName == "Discipline" || sectionName == "Type" ) )
        {
        return idx.data(Qt::DisplayRole);
        }
    return QSqlTableModel::data(idx, role);
}
//*******************************************************************************************************
//
//*******************************************************************************************************
PItemView::PItemView(QWidget *parent) : QTableView(parent)
{
setSelectionMode(SingleSelection);
setSelectionBehavior(SelectRows);
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
        {
        startPos = event->pos();
        }
    QTableView::mousePressEvent(event);
}

void PItemView::mouseMoveEvent(QMouseEvent *event)
{
    if(event->buttons() & Qt::LeftButton)
    {
        int distance = (event->pos() - startPos).manhattanLength();
        if (distance >= QApplication::startDragDistance() && indexAt(startPos).isValid() )
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
QStringList embeddedDatas;
QMimeData *DraggedData = new QMimeData;
QDrag *Drag = new QDrag(this);

DossierAppli.setPath(QCoreApplication::applicationDirPath());
if (DossierAppli.cd("Cartes"))
    { PathDragIcone = DossierAppli.absolutePath(); }
PathDragIcone = PathDragIcone + "/" + "Vtes_Grelarge.gif";

// We record card's datas into a QDrag object
CurrentIndex = CurrentSelection.first();
for (int i=0; i< model()->columnCount(); i++)
    {
    QString dataValue = model()->index(CurrentIndex.row(),i).data(Qt::DisplayRole).toString().trimmed();
    embeddedDatas.append( dataValue );
    }

DraggedData->setText(embeddedDatas.join("\n"));

if (IconeDrag.load(PathDragIcone))
    {
    Drag->setPixmap(QPixmap::fromImage(IconeDrag));
    }

Drag->setMimeData(DraggedData);
Drag->exec(Qt::CopyAction);
}

void PItemView::dragLeaveEvent(QDragLeaveEvent *event)
{
    /*MMh pas tres utile ; à jeter peut etre*/
}

//*******************************************************************************************************
//
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
        const QWidget *widget = option.widget;
        QStyle *style = widget ? widget->style() : QApplication::style();
        opt.text = "";

        // setup du peintre
        painter->save();
        painter->setRenderHint(QPainter::Antialiasing);
        painter->setRenderHint(QPainter::SmoothPixmapTransform, true);
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
        painter->setRenderHint(QPainter::SmoothPixmapTransform, true);
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
                QRectF target( rect.x()+i*26+10, rect.center().y()-12, 24, 24 );
                NomIconeDiscipline = ListeDisciplines.at(i).toLower() + "-sup.png";
                QPixmap PixmapCourante(":/icons/disc/" + NomIconeDiscipline);
                QRectF source = PixmapCourante.rect();
                painter->drawPixmap(target, PixmapCourante, source);
                }
            else
                {
                QRectF target( rect.x()+i*26+10, rect.center().y()-12, 24, 24 );
                NomIconeDiscipline = ListeDisciplines.at(i) + ".png";
                QPixmap PixmapCourante(":/icons/disc/" + NomIconeDiscipline);
                QRectF source = PixmapCourante.rect();
                painter->drawPixmap(target, PixmapCourante, source);
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
            painter->setRenderHint(QPainter::SmoothPixmapTransform, true);
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
            QStringList ListeTypesCarte = TypesCarte.split("/",QString::SkipEmptyParts);
            for (int i=0; i<ListeTypesCarte.size(); i++)
                {
                QRect target(rect.x()+i*26+10,rect.center().y()-12, 24, 24);
                NomIconeTypeCarte = ListeTypesCarte.at(i).trimmed() + ".gif";
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
            painter->setRenderHint(QPainter::SmoothPixmapTransform, true);
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
            painter->setRenderHint(QPainter::SmoothPixmapTransform, true);
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
                int j = VtesInfo::DisciplinesSigleList.indexOf( ListeDisciplines.at(i) );
                if ( j > 0 )
                    {
                    QRect target(rect.x()+i*26+10, rect.center().y()-12, 24, 24);
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
                // prend en charge l'affichage en mode focus
                painter->setPen(Qt::white);
                painter->setBrush( option.palette.highlightedText() );
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
                // prend en charge l'affichage en mode focus
                painter->setPen(Qt::white);
                painter->setBrush( option.palette.highlightedText() );
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


