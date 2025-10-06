#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <SFML/Graphics.hpp>
#include <string>

class GameObject {
public:
    GameObject(const std::string& texturePath, sf::Vector2f position);
    virtual ~GameObject() = default;

    virtual void update(float deltaTime) = 0;  // Pure virtual: Subclasses must implement
    void draw(sf::RenderWindow& window);

    sf::FloatRect getBounds() const;  // For collision detection
    void setVelocity(sf::Vector2f vel) { velocity = vel; }

protected:
    sf::Sprite sprite;
    sf::Texture texture;
    sf::Vector2f position;
    sf::Vector2f velocity;
};

#endif
