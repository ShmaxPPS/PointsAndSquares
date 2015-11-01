#include "gamefield.h"
#include <QGraphicsScene>
#include "edgeview.h"

GameField::GameField(QObject* parent) :
    QGraphicsScene(parent)
{
    drawHorizontalEdges();
    drawVerticalEdges();
    drawPoints();
}


void GameField::drawHorizontalEdges()
{
    size_t shift_x = paddings_ + circle_diameter_ / 2, shift_y = paddings_;
    size_t dx = (width_ - 2 * paddings_ - circle_diameter_) / (points_amount_ - 1);
    size_t dy = (height_ - 2 * paddings_ - circle_diameter_) / (points_amount_ - 1);
    for (size_t i = 0; i < points_amount_; ++i) {
        shift_x = paddings_ + circle_diameter_ / 2;
        for (size_t j = 0; j < points_amount_ - 1; ++j) {
            EdgeView* edge = new EdgeView(dx, circle_diameter_);
            edge->moveBy(shift_x, shift_y);
            this->addItem(edge);
            edges_.push_back(edge);
            shift_x += dx;
        }
        shift_y += dy;
    }
}

void GameField::drawVerticalEdges()
{
    size_t shift_x = paddings_, shift_y = paddings_ + circle_diameter_ / 2;
    size_t dx = (width_ - 2 * paddings_ - circle_diameter_) / (points_amount_ - 1);
    size_t dy = (height_ - 2 * paddings_ - circle_diameter_) / (points_amount_ - 1);
    for (size_t i = 0; i < points_amount_ - 1; ++i) {
        shift_x = paddings_;
        for (size_t j = 0; j < points_amount_; ++j) {
            EdgeView* edge = new EdgeView(circle_diameter_, dy);
            edge->moveBy(shift_x, shift_y);
            this->addItem(edge);
            edges_.push_back(edge);
            shift_x += dx;
        }
        shift_y += dy;
    }
}

void GameField::drawPoints()
{
    QBrush brush(Qt::white);
    QPen pen(Qt::white);

    QLine line = QLine(QPoint(0, 0), QPoint(width_, 0)); // Draw top line
    this->addLine(line, pen);
    line = QLine(QPoint(0, 0), QPoint(0, height_)); // Draw left line
    this->addLine(line, pen);
    line = QLine(QPoint(width_, 0), QPoint(width_, height_)); // Draw bottom line
    this->addLine(line, pen);
    line = QLine(QPoint(0, height_), QPoint(width_, height_)); // Draw right line
    this->addLine(line, pen);

    size_t shift_x = paddings_, shift_y = paddings_;
    size_t dx = (width_ - 2 * paddings_ - circle_diameter_) / (points_amount_ - 1);
    size_t dy = (height_ - 2 * paddings_ - circle_diameter_) / (points_amount_ - 1);
    for (size_t i = 0; i < points_amount_; ++i) {
        shift_x = paddings_;
        for (size_t j = 0; j < points_amount_; ++j) {
            this->addEllipse(shift_x, shift_y, circle_diameter_, circle_diameter_, pen, brush);
            shift_x += dx;
        }
        shift_y += dy;
    }
}
