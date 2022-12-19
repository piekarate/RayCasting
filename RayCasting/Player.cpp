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

float Player::degToRad(int a) {return a*M_PI/180.0;}

float Player::fixAng(float a) { if (a>359) {a-=360;} if (a<0) {a+= 360;} return a;}


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
        this->shape.move(this->playerDX, this->playerDY);
    }
    // Down
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        this->shape.move(-this->playerDX, -this->playerDY);
    }
}

float Player::distance(float ax, float ay, float bx, float by)
{
    return sqrt((bx-ax)*(bx-ax) + (by-ay)*(by-ay));
}

void Player::drawRays3D(Map map)
{
    int rayN, mx, my, mp, dof = 0; float rayX, rayY, rayAngle, xOffset, yOffset = 0;
    
    float playerX = this->shape.getPosition().x+10;
    float playerY = this->shape.getPosition().y+10;
    
    int mapX = map.getXY().x;
    int mapY = map.getXY().y;

    std::array<int, 64> tempMap = map.getMap();
    
    float DR = 0.0174533; // One degree in radiants

    rayAngle = this->playerAngle - DR * 30;
    if (rayAngle<0)
    {
        rayAngle+=2*M_PI;
    }
    if (rayAngle>2*M_PI) {
        rayAngle-=2*M_PI;
    }
    
    
    
    this->rays.clear();
    
    for (rayN = 0; rayN < 60; rayN++)
    {
        //  --- Check Horizontal Lines ---
        dof = 0;
        float disH=1000000, hx=playerX, hy=playerY;
        float aTan = -1/tan(rayAngle);
        // Looking up
        if (rayAngle > M_PI)
        {
            rayY = (((int)playerY>>7)<<7)-0.0001;
            rayX =(playerY - rayY) * aTan + playerX;
            yOffset = -128;
            xOffset = -yOffset*aTan;
        }
        // Looking down
        if (rayAngle < M_PI)
        {
            rayY = (((int)playerY>>7)<<7)+128;
            rayX =(playerY - rayY) * aTan + playerX;
            yOffset = 128;
            xOffset = -yOffset*aTan;
        }
        // Looking straight left or right
        if (rayAngle == 0 || rayAngle==M_PI)
        {
            rayX = playerX;
            rayY = playerY;
            dof = 8;
        }

        while (dof < 8)
        {
            mx = (int) (rayX)>>7;
            my = (int) (rayY)>>7;
            mp = my*mapX+mx;

            // Hit wall

            if (mp > 0 &&mp < mapX*mapY && tempMap[mp] == 1)
            {
                hx = rayX;
                hy = rayY;
                disH = distance(playerX, playerY, hx, hy);
                dof = 8;
            } else
            {
                rayX += xOffset;
                rayY += yOffset;
                dof += 1;
            }
        }
        
        // --- Check Vertical Lines ---
        dof = 0;
        float disV=1000000, vx=playerX, vy=playerY;
        float nTan = -tan(rayAngle);
        // Looking left
        if (rayAngle > M_PI/2 && rayAngle < 3*M_PI/2)
        {
            rayX = (((int)playerX>>7)<<7)-0.0001;
            rayY =(playerX - rayX) * nTan + playerY;
            xOffset = -128;
            yOffset = -xOffset*nTan;
        }
        // Looking right
        if (rayAngle < M_PI/2 || rayAngle > 3*M_PI/2)
        {
            rayX = (((int)playerX>>7)<<7)+128;
            rayY =(playerX - rayX) * nTan + playerY;
            xOffset = 128;
            yOffset = -xOffset*nTan;
        }
        // Looking straight left or right
        if (rayAngle == 0 || rayAngle==M_PI)
        {
            rayX = playerX;
            rayY = playerY;
            dof = 8;
        }

        while (dof < 8)
        {
            mx = (int) (rayX)>>7;
            my = (int) (rayY)>>7;
            mp = my*mapX+mx;

            // Hit wall

            if (mp > 0 && mp < mapX*mapY && tempMap[mp] == 1)
            {
                vx = rayX;
                vy = rayY;
                disV = distance(playerX, playerY, vx, vy);
                dof = 8;
            } else
            {
                rayX += xOffset;
                rayY += yOffset;
                dof += 1;
            }
        }
        if (disV < disH) {rayX=vx; rayY=vy;}
        if (disV > disH) {rayX=hx; rayY=hy;}
        this->rays.push_back(sf::Vertex( sf::Vector2f(playerX, playerY), sf::Color::Red ));
        this->rays.push_back(sf::Vertex( sf::Vector2f(rayX, rayY), sf::Color::Red ));
        rayAngle += DR;
        if (rayAngle<0)
        {
            rayAngle+=2*M_PI;
        }
        if (rayAngle>2*M_PI) {
            rayAngle-=2*M_PI;
        }
        
    }
    
}

void Player::update(Map map)
{
    this->updateInput();
    this->drawRays3D(map);
}

void Player::render(sf::RenderTarget *target)
{
    target->draw(this->shape);
    
    target->draw(&this->rays[0], this->rays.size(), sf::Lines);
}

