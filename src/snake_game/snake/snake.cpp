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
    this->brain = NeuralNetwork(10, 10, 3, 4);
}

void Snake::update(){
    if(!this->dead){

        this->think();
        
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

    // draw brain
    this->brain.draw(window, 0, 0, 100);
    
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

void Snake::think(){
    auto distances_to_apple = getDistanceToApple();
    auto distances_to_wall = getDistanceToWall();
    auto distances_to_tail = getDistanceToTail();

    std::vector<float> inputs = {
        static_cast<float>(distances_to_apple[0]) / (window_width/size),
        static_cast<float>(distances_to_apple[1]) / (window_height/size),
        static_cast<float>(distances_to_wall[0]) / (window_width/size),
        static_cast<float>(distances_to_wall[1]) / (window_width/size),
        static_cast<float>(distances_to_wall[2]) / (window_height/size),
        static_cast<float>(distances_to_wall[3]) / (window_height/size),
        static_cast<float>(distances_to_tail[0]) / (window_width/size),
        static_cast<float>(distances_to_tail[1]) / (window_width/size),
        static_cast<float>(distances_to_tail[2]) / (window_height/size),
        static_cast<float>(distances_to_tail[3]) / (window_height/size)
    };

    std::cout << "inputs: ";
    for(auto i: inputs){
        std::cout << i << " ";
    }

    auto outputs = this->brain.feedForward(inputs);

    std::cout << "outputs: ";
    for(auto o: outputs){
        std::cout << o << " ";
    }

    int max_index = 0;
    for(int i = 0; i < outputs.size(); i++){
        if(outputs[i] > outputs[max_index]){
            max_index = i;
        }
    }

    std::cout << "max_index: " << max_index << std::endl;

    switch (max_index) {
        case 0:
            this->dir = UP;
            break;
        case 1:
            this->dir = DOWN;
            break;
        case 2:
            this->dir = LEFT;
            break;
        case 3:
            this->dir = RIGHT;
            break;
    }


}

std::array<int, 2> Snake::getDistanceToApple(){
    std::array<int, 2> distances;
    distances[0] = this->head.x - this->apple.x;
    distances[1] = this->head.y - this->apple.y;
    return distances;
}

std::array<int, 4> Snake::getDistanceToWall(){
    std::array<int, 4> distances;
    distances[0] = (this->head.x);
    distances[1] = (window_width/size - this->head.x);
    distances[2] = (this->head.y);
    distances[3] = (window_height/size - this->head.y);
    return distances;
}

std::array<int, 4> Snake::getDistanceToTail(){
    std::array<int, 4> distances;

    distances[0] = -1;
    distances[1] = -1;
    distances[2] = -1;
    distances[3] = -1;

    for(auto cell: this->body){
        if(cell.y == this->head.y){
            if(cell.x < this->head.x){
                distances[0] = this->head.x - cell.x;
            }else{
                distances[1] = cell.x - this->head.x;
            }
        }
        if(cell.x == this->head.x){
            if(cell.y > this->head.y){
                distances[2] = cell.y - this->head.y;
            }else{
                distances[3] = this->head.y - cell.y;
            }
        }
    }

    return distances;
}

