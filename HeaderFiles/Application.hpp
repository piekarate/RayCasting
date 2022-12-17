#pragma once
#include <iostream>
#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>


class Application
{
private:
    // Variables
    sf::VideoMode videoMode;
    sf::RenderWindow *window;
    
    sf::Event event;
    
    // Objects

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

    
    void update();
    void render();
};
