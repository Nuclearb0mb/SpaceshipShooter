#pragma once

#include <SFML/Graphics.hpp>

class Map
{
public:

    Map();
    virtual ~Map() = default;

    Map(const Map&) = delete;
    Map& operator= (const Map&) = delete;

    void update (sf::RenderWindow& window, float frameDelta);


private:
    void generateDefaultTexture();

    sf::RectangleShape _drawableRectangle{};
    sf::Texture _texture;
    const int _defaultTextureSize = 100;
};