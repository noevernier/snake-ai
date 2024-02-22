//
//  snake_game.cpp
//  SnakeAI
//
//  Created by Noé on 15/07/2021.
//  Copyright © 2021 Noé. All rights reserved.
//

#include "snake_game/snake_game.hpp"

SnakeGame::SnakeGame(){
    
}

void SnakeGame::Run(sf::RenderWindow& window){
    snake.update();
    snake.draw(window);
}

void SnakeGame::checkKey(sf::Event event){
    if (event.type == sf::Event::KeyPressed)
    {
        switch (event.key.code) {
            case sf::Keyboard::Up:
                this->snake.moveTo(UP);
                break;
            case sf::Keyboard::Down:
                this->snake.moveTo(DOWN);
                break;
            case sf::Keyboard::Left:
                this->snake.moveTo(LEFT);
                break;
            case sf::Keyboard::Right:
                this->snake.moveTo(RIGHT);
                break;
        }
    }
}
