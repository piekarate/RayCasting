#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <math.h>

class Player
{
private:
    // Variables
    float movementSpeed;
    
    float playerDX, playerDY, playerAngle;
    
    sf::RectangleShape shape;
    
    
    // Functions
    void initVariables();
    void initShape();
    
public:
    Player();
    ~Player();
    
    void updateInput();
    
    void update();
    void render(sf::RenderTarget* target);
};
