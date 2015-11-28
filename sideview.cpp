#include "sideview.h"
#include <iostream>
#include "gamemanager.h"

SideView::SideView(size_t width, size_t height) :
    width_(width), height_(height), state(ENABLED)
{
    setAcceptHoverEvents(true);
    setFlag(ItemIsSelectable);
    brush_ = QBrush(Qt::green);
}

QRectF SideView::boundingRect() const
{
    return QRectF(0, 0, width_, height_);
}

void SideView::paint(QPainter *painter,
                     const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    QRectF rectf = boundingRect();
    switch (state)
    {
        case ENABLED:
            brush_.setColor(Qt::green);
            break;
        case PRESSED:
            if (GameManager::isFirstPlayerTurn())
            {
                brush_.setColor(Qt::blue);
            }
            else
            {
                brush_.setColor(Qt::red);
            }
            break;
        case HOVERED:
            brush_.setColor(Qt::yellow);
            break;
        default:
            break;
    }
    painter->fillRect(rectf, brush_);
    painter->drawRect(rectf);
}

void SideView::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
    if (state != DISABLED)
    {
        state = PRESSED;
        QGraphicsItem::mousePressEvent(event);
    }
}

void SideView::mouseReleaseEvent(QGraphicsSceneMouseEvent* event)
{
    state = DISABLED;
    GameManager::doTurn();
}

void SideView::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    if (state != DISABLED)
    {
        state = HOVERED;
        QGraphicsItem::hoverEnterEvent(event);
    }
}

void SideView::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    if (state != DISABLED)
    {
        state = ENABLED;
        QGraphicsItem::hoverLeaveEvent(event);
    }
}
