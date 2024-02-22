//
//  utils.hpp
//  SnakeAI
//
//  Created by Noé on 15/07/2021.
//  Copyright © 2021 Noé. All rights reserved.
//

#ifndef utils_hpp
#define utils_hpp

#include <stdio.h>
#include <iostream>
#include <math.h>
#include <SFML/Graphics.hpp>
#include "matrix/matrix.hpp"
#include "utils/constants.h"

struct Cell
{
    int x;
    int y;
    
    Cell(int x, int y){this->x = x;this->y = y;}
    Cell(){}
};

double rand_float(double M, double N);
sf::Color HSVtoRGB(float H, float S, float V);

#endif /* utils_hpp */
