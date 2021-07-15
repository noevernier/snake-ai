//
//  application.hpp
//  SnakeAI
//
//  Created by Noé on 15/07/2021.
//  Copyright © 2021 Noé. All rights reserved.
//

#ifndef application_hpp
#define application_hpp

#include <stdio.h>
#include "utils.hpp"
#include "snake_game.hpp"
#include "neural_network.hpp"

class App {
public:
    sf::RenderWindow* window;
    int width, height;
    std::string title;
    
    SnakeGame s_game;
    NeuralNetwork* brain;
    
    App(){}
    App(int w_width, int w_height, std::string title);
    
    void Init(int);
    void Run();
private:
    void Events();

};

#endif /* application_hpp */
