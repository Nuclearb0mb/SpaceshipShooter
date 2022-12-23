#pragma once

#include <SFML/Graphics.hpp>


class Ship
{
public:

    Ship();
    virtual ~Ship() = default;

    Ship(const Ship&) = delete;
    Ship& operator= (const Ship&) = delete;

    void update (sf::RenderWindow& window, float frameDelta);



private:
    void createShipShape();

    void handleInputs(float frameDelta);
    void handleRotationInput(float frameDelta);
    void handleMovementInput(float frameDelta);


    sf::Vector2f _position {100.0f,100.0f};
    sf::ConvexShape _shape{3};
    float _rotation {0};
    

};