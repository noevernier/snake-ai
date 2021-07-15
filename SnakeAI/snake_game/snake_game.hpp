//
//  snake_game.hpp
//  SnakeAI
//
//  Created by Noé on 15/07/2021.
//  Copyright © 2021 Noé. All rights reserved.
//

#ifndef snake_game_hpp
#define snake_game_hpp

#include <stdio.h>
#include "snake/snake.hpp"
class SnakeGame{
public:
    
    Snake snake;
    
    SnakeGame();
    
    void Run(sf::RenderWindow& window);
    void checkKey(sf::Event event);
};

#endif /* snake_game_hpp */
