#include "cellview.h"

CellView::CellView(size_t width, size_t height)
{
    width_ = width;
    height_ = height;
    state_ = EMPTY;
}

QRectF CellView::boundingRect() const
{
    return QRectF(0, 0, width_, height_);
}

void CellView::paint(QPainter *painter,
                     const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap picture;
    switch (state_)
    {
        case EMPTY:
            break;
        case PLAYER:
            picture.load(":/faces/blue.png");
            break;
        case COMPUTER:
            picture.load(":/faces/red.png");
            break;
        default:
            break;
    }
    painter->drawPixmap(0, 0, width_, height_, picture);
}

void CellView::setState(CellState state)
{
    if (state_ != state)
    {
        state_ = state;
        emit callCellRedraw();
    }
}

CellState CellView::getState()
{
    return state_;
}
