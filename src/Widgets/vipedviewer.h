#ifndef VIPEDVIEWER_H
#define VIPEDVIEWER_H

#include <QFrame>
#include <QMouseEvent>

class VipedViewer : public QFrame
{
    Q_OBJECT

public:
    explicit VipedViewer(QWidget *parent = 0 );
    virtual QSize sizeHint() const;
    void setModel(QMap<QString, int> &model);
    bool setData(QString key, int value);
    void clearData();
    void checkModelConformity();
    void setTitle(QString title);
    void setTickNumber(int Nb = 5);
    void setMargin(int x, int y);

protected:
    virtual void paintEvent(QPaintEvent * event);
    virtual void resizeEvent(QResizeEvent * event);
    virtual void mousePressEvent(QMouseEvent * event);
    //virtual void mouseMoveEvent(QMouseEvent * event);
    virtual void mouseReleaseEvent(QMouseEvent * event);

private:
    int myNbTicks;
    qreal myTickSize;
    int myMin;
    int myMax;
    qreal myMinBound;
    qreal myMaxBound;
    qreal myCenterHoleDiam;
    QPoint mycenterChart;
    qreal mySectionAngle;
    int myMarginX;
    int myMarginY;
    int myNbSection;
    QString myTitle;
    QRect myTitleRect;
    QRect myChartRect;
    QRect myValuesRect;
    QMap<QString, int> myModel;
    QString mySelectedSection;

    qreal valueToPx( int value) const;
    int PxToValue(qreal px) const;
    int PointToValue(QPoint p) const;
    int PointToSection(QPoint p) const;
    void updateChart();
    void updateRects();
    void updateValues();
    void paintChart( QPainter& );
    void paintAxis( QPainter& painter ) const;
    void paintTicks( QPainter& painter ) const;
    void paintValue( QPainter& painter, int i, QVariant v ) const;
    void paintTextAxis(QPainter& painter, int i, QVariant v) const;
    void paintTitle(QPainter &painter) const;

signals:
    void dataChanged(QString key, int value);
};

#endif // VIPEDVIEWER_H
