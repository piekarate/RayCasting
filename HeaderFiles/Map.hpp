#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <iostream>

class Map
{
private:
    // Variables
    int mapX, mapY, mapSize;
    int map [64] =
    {
        1, 1, 1, 1, 1, 1, 1, 1,
        1, 0, 1, 0, 0, 0, 0, 1,
        1, 0, 1, 0, 0, 0, 0, 1,
        1, 0, 1, 0, 0, 0, 0, 1,
        1, 0, 0, 0, 0, 0, 0, 1,
        1, 0, 0, 0, 0, 1, 0, 1,
        1, 0, 0, 0, 0, 0, 0, 1,
        1, 1, 1, 1, 1, 1, 1, 1,
    };
    
    // Functions
    void initVariables();
    void initMap();
    
public:
    // Constructors | Destructors
    Map();
    ~Map();
    
    void update();
    void render(sf::RenderTarget* target);
};
