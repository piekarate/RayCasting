#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <iostream>
#include <array>

class Map
{
private:
    // Variables
    int mapX, mapY, mapSize;
    
    std::array<int, 64> map = {
            1, 1, 1, 1, 1, 1, 1, 1,
            1, 0, 1, 0, 0, 0, 0, 1,
            1, 0, 1, 0, 0, 0, 0, 1,
            1, 0, 1, 0, 0, 0, 0, 1,
            1, 0, 0, 0, 0, 0, 0, 1,
            1, 0, 0, 0, 0, 1, 0, 1,
            1, 0, 0, 0, 0, 0, 0, 1,
            1, 1, 1, 1, 1, 1, 1, 1,
        };
    std::vector<sf::Vertex> vertices;
    
    // Functions
    void initVariables();
    void initMap();
    
public:
    // Constructors | Destructors
    Map();
    ~Map();
    
    // Accessors
    sf::Vector2f getXY();
    int getSize();
    std::array<int, 64> getMap();
    
    void update();
    void render(sf::RenderTarget* target);
};
