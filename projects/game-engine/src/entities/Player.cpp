#include "entities/Player.h"

Player::Player(sf::Vector2f position) : GameObject("assets/paddle.png", position) {}

void Player::update(float deltaTime) {
    // Handle input (e.g., keyboard up/down)
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        position.y -= 200.f * deltaTime;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        position.y += 200.f * deltaTime;
    }
    sprite.setPosition(position);
}
