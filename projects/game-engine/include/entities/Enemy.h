#ifndef ENEMY_H
#define ENEMY_H

#include "core/GameObject.h"

class Enemy : public GameObject {
public:
    Enemy(sf::Vector2f position, GameObject* target);  // Tracks a target (e.g., ball)
    void update(float deltaTime) override;

private:
    GameObject* target;
};

#endif
