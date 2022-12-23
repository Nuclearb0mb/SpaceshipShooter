#pragma once

#include <SFML/Graphics.hpp>


class Ship
{
public:

    Ship() = default;
    virtual ~Ship() = default;

    Ship(const Ship&) = delete;
    Ship& operator= (const Ship&) = delete;

    void update (sf::RenderWindow& window);


private:
    sf::Vector2f _position {100.0f,100.0f};
    

};