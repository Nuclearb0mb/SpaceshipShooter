#include <vector>

#include "map.h"

Map::Map()
{
    generateDefaultTexture();
    _drawableRectangle.setTexture(&_texture, true);

    _drawableRectangle.setSize(sf::Vector2f(_defaultTextureSize,_defaultTextureSize));
    _drawableRectangle.setPosition(sf::Vector2f(200.0f, 200.0f));
}

void Map::update(sf::RenderWindow &window, float frameDelta)
{
    window.draw(_drawableRectangle);

}

void Map::generateDefaultTexture()
{   

    sf::Image image;
    image.create(_defaultTextureSize, _defaultTextureSize, sf::Color::Green);
    
    _texture.loadFromImage(image);  

}
