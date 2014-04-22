#ifndef MVDBDD_H
#define MVDBDD_H

#include <QSqlTableModel>
#include <QTableView>
#include <QStyledItemDelegate>

class PSqlTableModel : public QSqlTableModel
{
    Q_OBJECT

public:
    PSqlTableModel(QObject *parent=0);

protected:

private:

};

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


#endif // MVDBDD_H
