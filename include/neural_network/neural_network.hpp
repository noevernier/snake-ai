//
//  neural_network.hpp
//  SnakeAI
//
//  Created by Noé on 16/07/2021.
//  Copyright © 2021 Noé. All rights reserved.
//

#ifndef neural_network_hpp
#define neural_network_hpp

#include <stdio.h>
#include "matrix/matrix.hpp"
#include <vector>

class NeuralNetwork{
public:
    int n_inputs, n_hiddens, n_layers, n_outputs;
    std::vector<Matrix> weights;
    std::vector<Matrix> bias;
    
    NeuralNetwork(int n_inputs,int n_hiddens, int  n_layers, int n_outputs);
    NeuralNetwork(){}
    
    void draw(sf::RenderWindow& window, float x, float y, float s);
    std::vector<float> feedForward(std::vector<float> inputs);
    
};

#endif /* neural_network_hpp */
