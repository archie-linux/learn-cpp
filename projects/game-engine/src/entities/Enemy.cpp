#include "entities/Enemy.h"

Enemy::Enemy(sf::Vector2f position, GameObject* tgt) : GameObject("assets/paddle.png", position), target(tgt) {}

void Enemy::update(float deltaTime) {
    // Simple AI: Move towards target's Y position
    if (target && position.y < target->getBounds().top) {
        position.y += 150.f * deltaTime;
    } else if (target && position.y > target->getBounds().top) {
        position.y -= 150.f * deltaTime;
    }
    sprite.setPosition(position);
}
