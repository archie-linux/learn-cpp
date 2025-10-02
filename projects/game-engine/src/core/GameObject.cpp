#include "core/GameObject.h"

GameObject::GameObject(const std::string& texturePath, sf::Vector2f pos) : position(pos), velocity(0.f, 0.f) {
    if (!texture.loadFromFile(texturePath)) {
        // Handle error (e.g., throw exception)
    }
    sprite.setTexture(texture);
    sprite.setPosition(position);
}

sf::FloatRect GameObject::getBounds() const {
    return sprite.getGlobalBounds();
}

void GameObject::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}
