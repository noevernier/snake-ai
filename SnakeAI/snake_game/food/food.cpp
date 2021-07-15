//
//  food.cpp
//  SnakeAI
//
//  Created by Noé on 15/07/2021.
//  Copyright © 2021 Noé. All rights reserved.
//

#include "food.hpp"

Food::Food(){
    this->x = rand()%(window_width/size);
    this->y = rand()%(window_height/size);
}

Food::Food(int x, int y){
    this->x = x;
    this->y = y;
}

void Food::draw(sf::RenderWindow &window){
    sf::RectangleShape food(sf::Vector2f(size, size));
    food.setFillColor(sf::Color::Red);
    food.setPosition(this->x*size, this->y*size);
    window.draw(food);
}
