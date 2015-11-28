#ifndef CELLVIEW_H
#define CELLVIEW_H

#include <QGraphicsItem>
#include "sideview.h"

enum CellState { EMPTY, FIRST_PLAYER, SECOND_PLAYER };

class CellView : public QGraphicsItem
{
public:
    CellView(size_t width, size_t height);

    QRectF boundingRect() const;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void setState(CellState state);

    CellState getState();

private:
    CellState state_;

    size_t height_;
    size_t width_;
};

#endif // CELLVIEW_H
