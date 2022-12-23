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

    std::unique_ptr<Shot> testShot1 = std::make_unique<Shot>(sf::Vector2f(1.0, 0.0));
    _shots.emplace_back(std::move(testShot1));     
}

void Engine::update(sf::RenderWindow &window, float frameDelta)
{
    for (auto& ship : _ships)
    {
        ship->update(window, frameDelta);
    }

    for (auto& shot : _shots)
    {
        shot->update(window, frameDelta);
    }
}
