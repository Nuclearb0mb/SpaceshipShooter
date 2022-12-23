#include <SFML/Graphics.hpp>

class Shot
{
public:
    explicit Shot(const sf::Vector2f& direction);
    virtual ~Shot() = default;

    Shot(const Shot&) = delete;
    Shot& operator= (const Shot&) = delete;

    void update (sf::RenderWindow& window, float frameDelta);

private:
    void updatePosition(float frameDelta);

    sf::Vector2f _position {100.0f,100.0f};
    sf::CircleShape _shape {10.0f};

    sf::Vector2f _direction {0.0f,0.0f};
    float _speed {150};
};