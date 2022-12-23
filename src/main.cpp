#include <SFML/Graphics.hpp>
#include <chrono>
#include <thread>

#include "ship.h"
#include "shot.h"
#include "engine.h"

int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

    Engine::get().init();

    auto lastFrameTimePoint = std::chrono::steady_clock::now();
    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // clear the window with black color
        window.clear(sf::Color::Black);
        window.setFramerateLimit(60);
        // draw everything here...
        // window.draw(...);

        sf::CircleShape shape(50.f);

        // set the shape color to green
        shape.setFillColor(sf::Color(100, 250, 50));

        window.draw(shape);

        // entity updates
        const auto now = std::chrono::steady_clock::now();
        const float frameDelta = std::chrono::duration<float>(now-lastFrameTimePoint).count();
        lastFrameTimePoint = now;

        Engine::get().update(window, frameDelta);

        
        // end the current frame
        window.display();
    }

    return 0;
}