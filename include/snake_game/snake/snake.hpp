//
//  snake.hpp
//  SnakeAI
//
//  Created by Noé on 15/07/2021.
//  Copyright © 2021 Noé. All rights reserved.
//

#ifndef snake_hpp
#define snake_hpp

#include <stdio.h>
#include "snake_game/food/food.hpp"


class Snake{
public:
    Cell head;
    std::vector<Cell> body;

    bool dead;
    Food apple;
    Direction dir;
    
    int score;
    int life_time;

    Snake();
    
    void update();
    void draw(sf::RenderWindow& window);
    
    void moveTo(Direction d);
    Direction getDirection() const;
    bool isDead() const;
private:
    bool checkFood();
    bool checkCollide();
    
    void move();
};

#endif /* snake_hpp */
