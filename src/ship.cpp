#include "ship.h"


void Ship::update(sf::RenderWindow& window)
{
    //default shape
    sf::ConvexShape shape(3);
    shape.setPoint(0,sf::Vector2f (5,0));
    shape.setPoint(1,sf::Vector2f (-4,-4));
    shape.setPoint(2,sf::Vector2f (-4,4));

    shape.setOutlineColor(sf::Color::Red);
    shape.setOutlineThickness(1);

    shape.setScale(5,5);

    

    shape.setPosition(_position);
    // set the shape color to green
    shape.setFillColor(sf::Color(100, 50, 250));

    window.draw(shape);
}