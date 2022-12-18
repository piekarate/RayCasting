#include "Player.hpp"

void Player::initVariables()
{
    this->movementSpeed = 5.f;
    this->playerAngle = 0.f;
    this->playerDX = cos(playerAngle) * 5;
    this->playerDY = sin(playerAngle) * 5;
}

void Player::initShape()
{
    this->shape.setFillColor(sf::Color::Yellow);
    this->shape.setSize(sf::Vector2f(20.f, 20.f));
    this->shape.setPosition(500, 500);
}

Player::Player()
{
    this->initVariables();
    this->initShape();
}

Player::~Player()
{
    
}


void Player::updateInput()
{
    // Keyboard inputs
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
//        this->shape.move(-this->movementSpeed, 0.f);
        this->playerAngle -= 0.1;
        if (this->playerAngle < 0) {this->playerAngle += 2*M_PI;}
        this->playerDX = cos(playerAngle) * 5;
        this->playerDY = sin(playerAngle) * 5;
    }
    // Right
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
//        this->shape.move(this->movementSpeed, 0.f);
        this->playerAngle += 0.1;
        if (this->playerAngle > 2*M_PI) {this->playerAngle -= 2*M_PI;}
        this->playerDX = cos(playerAngle) * 5;
        this->playerDY = sin(playerAngle) * 5;
    }
    // Up
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
//        this->shape.move(0.f, -this->movementSpeed);
        this->shape.move(this->playerDX, this->playerDY);
    }
    // Down
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
//        this->shape.move(0.f, this->movementSpeed);
        this->shape.move(-this->playerDX, -this->playerDY);
    }
}

void Player::update()
{
    this->updateInput();
}

void Player::render(sf::RenderTarget *target)
{
    target->draw(this->shape);
    
    sf::Vertex vertices[2] =
    {
        sf::Vertex( sf::Vector2f(this->shape.getPosition().x+10, this->shape.getPosition().y+10), sf::Color::Yellow),
        sf::Vertex( sf::Vector2f(this->shape.getPosition().x + this->playerDX * 10, this->shape.getPosition().y + this->playerDY * 10), sf::Color::Yellow)
    };
    target->draw(vertices, 2, sf::Lines);
}
