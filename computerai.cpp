#include "computerai.h"
#include <iostream>

ComputerAI::ComputerAI()
{
}


SideView* ComputerAI::makeRandomTurn()
{
    size_t isNotDisabled = 0;
    for (size_t i = 0; i < game_field_->horizontal_sides.size(); ++i)
    {
        for (size_t j = 0; j < game_field_->horizontal_sides[i].size(); ++j)
        {
            if(game_field_->horizontal_sides[i][j]->state != DISABLED)
            {
                ++isNotDisabled;
            }
        }
    }
    for (size_t i = 0; i < game_field_->vertical_sides.size(); ++i)
    {
        for (size_t j = 0; j < game_field_->vertical_sides[i].size(); ++j)
        {
            if(game_field_->vertical_sides[i][j]->state != DISABLED)
            {
                ++isNotDisabled;
            }
        }
    }
    size_t rand_index = rand() % isNotDisabled;
    size_t current_index = 0;
    for (size_t i = 0; i < game_field_->horizontal_sides.size(); ++i)
    {
        for (size_t j = 0; j < game_field_->horizontal_sides[i].size(); ++j)
        {
            if(game_field_->horizontal_sides[i][j]->state != DISABLED)
            {
                if(current_index == rand_index)
                {
                    return game_field_->horizontal_sides[i][j];
                }
                ++current_index;
            }
        }
    }
    for (size_t i = 0; i < game_field_->vertical_sides.size(); ++i)
    {
        for (size_t j = 0; j < game_field_->vertical_sides[i].size(); ++j)
        {
            if(game_field_->vertical_sides[i][j]->state != DISABLED)
            {
                if(current_index == rand_index)
                {
                    return game_field_->vertical_sides[i][j];
                }
                ++current_index;
            }
        }
    }
    return nullptr;
}

void ComputerAI::setGameField(GameField* game_field)
{
    game_field_ = game_field;
}
