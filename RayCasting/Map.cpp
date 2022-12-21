#include "Map.hpp"

void Map::initVariables()
{
    this->mapX = 8;
    this->mapY = 8;
    this->mapSize = 128;
}

void Map::initMap()
{
    int x, y, xOffset, yOffset;
    sf::Color color;
    
    for (y=0; y<this->mapY; y++)
    {
        for (x=0; x<this->mapX; x++)
        {
            // Choose Color based on array numbers
            if (this->map[y*this->mapX+x] == 1)
            {

                color = sf::Color::White;
                
            } else
            {

                color = sf::Color::Black;
            }
            
            // Draw rectangle
            xOffset = x*this->mapSize;
            yOffset = y*this->mapSize;
            this->vertices.push_back( sf::Vertex( sf::Vector2f(xOffset + 1, yOffset + 1), color));
            this->vertices.push_back( sf::Vertex( sf::Vector2f(xOffset + 1, yOffset + this->mapSize - 1), color));
            this->vertices.push_back( sf::Vertex( sf::Vector2f(xOffset + this->mapSize - 1, yOffset + this->mapSize - 1), color));
            this->vertices.push_back( sf::Vertex( sf::Vector2f(xOffset + this->mapSize - 1, yOffset + 1), color));
        }
    }
}

Map::Map()
{
    initVariables();
    initMap();
}
Map::~Map()
{
    
}

sf::Vector2f Map::getXY()
{
    return sf::Vector2f(this->mapX, this->mapY);
}

int Map::getSize()
{
    return this->mapSize;
}

std::array<int, 64> Map::getMap()
{
    return this->map;
}

void Map::update()
{
    
}

void Map::render(sf::RenderTarget *target)
{
    target->draw(&this->vertices[0], this->vertices.size(), sf::Quads);
}
