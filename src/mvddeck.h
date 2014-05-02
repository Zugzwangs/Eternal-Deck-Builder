#ifndef MVDDECK_H
#define MVDDECK_H

#include <QTreeView>
#include <QStyledItemDelegate>
#include <QStandardItemModel>
#include <QSortFilterProxyModel>


/*****************************************************************************************/
/* CARDS AND CATEGORIES ITEMS                                                            */
/*****************************************************************************************/
class SortItem : public QStandardItem
{
public:
    explicit SortItem(QString txt);
    ~SortItem();
    void Increment(int i=1);
    virtual int	type() const;
};

class CryptCardItem : public QObject, public QStandardItem
{
    Q_OBJECT

public:
    explicit CryptCardItem(QStringList strL);
    void Increment();
    void Decrement();
    ~CryptCardItem();
    virtual int	type() const;

signals:
    void request_deleting( QModelIndex );
};

class LibraryCardItem : public QObject, public QStandardItem
{
    Q_OBJECT

public:
    explicit LibraryCardItem(QStringList strL);
    void Increment();
    void Decrement();
    ~LibraryCardItem();
    virtual int	type() const;

signals:
    void request_deleting( QModelIndex );
};

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
    void RemoveCardITem( QModelIndex Idx );
    CryptCardItem* FindCryptCard( QString CardName );
    LibraryCardItem* FindLibraryCard( QString CardName );

signals:
    void CardAdded(QModelIndex parent, QModelIndex AddedItem);
    void CardRemoved();
};


/*****************************************************************************************/
/*  THE OVER VIEW MODEL                                                                  */
/*****************************************************************************************/
class StatsModel : public QStandardItemModel
{
    Q_OBJECT

public:
    explicit StatsModel(QObject *parent = 0);
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
