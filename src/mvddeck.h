#ifndef MVDDECK_H
#define MVDDECK_H

#include <QTreeView>
#include <QStyledItemDelegate>
#include <QStandardItemModel>


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
/* THE SPECIALISED ITEMS                                                                 */
/*****************************************************************************************/
class SortItem : public QStandardItem
{
public:
    explicit SortItem(QString txt);
    ~SortItem();
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
    PTreeModel(QObject *parent= 0);
    QMap<QString, QString> meta_list;

public slots:
    void AddCardItem(QStringList strL);

private:
    SortItem *itemLib;
    SortItem *itemCrypt;
    SortItem *itemSide;
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


#endif // MVDDECK_H
