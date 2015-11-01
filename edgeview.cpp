#include "edgeview.h"
#include <iostream>

EdgeView::EdgeView(size_t width, size_t height) :
    width_(width), height_(height), state(ENABLED)
{
    setAcceptHoverEvents(true);
    setFlag(ItemIsSelectable);
}

QRectF EdgeView::boundingRect() const
{
    return QRectF(0, 0, width_, height_);
}

void EdgeView::paint(QPainter *painter,
                     const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rectf = boundingRect();
    QBrush brush(Qt::blue);
    switch(state) {
        case ENABLED:
            brush.setColor(Qt::blue);
            break;
        case PRESSED:
            brush.setColor(Qt::red);
            break;
        case HOVERED:
            brush.setColor(Qt::yellow);
            break;
        default:
            break;
    }
    painter->fillRect(rectf, brush);
    painter->drawRect(rectf);
}

void EdgeView::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
    state = PRESSED;
    update();
    QGraphicsItem::mousePressEvent(event);
}

void EdgeView::mouseReleaseEvent(QGraphicsSceneMouseEvent* event)
{
    state = HOVERED;
    update();
    QGraphicsItem::mouseReleaseEvent(event);
}

void EdgeView::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    state = HOVERED;
    update();
    QGraphicsItem::hoverEnterEvent(event);
}

void EdgeView::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    state = ENABLED;
    update();
    QGraphicsItem::hoverLeaveEvent(event);
}
