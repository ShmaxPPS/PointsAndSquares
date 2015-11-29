#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>

#include "gamemanager.h"

class Game : public QGraphicsView
{
    Q_OBJECT

public:
    explicit Game(QWidget* parent = 0);

    void displayStartWindow();
    void displayGameWindow();
    void displayFinishWindow(QString text_to_display);

private:
    void initConnectors();
    void drawPanel(size_t x, size_t y, size_t width, size_t height, QColor color, double opacity);

public slots:
    void startGame();
    void catchRedraw();
    void finishGame(GameResult result);

public:
    QGraphicsScene* scene;
    QGraphicsView* view;

private:
    GameManager* game_manager;
    GameField*  game_field;
    ComputerAI* computer_player;
};

#endif // GAME_H
