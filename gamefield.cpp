#include <QGraphicsScene>
#include <iostream>
#include "gamefield.h"
#include "sideview.h"
#include "game.h"

extern Game* game;

GameField::GameField(size_t width, size_t height, GameManager* game_manager)
{    
    width_ = width;
    height_ = height;
    shift_x_ = game->width() / 2 - width_ / 2;
    shift_y_ = game->height() / 2 - height_ / 2;
    game_manager_ = game_manager;
    drawHorizontalSides();
    drawVerticalSides();
    drawPoints();
    drawCells();
}


void GameField::drawHorizontalSides()
{
    size_t shift_x = shift_x_ + paddings_ + circle_diameter_ / 2;
    size_t shift_y = shift_y_ + paddings_;
    size_t dx = (width_ - 2 * paddings_ - circle_diameter_) / (points_amount_ - 1);
    size_t dy = (height_ - 2 * paddings_ - circle_diameter_) / (points_amount_ - 1);
    for (size_t i = 0; i < points_amount_; ++i)
    {
        horizontal_sides.push_back(QList<SideView*>());
        shift_x = shift_x_ + paddings_ + circle_diameter_ / 2;
        for (size_t j = 0; j < points_amount_ - 1; ++j)
        {
            SideView* side = new SideView(dx, circle_diameter_, game_manager_);
            side->moveBy(shift_x, shift_y);
            game->scene->addItem(side);
            horizontal_sides[i].push_back(side);
            shift_x += dx;
        }
        shift_y += dy;
    }
}

void GameField::drawVerticalSides()
{
    size_t shift_x =  + shift_x_ + paddings_;
    size_t shift_y = shift_y_ + paddings_ + circle_diameter_ / 2;
    size_t dx = (width_ - 2 * paddings_ - circle_diameter_) / (points_amount_ - 1);
    size_t dy = (height_ - 2 * paddings_ - circle_diameter_) / (points_amount_ - 1);
    for (size_t i = 0; i < points_amount_ - 1; ++i)
    {
        vertical_sides.push_back(QList<SideView*>());
        shift_x = shift_x_ + paddings_;
        for (size_t j = 0; j < points_amount_; ++j)
        {
            SideView* side = new SideView(circle_diameter_, dy, game_manager_);
            side->moveBy(shift_x, shift_y);
            game->scene->addItem(side);
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

    QLine line = QLine(QPoint(shift_x_, shift_y_), QPoint(shift_x_ + width_, shift_y_)); // Draw top line
    game->scene->addLine(line, pen);
    line = QLine(QPoint(shift_x_, shift_y_), QPoint(shift_x_, shift_y_ + height_)); // Draw left line
    game->scene->addLine(line, pen);
    line = QLine(QPoint(shift_x_+ width_, shift_y_), QPoint(shift_x_ + width_, shift_y_ + height_)); // Draw bottom line
    game->scene->addLine(line, pen);
    line = QLine(QPoint(shift_x_, shift_y_+ height_), QPoint(shift_x_+ width_, shift_y_ + height_)); // Draw right line
    game->scene->addLine(line, pen);

    size_t shift_x = shift_x_ + paddings_;
    size_t shift_y = shift_y_ + paddings_;
    size_t dx = (width_ - 2 * paddings_ - circle_diameter_) / (points_amount_ - 1);
    size_t dy = (height_ - 2 * paddings_ - circle_diameter_) / (points_amount_ - 1);
    for (size_t i = 0; i < points_amount_; ++i)
    {
        shift_x = shift_x_ + paddings_;
        for (size_t j = 0; j < points_amount_; ++j)
        {
            game->scene->addEllipse(shift_x, shift_y, circle_diameter_, circle_diameter_, pen, brush);
            shift_x += dx;
        }
        shift_y += dy;
    }
}

void GameField::drawCells()
{
    size_t shift_x = shift_x_ + paddings_ + circle_diameter_ / 2 + cell_paddings_;
    size_t shift_y = shift_y_ + paddings_ + circle_diameter_ / 2 + cell_paddings_;
    size_t dx = (width_ - 2 * paddings_ - circle_diameter_) / (points_amount_ - 1);
    size_t dy = (height_ - 2 * paddings_ - circle_diameter_) / (points_amount_ - 1);
    for (size_t i = 0; i < points_amount_ - 1; ++i)
    {
        shift_x = shift_x_ + paddings_ + circle_diameter_ / 2 + cell_paddings_;
        cells.push_back(QList<CellView*>());
        for (size_t j = 0; j < points_amount_ - 1; ++j)
        {
            CellView* cell = new CellView(dx - 2 * cell_paddings_, dy - 2 * cell_paddings_);
            cell->moveBy(shift_x, shift_y);
            game->scene->addItem(cell);
            cells[i].push_back(cell);
            shift_x += dx;
        }
        shift_y += dy;
    }
}
