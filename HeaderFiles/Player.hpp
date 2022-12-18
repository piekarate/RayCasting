#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "Map.hpp"
#include <math.h>

class Player
{
private:
    // Variables
    float movementSpeed;
    
    float playerDX, playerDY, playerAngle;
    
    sf::RectangleShape shape;
    std::vector<sf::Vertex> rays;
    
    
    // Functions
    void initVariables();
    void initShape();
    
public:
    Player();
    ~Player();
    
    float degToRad(int a);
    float fixAng(float a);
    
    void updateInput();
    
    float distance(float ax, float ay, float bx, float by);
    
    void drawRays3D(Map map);
    
    void update(Map map);
    void render(sf::RenderTarget* target);
};
