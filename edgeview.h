#ifndef EDGEVIEW_H
#define EDGEVIEW_H

#include <QGraphicsItem>
#include <QPainter>


enum State { PRESSED, HOVERED, ENABLED, DISABLED };

class EdgeView : public QGraphicsItem
{
public:
    EdgeView(size_t width, size_t height);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent* event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent* event);
    void hoverEnterEvent(QGraphicsSceneHoverEvent* event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent* event);

public:
    State state;

private:
    size_t width_;
    size_t height_;
};



#endif // EDGEVIEW_H
