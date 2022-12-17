#include "Application.hpp"

void Application::initVariables()
{
    
}

void Application::initWindow()
{
    this->videoMode = sf::VideoMode(1000, 1000);
    this->window = new sf::RenderWindow(this->videoMode, "Ray Casting", sf::Style::Titlebar | sf::Style::Close);
    this->window->setFramerateLimit(60);
}

Application::Application()
{
    this->initVariables();
    this->initWindow();
}

Application::~Application()
{
    delete this->window;
}

const bool Application::isRunning()
{
    return this->window->isOpen();
}

void Application::pollEvents()
{
    while (this->window->pollEvent(this->event))
    {
        switch (this->event.type) {
            case sf::Event::Closed:
                this->window->close();
                break;
                
            default:
                break;
        }
    }
}

void Application::update()
{
    this->pollEvents();
    
    // Update objects
}

void Application::render()
{
    this->window->clear();
    
    // Render objects
    
    this->window->display();
}
