#include "gamemanager.h"
#include <iostream>

void GameManager::doTurn()
{
    bool cellIsCatched = false;
    size_t grid_size = game_field_->cells.size();

    for (size_t i = 0; i < grid_size; ++i)
    {
        for (size_t j = 0; j < grid_size; ++j)
        {
            if (game_field_->horizontal_sides[i][j]->state == DISABLED &&
                game_field_->horizontal_sides[i + 1][j]->state == DISABLED &&
                game_field_->vertical_sides[i][j]->state == DISABLED &&
                game_field_->vertical_sides[i][j + 1]->state == DISABLED &&
                game_field_->cells[i][j]->getState() == EMPTY)
            {
                if(isFirstPlayerTurn())
                {
                    game_field_->cells[i][j]->setState(FIRST_PLAYER);
                    first_player_score++;
                }
                else
                {
                    game_field_->cells[i][j]->setState(SECOND_PLAYER);
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

    if (first_player_score + second_player_score == grid_size * grid_size)
    {
        // All cells are catched, game is finished.

        std::cout << "GAME IS FINISHED: " << first_player_score << " " << second_player_score << std::endl;
    }
}

bool GameManager::isFirstPlayerTurn()
{
    return turn_counter_ % 2 == 0;
}

void GameManager::connectGameField(GameField* game_field)
{
    game_field_ = game_field;
    turn_counter_ = 0;
}

int GameManager::turn_counter_ = 0;
int GameManager::first_player_score = 0;
int GameManager::second_player_score = 0;
GameField* GameManager::game_field_ = nullptr;
