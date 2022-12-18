#include "Application.hpp"

void Application::initVariables()
{
    
}

void Application::initWindow()
{
    this->videoMode = sf::VideoMode(2048, 1024);
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

void Application::updatePlayer()
{
    this->player.update(this->map);
}

void Application::update()
{
    this->pollEvents();
    
    // Update objects
    this->updatePlayer();
}

void Application::render()
{
    this->window->clear(sf::Color(128,128,128));
    
    // Render objects
    
    this->map.render(this->window);
    this->player.render(this->window);
    
    this->window->display();
}
