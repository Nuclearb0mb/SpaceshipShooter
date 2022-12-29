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

            // catch the resize events
            if (event.type == sf::Event::Resized)
            {
                // update the view to the new size of the window
                sf::FloatRect visibleArea(0.0f, 0.0f, static_cast<float>(event.size.width), static_cast<float>(event.size.height));
                window.setView(sf::View(visibleArea));
            }
        }

        // clear the window with black color
        window.clear(sf::Color::Black);
        window.setFramerateLimit(60);


        // entity updates
        const auto now = std::chrono::steady_clock::now();
        const float frameDelta = std::chrono::duration<float>(now-lastFrameTimePoint).count();
        lastFrameTimePoint = now;

        Engine::get().update(window, frameDelta);       // window drawing is in update

        
        // end the current frame
        window.display();
    }

    return 0;
}