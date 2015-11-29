#include <QGraphicsScene>
#include <iostream>
#include "gamefield.h"
#include "sideview.h"

GameField::GameField(GameManager* game_manager, QObject* parent) :
    QGraphicsScene(parent)
{    
    game_manager_ = game_manager;
    drawHorizontalSides();
    drawVerticalSides();
    drawPoints();
    drawCells();
}


void GameField::drawHorizontalSides()
{
    size_t shift_x = paddings_ + circle_diameter_ / 2;
    size_t shift_y = paddings_;
    size_t dx = (width_ - 2 * paddings_ - circle_diameter_) / (points_amount_ - 1);
    size_t dy = (height_ - 2 * paddings_ - circle_diameter_) / (points_amount_ - 1);
    for (size_t i = 0; i < points_amount_; ++i)
    {
        horizontal_sides.push_back(QList<SideView*>());
        shift_x = paddings_ + circle_diameter_ / 2;
        for (size_t j = 0; j < points_amount_ - 1; ++j)
        {
            SideView* side = new SideView(dx, circle_diameter_, game_manager_);
            side->moveBy(shift_x, shift_y);
            addItem(side);
            horizontal_sides[i].push_back(side);
            shift_x += dx;
        }
        shift_y += dy;
    }
}

void GameField::drawVerticalSides()
{
    size_t shift_x = paddings_;
    size_t shift_y = paddings_ + circle_diameter_ / 2;
    size_t dx = (width_ - 2 * paddings_ - circle_diameter_) / (points_amount_ - 1);
    size_t dy = (height_ - 2 * paddings_ - circle_diameter_) / (points_amount_ - 1);
    for (size_t i = 0; i < points_amount_ - 1; ++i)
    {
        vertical_sides.push_back(QList<SideView*>());
        shift_x = paddings_;
        for (size_t j = 0; j < points_amount_; ++j)
        {
            SideView* side = new SideView(circle_diameter_, dy, game_manager_);
            side->moveBy(shift_x, shift_y);
            addItem(side);
            vertical_sides[i].push_back(side);
            shift_x += dx;
        }
        shift_y += dy;
    }
}

void GameField::drawPoints()
{
    QBrush brush(Qt::black);
    QPen pen(Qt::black);

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
    for (size_t i = 0; i < points_amount_; ++i)
    {
        shift_x = paddings_;
        for (size_t j = 0; j < points_amount_; ++j)
        {
            addEllipse(shift_x, shift_y, circle_diameter_, circle_diameter_, pen, brush);
            shift_x += dx;
        }
        shift_y += dy;
    }
}

void GameField::drawCells()
{
    size_t shift_x = paddings_ + circle_diameter_ / 2 + cell_paddings_;
    size_t shift_y = paddings_ + circle_diameter_ / 2 + cell_paddings_;
    size_t dx = (width_ - 2 * paddings_ - circle_diameter_) / (points_amount_ - 1);
    size_t dy = (height_ - 2 * paddings_ - circle_diameter_) / (points_amount_ - 1);
    for (size_t i = 0; i < points_amount_ - 1; ++i)
    {
        shift_x = paddings_ + circle_diameter_ / 2 + cell_paddings_;
        cells.push_back(QList<CellView*>());
        for (size_t j = 0; j < points_amount_ - 1; ++j)
        {
            CellView* cell = new CellView(dx - 2 * cell_paddings_, dy - 2 * cell_paddings_);
            cell->moveBy(shift_x, shift_y);
            addItem(cell);
            cells[i].push_back(cell);
            shift_x += dx;
        }
        shift_y += dy;
    }
}
