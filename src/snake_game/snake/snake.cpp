//
//  snake.cpp
//  SnakeAI
//
//  Created by Noé on 15/07/2021.
//  Copyright © 2021 Noé. All rights reserved.
//

#include "snake_game/snake/snake.hpp"

Snake::Snake(){
    this->head.x = window_width/(size*2);
    this->head.y = window_width/(size*2);
    this->body.push_back(Cell(this->head.x, this->head.y-1));
    this->dead = false;
    this->score = 0;
}

void Snake::update(){
    if(!this->dead){
        
        for(int i = this->body.size()-1; i > 0; i--){
            this->body[i] = this->body[i-1];
        }
        this->body[0] = this->head;
        this->move();
        
        if(checkFood()){
            apple = Food();
            this->body.push_back(Cell(this->body[this->body.size()-1].x, this->body[this->body.size()-1].y));
            score++;
        }
        
        if(checkCollide()){
            this->dead = true;
        }
        life_time++;
    }
}

void Snake::move(){
    switch (this->dir) {
        case UP:
            this->head.y = (window_height/size + this->head.y-1)%(window_height/size);
            break;
        case DOWN:
            this->head.y = (this->head.y+1)%(window_height/size);
            break;
        case LEFT:
            this->head.x = (window_width/size + this->head.x-1)%(window_width/size);
            break;
        case RIGHT:
            this->head.x = (this->head.x+1)%(window_width/size);
            break;
    }
}

void Snake::draw(sf::RenderWindow &window){
    this->apple.draw(window);
    sf::RectangleShape head(sf::Vector2f(size,size));
    if(!this->dead){head.setFillColor(sf::Color::Green);}
    else {head.setFillColor(sf::Color(200,200,200));}
    head.setPosition(this->head.x*size, this->head.y*size);
    window.draw(head);
    
    for(auto& b : this->body){
        sf::RectangleShape bo(sf::Vector2f(size,size));
        if(!this->dead){bo.setFillColor(sf::Color(100,200,150));}
        else {bo.setFillColor(sf::Color(100,100,100));}
        bo.setPosition(b.x*size, b.y*size);
        window.draw(bo);
    }
    
}

bool Snake::checkFood(){
    if(this->head.x == this->apple.x && this->head.y == this->apple.y){
        return true;
    }
    return false;
}

bool Snake::checkCollide(){
    // if(head.x < 0 || head.x > window_width/size || head.y < 0 || head.y > window_height/size){
    //     return true;
    // }
    
    for(auto& b : this->body){
        if(b.x == head.x && b.y == head.y){
            return true;
        }
    }
    
    return false;
}

void Snake::moveTo(Direction d){
    this->dir = d;
}

Direction Snake::getDirection() const{
    return this->dir;
}

bool Snake::isDead() const{
    return this->dead;
}