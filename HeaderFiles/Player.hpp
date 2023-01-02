#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

//#include "Textures.h"


#include "Map.hpp"
#include <math.h>

class Player
{
private:
    // Variables
    float movementSpeed;
    
    float playerDX, playerDY, playerAngle;
    
    sf::RectangleShape shape;
    sf::RectangleShape floor;
    std::vector<sf::Vertex> rays;
    std::vector<sf::RectangleShape> walls3d;
    std::vector<sf::RectangleShape> pixels;
    
    // Functions
    void initVariables();
    void initShape();
    
public:
    Player();
    ~Player();
    
    float degToRad(int a);
    float fixAng(float a);
    
    void updateInput(Map map);
    float map(float value, float istart, float istop, float ostart, float ostop);
    float distance(float ax, float ay, float bx, float by);
    
    void drawRays3D(Map map);
    
    void update(Map map);
    void render(sf::RenderTarget* target);
};
