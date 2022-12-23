#include "ship.h"
#include <math.h>
#include <glm/glm.hpp>

Ship::Ship()
{
    createShipShape();
}

void Ship::createShipShape()
{
    //default shape

    _shape.setPointCount(3);
    
    _shape.setPoint(0,sf::Vector2f (5,0));
    _shape.setPoint(1,sf::Vector2f (-4,-4));
    _shape.setPoint(2,sf::Vector2f (-4,4));

    _shape.setOutlineColor(sf::Color::Red);
    _shape.setOutlineThickness(1);

    _shape.setFillColor(sf::Color(100, 50, 250));

    _shape.setScale(5,5);
}

void Ship::handleInputs(float frameDelta)
{
    handleRotationInput(frameDelta);
    handleMovementInput(frameDelta);
}

void Ship::handleRotationInput(float frameDelta)    //TODO timing independent from framerate
{
    static const float ROTATION_SPEED = 120;     // degrees/s
    float rotateAngle = ROTATION_SPEED*frameDelta;

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        _rotation -= rotateAngle;
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        _rotation += rotateAngle;
    }

    _rotation = fmod(_rotation, 360.0f);
}

void Ship::handleMovementInput(float frameDelta)
{    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        _position += getForwardVector() * frameDelta * _speed;
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        _position -= getForwardVector() * frameDelta * _speed;
    }
}

sf::Vector2f Ship::getForwardVector() const
{
    return sf::Vector2f(std::cos(glm::radians(_rotation)), std::sin(glm::radians(_rotation)));
}

void Ship::update(sf::RenderWindow &window, float frameDelta)
{      
    _shape.setPosition(_position);
    _shape.setRotation(_rotation);

    handleInputs(frameDelta);
 
    window.draw(_shape);
}


