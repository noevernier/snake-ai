//
//  application.cpp
//  SnakeAI
//
//  Created by Noé on 15/07/2021.
//  Copyright © 2021 Noé. All rights reserved.
//

#include "app/application.hpp"

App::App(int w_width, int w_height, std::string title){
    this->width = w_width;
    this->height = w_height;
    this->title = title;
}

void App::Init(int fps){
    this->window = new sf::RenderWindow(sf::VideoMode(this->width, this->height), this->title);
    this->window->setFramerateLimit(fps);
    
    this->brain = new NeuralNetwork(9,5,5,3);
}

void App::Run(){
    while (window->isOpen())
    {
        // Process events
        this->Events();
        window->clear();
        s_game.run(*window);
        // brain->draw(*window, 10, 10, 130);
        window->display();
    }
}

void App::Events(){
    sf::Event sf_event;
    while (window->pollEvent(sf_event))
    {
        if (sf_event.type == sf::Event::Closed) {
            window->close();
        }
        s_game.checkKey(sf_event);
    }
}
