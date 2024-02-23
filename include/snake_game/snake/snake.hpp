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
#include "neural_network/neural_network.hpp"


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
    void think();
private:
    bool checkFood();
    bool checkCollide();

    std::array<int, 2> getDistanceToApple();
    std::array<int, 4> getDistanceToWall();
    std::array<int, 4> getDistanceToTail();
    
    void move();

    // brain
    NeuralNetwork brain;
};

#endif /* snake_hpp */
