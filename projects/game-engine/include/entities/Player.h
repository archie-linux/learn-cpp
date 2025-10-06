#ifndef PLAYER_H
#define PLAYER_H

#include "core/GameObject.h"

class Player : public GameObject {
public:
    Player(sf::Vector2f position);
    void update(float deltaTime) override;
};

#endif
