//
//  snake_game.cpp
//  SnakeAI
//
//  Created by Noé on 15/07/2021.
//  Copyright © 2021 Noé. All rights reserved.
//

#include "snake_game/snake_game.hpp"

SnakeGame::SnakeGame(){}

void SnakeGame::run(sf::RenderWindow& window){
    snake.update();
    snake.draw(window);
    this->draw(window);
}

void SnakeGame::checkKey(sf::Event event){
    if (event.type == sf::Event::KeyPressed)
    {
        switch (event.key.code) {
            case sf::Keyboard::Up:
                if (snake.getDirection() != DOWN)
                    this->snake.moveTo(UP);
                break;
            case sf::Keyboard::Down:
                if (snake.getDirection() != UP)
                    this->snake.moveTo(DOWN);
                break;
            case sf::Keyboard::Left:
                if (snake.getDirection() != RIGHT)
                    this->snake.moveTo(LEFT);
                break;
            case sf::Keyboard::Right:
                if (snake.getDirection() != LEFT)
                    this->snake.moveTo(RIGHT);
                break;
            default:
                break;
        }
    }
}

void SnakeGame::draw(sf::RenderWindow& window){
    // draw hud with score
    sf::Font font;
    font.loadFromFile("data/fonts/arcade.ttf");
    sf::Text text;
    text.setFont(font);
    text.setString("Score  " + std::to_string(snake.score));
    text.setCharacterSize(32);
    text.setFillColor(sf::Color::White);
    text.setPosition(10, 10);
    window.draw(text);

    // draw you lose
    if(snake.isDead()){
        sf::Text text;
        text.setFont(font);
        text.setString("You  lose");
        text.setCharacterSize(100);
        text.setFillColor(sf::Color::White);
        text.setPosition(window_width/2-200, window_height/2-50);
        window.draw(text);
    }
}
