#pragma once

#include <SFML/Graphics.hpp>
#include <vector>



class Map
{
public:

    Map();
    virtual ~Map() = default;

    Map(const Map&) = delete;
    Map& operator= (const Map&) = delete;

    void update (sf::RenderWindow& window, float frameDelta);


private:
    enum class Material
    {
        air,
        ground
    };
    
    //  ----------- FUNCTIONS ----------
    //  -----------Generating functions-------------
    void generateDefaultTexture();
    void generateDefaultTerrainMaterials();
    void generateTextureFromTerrain();

    //  -----------Helper functions-------------
    sf::Color getMaterialColor(Material material);
    void updateDrawableRectangle();

    //  ---------- Variables and Constants ----------
    //  -----------Drawing and texture------------
    sf::RectangleShape _drawableRectangle{};
    sf::Texture _texture;
    const int _defaultTextureSize = 100;

    //  -----------Terrain-----------
    int _defaultTerrainSize = 1000;             // in pixels
    int _terrainBorderWidth = 100;
    std::vector<std::vector<Material>> _terrainMaterials;                   // information of terrain type for every pixel, stored in material per pixel
};