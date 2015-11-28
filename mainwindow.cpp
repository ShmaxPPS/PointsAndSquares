#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gamemanager.h"

#include <QHBoxLayout>
#include <QGraphicsView>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    game_field = new GameField(this);
    GameManager::connectGameField(game_field);
    QGraphicsView* view = new QGraphicsView(game_field);
    view->setBackgroundBrush(QBrush(Qt::white, Qt::SolidPattern));
    QHBoxLayout *horizontalLayout = new QHBoxLayout;
    horizontalLayout->addWidget(view);
    this->centralWidget()->setLayout(horizontalLayout);
}


MainWindow::~MainWindow()
{
    delete ui;
}
