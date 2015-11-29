#include "button.h"
#include "game.h"

#include <QHBoxLayout>
#include <iostream>

Game::Game(QWidget* parent) : QGraphicsView(parent)
{
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1024, 768);

    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, 1024, 768);
    setScene(scene);
}

void Game::displayStartWindow()
{
    QGraphicsTextItem* titleText = new QGraphicsTextItem(QString("Points and Squares"));
    QFont titleFont("comic sans", 50);
    titleText->setFont(titleFont);
    int txPos = this->width() / 2 - titleText->boundingRect().width() / 2;
    int tyPos = 150;
    titleText->setPos(txPos, tyPos);
    scene->addItem(titleText);

    Button* playButton = new Button(200, 50, QString("Play"));
    txPos = this->width() / 2 - playButton->boundingRect().width() / 2;
    tyPos = 350;
    playButton->setPos(txPos, tyPos);
    scene->addItem(playButton);
    QObject::connect(playButton, SIGNAL(clicked()), this, SLOT(startGame()));


    Button* quitButton = new Button(200, 50, QString("Quit"));
    txPos = this->width() / 2 - quitButton->boundingRect().width() / 2;
    tyPos = 425;
    quitButton->setPos(txPos, tyPos);
    scene->addItem(quitButton);
    QObject::connect(quitButton, SIGNAL(clicked()), this, SLOT(close()));

}

void Game::displayGameWindow()
{
    scene->clear();

    game_manager = new GameManager(); // Create game manager.
    game_field = new GameField(500, 500, game_manager); // Create game field that will be processed by game manager.
    game_manager->setGameField(game_field); // Connect game field to game manager.
    computer_player = new ComputerAI(); // Create computer player.
    game_manager->setComputerAI(computer_player); // Connect computer player to game manager.

    initConnectors();
}

void Game::displayFinishWindow(QString text_to_display)
{
    for (size_t i = 0; i < scene->items().size(); ++i)
    {
        scene->items()[i]->setEnabled(false);
    }

    drawPanel(0, 0, 1024, 768, Qt::black, 0.65);

    drawPanel(312, 184, 400, 400, Qt::lightGray, 0.75);

    Button* playAgain = new Button(200, 50, QString("Play Again"));
    playAgain->setPos(410, 350);
    scene->addItem(playAgain);
    QObject::connect(playAgain, SIGNAL(clicked()), this, SLOT(startGame()));

    Button* quit = new Button(200, 50, QString("Quit"));
    quit->setPos(410, 425);
    scene->addItem(quit);
    QObject::connect(quit, SIGNAL(clicked()), this, SLOT(close()));

    QGraphicsTextItem* overText = new QGraphicsTextItem(text_to_display);
    QFont titleFont("comic sans", 40);
    overText->setFont(titleFont);
    int txPos = 312 + 400 / 2 - overText->boundingRect().width() / 2;
    int tyPos = 250;
    overText->setPos(txPos, tyPos);
    scene->addItem(overText);
}

void Game::startGame()
{
    displayGameWindow();
}

void Game::finishGame(GameResult result)
{
    switch(result)
    {
        case WIN:
            displayFinishWindow(QString("You win!"));
            break;
        case LOSE:
            displayFinishWindow(QString("You lose!"));
            break;
        case DRAW:
            displayFinishWindow(QString("It is draw!"));
            break;
        default:
            break;
    }
}

void Game::catchRedraw()
{
    this->viewport()->repaint();
}


void Game::initConnectors()
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

void Game::drawPanel(size_t x, size_t y, size_t width, size_t height, QColor color, double opacity)
{
    QGraphicsRectItem* panel = new QGraphicsRectItem(x, y, width, height);
    QBrush brush(color);
    panel->setBrush(brush);
    panel->setOpacity(opacity);
    scene->addItem(panel);
}



