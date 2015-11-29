#include "button.h"

#include <QBrush>

Button::Button(size_t width, size_t height, QString name, QGraphicsItem *parent) :
    QGraphicsRectItem(parent)
{
    setRect(0, 0, width, height);
    QBrush brush(Qt::darkCyan);
    setBrush(brush);

    text = new QGraphicsTextItem(name, this);
    size_t xPos = rect().width() / 2 - text->boundingRect().width() / 2;
    size_t yPos = rect().height() / 2 - text->boundingRect().height() / 2;
    text->setPos(xPos, yPos);

    setAcceptHoverEvents(true);

}

void Button::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    emit clicked();
}

void Button::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    QBrush brush(Qt::cyan);
    setBrush(brush);
}

void Button::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    QBrush brush(Qt::darkCyan);
    setBrush(brush);
}


