#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>

#include "ship.h"
#include "shot.h"


class Engine
{
public:
    static Engine& get();

    void init();

    void update(sf::RenderWindow& window, float frameDelta);

    void addShot(const sf::Vector2f& position, const sf::Vector2f& direction);


private:
    Engine() = default;
    virtual ~Engine() = default;

    Engine(const Engine&) = delete;
    Engine& operator= (const Engine&) = delete;

    std::vector<std::unique_ptr<Ship>> _ships;
    std::vector<std::unique_ptr<Shot>> _shots;

};