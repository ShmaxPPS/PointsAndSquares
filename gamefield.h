#ifndef GAMEFIELD_H
#define GAMEFIELD_H

#include <QGraphicsScene>
#include <QMainWindow>

#include "sideview.h"
#include "cellview.h"

class GameField : public QGraphicsScene
{
    Q_OBJECT


public:
    explicit GameField(QObject* parent = 0);

private:
    void drawPoints();
    void drawHorizontalSides();
    void drawVerticalSides();
    void drawCells();



public:
    QList<QList<SideView*> > horizontal_sides;
    QList<QList<SideView*> > vertical_sides;
    QList<QList<CellView*> > cells;

private:
    size_t points_amount_ = 6;
    size_t paddings_ = 10;
    size_t cell_paddings_ = 10;
    size_t circle_diameter_ = 10;
    size_t width_ = 500;
    size_t height_ = 500;
};

#endif // GAMEFIELD_H
