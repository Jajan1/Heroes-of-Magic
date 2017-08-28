#ifndef MYOBJECT_H
#define MYOBJECT_H

#include <QGraphicsItem>


class MyObject : public QGraphicsPixmapItem
{
public:
    MyObject(const QColor &color, int x, int y);

    QRectF boundingRect() const Q_DECL_OVERRIDE;
    QPainterPath shape() const Q_DECL_OVERRIDE;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget) Q_DECL_OVERRIDE;

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) Q_DECL_OVERRIDE;

private:
    int x;
    int y;
    QColor color;
    QVector<QPointF> stuff;

};

class MyMovingObject : public MyObject
{
public:
    MyMovingObject(const QColor &color, int x, int y);
};

#endif // MYOBJECT_H
