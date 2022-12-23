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
    for (auto& ship : _ships)
    {
        ship->update(window, frameDelta);
    }
}
