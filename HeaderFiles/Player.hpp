#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Player
{
private:
    // Variables
    float movementSpeed;
    
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
