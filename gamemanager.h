#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "gamefield.h"

class GameManager
{
public:
    static bool isFirstPlayerTurn();

    static void doTurn();

    static void connectGameField(GameField* game_field);

private:
    static int turn_counter_;
    static int first_player_score;
    static int second_player_score;
    static GameField* game_field_;
};


#endif // GAMEMANAGER_H
