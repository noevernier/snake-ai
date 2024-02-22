//
//  food.hpp
//  SnakeAI
//
//  Created by Noé on 15/07/2021.
//  Copyright © 2021 Noé. All rights reserved.
//

#ifndef food_hpp
#define food_hpp

#include <stdio.h>
#include "utils/utils.hpp"

class Food{
public:
    int x;
    int y;
    Food();
    Food(int x, int y);
    void draw(sf::RenderWindow& window);
};

#endif /* food_hpp */
