#ifndef MVDDECK_H
#define MVDDECK_H

#include <QTreeView>
#include <QStyledItemDelegate>
#include <QStandardItemModel>

//
class PTreeView : public QTreeView
{
    Q_OBJECT

public:
    PTreeView(QWidget *parent=0);
    void setModel(QAbstractItemModel *model);

public slots:
    void fakeDrop(QStringList StrL);
};

//
class PDelegateDeck : public QStyledItemDelegate
{
    Q_OBJECT

public:
    PDelegateDeck(QObject* parent=0);
    void paint(QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index ) const;
    virtual QSize sizeHint(const QStyleOptionViewItem & option, const QModelIndex & index ) const;

};

//
class MetaItem : public QStandardItem
{
public:
    explicit MetaItem(QString txt);
    ~MetaItem();
    virtual int	type() const;
};

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
    explicit CardItem();
    ~CardItem();
    virtual int	type() const;
};

//
class PTreeModel : public QStandardItemModel
{
    Q_OBJECT

public:
    PTreeModel(QObject *parent= 0);
    SortItem *itemMeta; //*itemCrypt  *ItemLibrary ?
};

#endif // MVDDECK_H
