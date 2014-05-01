#ifndef MVDDECK_H
#define MVDDECK_H

#include <QTreeView>
#include <QStyledItemDelegate>
#include <QStandardItemModel>
#include <QSortFilterProxyModel>


/*****************************************************************************************/
/* THE DELEGATE VIEW                                                                     */
/*****************************************************************************************/
class PDelegateDeck : public QStyledItemDelegate
{
    Q_OBJECT

public:
    PDelegateDeck(QObject* parent=0);
    void paint(QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index ) const;
    virtual QSize sizeHint(const QStyleOptionViewItem & option, const QModelIndex & index ) const;
};


/*****************************************************************************************/
/* CARDS AND CATEGORIES ITEMS                                                            */
/*****************************************************************************************/
class SortItem : public QStandardItem
{
public:
    explicit SortItem(QString txt);
    ~SortItem();
    void Increment();
    virtual int	type() const;
};

class CardItem : public QStandardItem
{
public:
    explicit CardItem(QStringList strL);
    void Increment();
    ~CardItem();
    virtual int	type() const;
};


/*****************************************************************************************/
/*  THE MODEL                                                                            */
/*****************************************************************************************/
class PTreeModel : public QStandardItemModel
{
    Q_OBJECT

public:
    PTreeModel(QObject *parent = 0);
    QMap<QString, QString> meta_list;
    SortItem *itemLib;
    SortItem *itemCrypt;
    SortItem *itemSide;

public slots:
    void AddCardItem(QStringList strL);

signals:
    void CardAdded(QModelIndex parent, QModelIndex AddedItem);
};

/*****************************************************************************************/
/*  THE OVER VIEW MODEL                                                                  */
/*****************************************************************************************/
class StatsModel : public QStandardItemModel
{
    Q_OBJECT
public:
    explicit StatsModel(QObject *parent = 0);
    //StatsModel(int r, int c, QObject *parent = 0); // no need
};

/*****************************************************************************************/
/*  METADATAS TO WIDGET MAPPER                                                           */
/*****************************************************************************************/
class WidgetMetaMapper : public QObject
{
    Q_OBJECT

public:
    WidgetMetaMapper( QObject *parent=0 );
    void SetModel( PTreeModel* model );
    bool AddWidget( QWidget* w, QString metadata );
    bool RemoveWidget();

private:
    PTreeModel* model;
    //QList<Widget *> WidgetList; ?

private slots:
    void synchroDatas(QString newData);
};


/*****************************************************************************************/
/*  THE DECK VIEW                                                                        */
/*****************************************************************************************/
class PTreeView : public QTreeView
{
    Q_OBJECT

public:
    PTreeView(QWidget *parent=0);
    void setModel(QAbstractItemModel *model);
    PTreeModel* deckModel;

public slots:
    void fakeDrop(QStringList StrL);
};

/*****************************************************************************************/
/*  THE DECK VIEW                                                                        */
/*****************************************************************************************/
class CryptProxy : public QSortFilterProxyModel
{
    Q_OBJECT

public:
    CryptProxy( QObject *parent=0 );
};

class LibraryProxy : public QSortFilterProxyModel
{
    Q_OBJECT

public:
    LibraryProxy( QObject *parent=0 );
};


#endif // MVDDECK_H
