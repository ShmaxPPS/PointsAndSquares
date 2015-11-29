#include "gamemanager.h"

#include <iostream>
#include <thread>
#include <chrono>

GameManager::GameManager()
{
    turn_counter_ = 0;
    first_player_score = 0;
    second_player_score = 0;
}

void GameManager::doTurn()
{
    bool cellIsCatched = false;

    for (size_t i = 0; i < game_field_->cells.size(); ++i)
    {
        for (size_t j = 0; j < game_field_->cells[i].size(); ++j)
        {
            if (game_field_->horizontal_sides[i][j]->state == DISABLED &&
                game_field_->horizontal_sides[i + 1][j]->state == DISABLED &&
                game_field_->vertical_sides[i][j]->state == DISABLED &&
                game_field_->vertical_sides[i][j + 1]->state == DISABLED &&
                game_field_->cells[i][j]->getState() == EMPTY)
            {
                if(isPlayerTurn())
                {
                    game_field_->cells[i][j]->setState(PLAYER);
                    first_player_score++;
                }
                else
                {
                    game_field_->cells[i][j]->setState(COMPUTER);
                    second_player_score++;
                }
                cellIsCatched = true;
            }
        }
    }

    if(!cellIsCatched)
    {
        turn_counter_++;
    }

    if (first_player_score + second_player_score ==
            game_field_->cells.size() * game_field_->cells.size())
    {
        // All cells are catched, game is finished.
        if(first_player_score > second_player_score)
        {
            emit callFinishGame(WIN);
        }
        else if(first_player_score < second_player_score)
        {
            emit callFinishGame(LOSE);
        }
        else
        {
            emit callFinishGame(DRAW);
        }
        return;
    }

    if(!isPlayerTurn())
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
        computer_player_->makeRandomTurn()->pressSideView();
    }
}

bool GameManager::isPlayerTurn()
{
    return turn_counter_ % 2 == 0;
}

void GameManager::setGameField(GameField* game_field)
{
    game_field_ = game_field;
}

void GameManager::setComputerAI(ComputerAI* computer_player)
{
    computer_player_ = computer_player;
    computer_player_->setGameField(game_field_);
}


