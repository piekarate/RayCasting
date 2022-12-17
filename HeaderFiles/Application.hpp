#pragma once
#include <iostream>
#include <vector>

#include "Player.hpp"
#include "Map.hpp"


class Application
{
private:
    // Variables
    sf::VideoMode videoMode;
    sf::RenderWindow *window;
    
    sf::Event event;
    
    // Objects
    Player player;
    Map map;
    
    // Initializer Functions
    
    void initVariables();
    void initWindow();
    
public:
    // Constructors | Deconstructors
    Application();
    ~Application();
    
    // Functions
    const bool isRunning();
    void pollEvents();

    void updatePlayer();
    
    void update();
    void render();
};
