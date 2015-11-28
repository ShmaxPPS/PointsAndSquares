#ifndef SIDEVIEW_H
#define SIDEVIEW_H

#include <QGraphicsItem>
#include <QPainter>


enum SideState { PRESSED, HOVERED, ENABLED, DISABLED };

class SideView : public QGraphicsItem
{
public:
    SideView(size_t width, size_t height);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent* event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent* event);
    void hoverEnterEvent(QGraphicsSceneHoverEvent* event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent* event);

public:
    SideState state;

private:
    size_t width_;
    size_t height_;
    QBrush brush_;
};


#endif // SIDEVIEW_H
