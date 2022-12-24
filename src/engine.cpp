#include "engine.h"


Engine& Engine::get()
{
    static Engine engine;
    return engine;
}

void Engine::init()
{
    std::unique_ptr<Ship> player1 = std::make_unique<Ship>();
    _ships.emplace_back(std::move(player1));   
}

void Engine::update(sf::RenderWindow &window, float frameDelta)
{
    _map.update(window, frameDelta);
    
    for (auto& ship : _ships)
    {
        ship->update(window, frameDelta);
    }

    for (auto& shot : _shots)
    {
        shot->update(window, frameDelta);
    }
}

void Engine::addShot(const sf::Vector2f& position, const sf::Vector2f& direction)
{
    _shots.emplace_back(std::make_unique<Shot>(position, direction));
}
