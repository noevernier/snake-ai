//
//  utils.cpp
//  SnakeAI
//
//  Created by Noé on 15/07/2021.
//  Copyright © 2021 Noé. All rights reserved.
//

#include "utils.hpp"

double rand_float(double M, double N)
{
    return M + (rand() / ( RAND_MAX / (N-M) ) ) ;
}

sf::Color HSVtoRGB(float H, float S, float V)
{
    float s = S / 100.;
    float v = V / 100.;
    float C = s * v;
    float X = C * (1. - abs(fmod(H / 60., 2.) - 1.));
    float m = v - C;
    float r, g, b;
    
    if (H >= 0 && H < 60)
        r = C, g = X, b = 0;
    
    else if (H >= 60 && H < 120)
        r = X, g = C, b = 0;
    
    else if (H >= 120 && H < 180)
        r = 0, g = C, b = X;
    
    else if (H >= 180 && H < 240)
        r = 0, g = X, b = C;
    
    else if (H >= 240 && H < 300)
        r = X, g = 0, b = C;
    
    else
        r = C, g = 0, b = X;
    
    return sf::Color((r + m) * 255, (g + m) * 255, (b + m) * 255, 255);
}
