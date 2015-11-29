#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <QObject>
#include "gamefield.h"
#include "computerai.h"

enum GameResult { WIN, LOSE, DRAW };

class GameManager : public QObject
{
    Q_OBJECT

public:
    explicit GameManager();

    bool isPlayerTurn();

    void doTurn();

    void setGameField(GameField* game_field);

    void setComputerAI(ComputerAI* computer_player);

signals:
    void callFinishGame(GameResult result);

private:
    int turn_counter_;
    int first_player_score;
    int second_player_score;
    GameField* game_field_;
    ComputerAI* computer_player_;
};


#endif // GAMEMANAGER_H
