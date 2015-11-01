#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QHBoxLayout>
#include <QGraphicsView>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->game_field = new GameField(this);
    QGraphicsView* view = new QGraphicsView(game_field);
    view->setBackgroundBrush(QBrush(Qt::black, Qt::SolidPattern));
    QHBoxLayout *horizontalLayout = new QHBoxLayout;
    horizontalLayout->addWidget(view);
    this->centralWidget()->setLayout(horizontalLayout);
}


MainWindow::~MainWindow()
{
    delete ui;
}
