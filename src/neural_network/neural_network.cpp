//
//  neural_network.cpp
//  SnakeAI
//
//  Created by Noé on 16/07/2021.
//  Copyright © 2021 Noé. All rights reserved.
//

#include "neural_network/neural_network.hpp"

NeuralNetwork::NeuralNetwork(int n_inputs,int n_hiddens, int  n_layers, int n_outputs){
    this->n_inputs = n_inputs;
    this->n_hiddens = n_hiddens;
    this->n_layers = n_layers;
    this->n_outputs = n_outputs;
    
    this->weights.push_back(Matrix(n_hiddens, n_inputs));
    this->bias.push_back(Matrix(n_hiddens, 1));
    for (int i = 1; i < n_layers; i++) {
        this->weights.push_back(Matrix(n_hiddens, n_hiddens));
        this->bias.push_back(Matrix(n_hiddens, 1));
    }
    this->weights.push_back(Matrix(n_outputs, n_hiddens));
    this->bias.push_back(Matrix(n_hiddens, 1));
    
    for(auto& w : weights){
        w.randomize();
    }
    for(auto& b : bias){
        b.randomize();
    }
}

std::vector<float> NeuralNetwork::feedForward(std::vector<float> inputs){
    Matrix input = Matrix::fromArray(inputs);
    for (int i = 0; i < n_layers; i++) {
        input = (weights[i] * input) + bias[i];
        input.map(sigmoid);
    }

    input = (weights[weights.size()-1] * input) + bias[bias.size()-1];
    input.map(sigmoid);

    std::vector<float> result;
    for (int i = 0; i < n_outputs; i++) {
        result.push_back(input(i, 0));
    }
    return result;
}

void NeuralNetwork::draw(sf::RenderWindow &window, float x, float y, float s){
    
    float nodes_radius = s/(2*(n_inputs));
    float spacing = 2*s/n_layers;
    
    float h_start = (nodes_radius*(n_inputs)*nodes_radius)/2 - nodes_radius*(n_hiddens)*nodes_radius/2;
    float o_start = (nodes_radius*(n_inputs)*nodes_radius)/2 - nodes_radius*(n_outputs)*nodes_radius/2;
    
    //draw weights
    for (int i = 0; i < n_hiddens; i++) {
        for (int j = 0; j < n_inputs; j++) {
            float h = (weights[0](i, j) + 1) * (255/2);
            sf::Color c = HSVtoRGB(h, 255, 255);
            sf::Vertex line[2];
            line[0].position = sf::Vector2f(x + nodes_radius, y +  nodes_radius*j*nodes_radius + nodes_radius);
            line[0].color  = sf::Color(c.r,0,c.b);
            line[1].position = sf::Vector2f(x + spacing + nodes_radius, h_start + y +  nodes_radius*i*nodes_radius + nodes_radius);
            line[1].color = sf::Color(c.r,0,c.b);
            window.draw(line, 2, sf::Lines);
        }
    }
    
    for (int k = 1; k < n_layers; k++) {
        for (int i = 0; i < n_hiddens; i++) {
            for (int j = 0; j < n_hiddens; j++) {
                float h = (weights[k](i, j) + 1) * (255/2);
                sf::Color c = HSVtoRGB(h, 255, 255);
                sf::Vertex line[2];
                line[0].position = sf::Vector2f(x + spacing*k+ nodes_radius, h_start +y +  nodes_radius*j*nodes_radius + nodes_radius);
                line[0].color  = sf::Color(c.r,0,c.b);
                line[1].position = sf::Vector2f(x + spacing*(k+1)+ nodes_radius, h_start + y +  nodes_radius*i*nodes_radius + nodes_radius);
                line[1].color = sf::Color(c.r,0,c.b);
                window.draw(line, 2, sf::Lines);
            }
        }
    }
    
    for (int i = 0; i < n_outputs; i++) {
        for (int j = 0; j < n_hiddens; j++) {
            float h = (weights[weights.size()-1](i, j) + 1) * (255/2);
            sf::Color c = HSVtoRGB(h, 255, 255);
            sf::Vertex line[2];
            line[0].position = sf::Vector2f(x + spacing*(n_layers)+ nodes_radius, h_start + y +  nodes_radius*j*nodes_radius + nodes_radius);
            line[0].color  = sf::Color(c.r,0,c.b);
            line[1].position = sf::Vector2f(x+ spacing*(n_layers+1) + nodes_radius, o_start + y +  nodes_radius*i*nodes_radius+ nodes_radius);
            line[1].color = sf::Color(c.r,0,c.b);
            window.draw(line, 2, sf::Lines);
        }
    }
    
    //draw inputs
    for (int i = 0; i < n_inputs; i++) {
        sf::CircleShape node(nodes_radius);
        node.setPosition(x, y +  nodes_radius*i*nodes_radius);
        node.setFillColor(sf::Color(100,230,150));
        window.draw(node);
    }
    
    for (int i = 0; i < n_layers; i++) {
        for (int j = 0; j < n_hiddens; j++) {
            sf::CircleShape node(nodes_radius);
            node.setPosition(x + spacing*(i+1), h_start + y +  nodes_radius*j*nodes_radius);
            window.draw(node);
        }
    }
    
    for (int i = 0; i < n_outputs; i++) {
        sf::CircleShape node(nodes_radius);
        node.setFillColor(sf::Color(100,150,230));
        node.setPosition(x+ spacing*(n_layers+1), o_start + y +  nodes_radius*i*nodes_radius);
        window.draw(node);
    }
    
}
