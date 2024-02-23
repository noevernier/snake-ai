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
#include "snake_game/snake/snake.hpp"
class SnakeGame{
public:
    
    Snake snake;
    
    SnakeGame();
    
    void run(sf::RenderWindow& window);
    void checkKey(sf::Event event);
    void draw(sf::RenderWindow& window);
};

#endif /* snake_game_hpp */
