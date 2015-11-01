#ifndef GAMEFIELD_H
#define GAMEFIELD_H

#include <QGraphicsScene>
#include <QMainWindow>


class GameField : public QGraphicsScene
{
    Q_OBJECT


public:
    explicit GameField(QObject* parent = 0);

private:
    void drawPoints();
    void drawHorizontalEdges();
    void drawVerticalEdges();

private:
    QList<QGraphicsItem*> edges_;

    size_t points_amount_ = 6;
    size_t paddings_ = 10;
    size_t circle_diameter_ = 10;
    size_t width_ = 500;
    size_t height_ = 500;
};

#endif // GAMEFIELD_H
