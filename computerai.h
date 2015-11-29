#ifndef COMPUTERAI_H
#define COMPUTERAI_H

#include "gamefield.h"

class ComputerAI
{
public:
    ComputerAI();

    void setGameField(GameField* game_field);

    SideView* makeRandomTurn();

private:
    GameField* game_field_;
};

#endif // COMPUTERAI_H
