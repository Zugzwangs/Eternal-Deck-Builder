#ifndef PITEMVIEW_H
#define PITEMVIEW_H

#include <QDebug>
#include <QMouseEvent>
#include <QMessageBox>
#include <QApplication>
#include <QWidget>
#include <QTableView>
#include <QTreeView>
#include <QSqlTableModel>
#include <QStandardItemModel>
#include <QStyledItemDelegate>
#include <QPainter>

/***************** QTableView subclass : implémente un Drag perso *****************/
class PItemView : public QTableView
{
    Q_OBJECT

public:
    PItemView(QWidget *parent = 0);

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void dragLeaveEvent(QDragLeaveEvent *event);

private:
    void startDrag();
    QPoint startPos;
};


/***************** QTreeView subclass : implémente un drop et utilise un délegate perso *****************/
class PTreeView : public QTreeView
{
    Q_OBJECT

public:
    PTreeView(QWidget *parent=0);

public slots:
    void fakeDrop(QStringList StrL);

};


class PStatsView : public QAbstractItemView
{
    Q_OBJECT

public:
    PStatsView(QWidget *parent=0);

protected:

private:

};


/***************** MODELE CONTENANT LA BDD *****************/
class PSqlTableModel : public QSqlTableModel
{
    Q_OBJECT

public:
    PSqlTableModel(QObject *parent=0);

protected:

private:

};

/***************** MODELE CONTENANT LE DECK *****************/
class PTreeModel : public QStandardItemModel
{
    Q_OBJECT

public:
    PTreeModel();
    QStandardItem *itemMeta;

protected:

private:

};


/***************** DELEGATE POUR LES RESULTATS CRYPT *****************/
class PDelegateCryptResult : public QStyledItemDelegate
{
    Q_OBJECT

public:
    PDelegateCryptResult(QObject* parent=0);
    void paint(QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index ) const;
    virtual QSize sizeHint(const QStyleOptionViewItem & option, const QModelIndex & index ) const;

private:
    QString PathImages;
};

/***************** DELEGATE POUR LES RESULTATS CARTE *****************/
class PDelegateCardResult : public QStyledItemDelegate
{
    Q_OBJECT

public:
    PDelegateCardResult(QObject* parent=0);
    void paint(QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index ) const;
    virtual QSize sizeHint(const QStyleOptionViewItem & option, const QModelIndex & index ) const;

private:
    QString PathImages;
};

/*****************        DELEGATE POUR LE DECK      *****************/
class PDelegateDeck : public QStyledItemDelegate
{
    Q_OBJECT

public:
    PDelegateDeck(QObject* parent=0);
    void paint(QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index ) const;
    virtual QSize sizeHint(const QStyleOptionViewItem & option, const QModelIndex & index ) const;

};

#endif // PITEMVIEW_H
