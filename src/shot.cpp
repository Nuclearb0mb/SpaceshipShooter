#include "shot.h"

Shot::Shot(const sf::Vector2f& direction):_direction (direction)
{    
    _shape.setFillColor(sf::Color::Red);
}

void Shot::update(sf::RenderWindow &window, float frameDelta)
{
    updatePosition(frameDelta);
    window.draw(_shape);
}


void Shot::updatePosition(float frameDelta)
{    
    _position += _direction * _speed * frameDelta; 
    _shape.setPosition(_position);
}
