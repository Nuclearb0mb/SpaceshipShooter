#include <vector>

#include "map.h"
#include "iostream"

Map::Map()
{
    generateDefaultTexture();
    
    _drawableRectangle.setTexture(&_texture, true);

    _drawableRectangle.setSize(sf::Vector2f(_defaultTextureSize,_defaultTextureSize));
    _drawableRectangle.setPosition(sf::Vector2f(0.0f, 0.0f));
    
    generateDefaultTerrainMaterials();
    generateTextureFromTerrain();

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

void Map::generateDefaultTerrainMaterials()
{
    
    // generating terrain border
    for (int y = 0; y < _defaultTerrainSize; y++)
    {
        std::vector<Material> terrainMaterialsX;
        for (int x = 0; x < _defaultTerrainSize; x++)
        {
            
            // coordinates inside bordered box
            if (((x > _terrainBorderWidth) && (y > _terrainBorderWidth)) && ((x < (_defaultTerrainSize - _terrainBorderWidth )) && (y < (_defaultTerrainSize - _terrainBorderWidth ))))
            {
                terrainMaterialsX.emplace_back(Material::air);
            }
            // coordinates of border area
            else
            {
                terrainMaterialsX.emplace_back(Material::ground);
            }
        
        }
        _terrainMaterials.emplace_back(std::move(terrainMaterialsX));
    }
}

void Map::generateTextureFromTerrain()      // Generates texture and updates drawableRectangle, may break when generating large textures
{
    // Generating image
    sf::Image textureImage;

    textureImage.create(_terrainMaterials.size(), _terrainMaterials.size(), sf::Color::Black);

    int pixelIteratorX = 0;
    int pixelIteratorY = 0;

    for (auto xLine : _terrainMaterials)
    {
        for ( Material material : xLine)
        {
            if (pixelIteratorX < textureImage.getSize().x)
            {   
                if (pixelIteratorY < textureImage.getSize().y)
                {
                textureImage.setPixel(pixelIteratorX, pixelIteratorY, getMaterialColor(material));
                
                }
                else std::cout << "Terrain generation pixelIteratorY out of range!\n";
            }
            else std::cout << "Terrain generation pixelIteratorX out of range!\n";

            pixelIteratorX++;
        }
        pixelIteratorX = 0;
        pixelIteratorY++;
    }

    _texture.create(textureImage.getSize().x, textureImage.getSize().y);
    _texture.update(textureImage);
    updateDrawableRectangle();
}

sf::Color Map::getMaterialColor(Material material)
{
    switch (material)
    {
    case Material::ground:
        return sf::Color::Green;
        break;
    case Material::air:
    default:
        return sf::Color::Black;
        break;
    }    
}

void Map::updateDrawableRectangle()
{
    _drawableRectangle.setSize(static_cast<sf::Vector2f>(_texture.getSize()));
    _drawableRectangle.setTextureRect(sf::IntRect(sf::Vector2i(0,0), static_cast<sf::Vector2i>(_texture.getSize())));
}
