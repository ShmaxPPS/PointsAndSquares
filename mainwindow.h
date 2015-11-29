#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>

#include "gamemanager.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    void initConnectors();

public slots:
    void catchRedraw();
    void finishGame(GameResult result);

private:
    Ui::MainWindow *ui;
    QGraphicsView* view;
    GameManager* game_manager;
    GameField*  game_field;
    ComputerAI* computer_player;
};

#endif // MAINWINDOW_H
