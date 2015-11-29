#ifndef GAMEFIELD_H
#define GAMEFIELD_H

#include <QGraphicsScene>
#include <QMainWindow>

#include "sideview.h"
#include "cellview.h"

class GameField
{
public:
    explicit GameField(size_t width, size_t height, GameManager *game_manager);

private:
    void drawPoints();
    void drawHorizontalSides();
    void drawVerticalSides();
    void drawCells();


public:
    QList<QList<SideView*> > horizontal_sides;
    QList<QList<SideView*> > vertical_sides;
    QList<QList<CellView*> > cells;

public:
    GameManager* game_manager_;

private:
    // Custom parameters for field.
    size_t points_amount_ = 6;
    size_t paddings_ = 10;
    size_t cell_paddings_ = 10;
    size_t circle_diameter_ = 10;
    size_t width_;
    size_t height_;
    size_t shift_x_;
    size_t shift_y_;
};

#endif // GAMEFIELD_H
