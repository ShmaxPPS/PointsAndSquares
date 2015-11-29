#include "mainwindow.h"
#include "ui_mainwindow.h"


#include <QHBoxLayout>
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    game_manager = new GameManager(); // Create game manager.
    game_field = new GameField(game_manager, this); // Create game field that will be processed by game manager.
    game_manager->setGameField(game_field); // Connect game field to game manager.
    computer_player = new ComputerAI(); // Create computer player.
    game_manager->setComputerAI(computer_player); // Connect computer player to game manager.

    view = new QGraphicsView(game_field);
    view->setBackgroundBrush(QBrush(Qt::white, Qt::SolidPattern));
    QHBoxLayout *horizontalLayout = new QHBoxLayout;
    horizontalLayout->addWidget(view);
    this->centralWidget()->setLayout(horizontalLayout);

    initConnectors();
}


void MainWindow::catchRedraw()
{
    this->view->viewport()->repaint();
}

void MainWindow::finishGame(GameResult result)
{
    switch(result)
    {
        case WIN:
            std::cout << "WIN" <<std::endl;
            break;
        case LOSE:
            std::cout << "LOSE" <<std::endl;
            break;
        case DRAW:
            std::cout << "DRAW" <<std::endl;
            break;
        default:
            break;
    }

}

void MainWindow::initConnectors()
{

    for (size_t i = 0; i < game_field->horizontal_sides.size(); ++i)
    {
        for (size_t j = 0; j < game_field->horizontal_sides[i].size(); ++j)
        {
            QObject::connect(game_field->horizontal_sides[i][j], SIGNAL(callSideRedraw()), this, SLOT(catchRedraw()));
        }
    }

    for (size_t i = 0; i < game_field->vertical_sides.size(); ++i)
    {
        for (size_t j = 0; j < game_field->vertical_sides[i].size(); ++j)
        {
            QObject::connect(game_field->vertical_sides[i][j], SIGNAL(callSideRedraw()), this, SLOT(catchRedraw()));
        }
    }

    for (size_t i = 0; i < game_field->cells.size(); ++i)
    {
        for (size_t j = 0; j < game_field->cells[i].size(); ++j)
        {
            QObject::connect(game_field->cells[i][j], SIGNAL(callCellRedraw()), this, SLOT(catchRedraw()));
        }
    }

    QObject::connect(game_manager, SIGNAL(callFinishGame(GameResult)), this, SLOT(finishGame(GameResult)));
}

MainWindow::~MainWindow()
{
    delete ui;
}
