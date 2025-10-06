#ifndef PHYSICS_H
#define PHYSICS_H

#include "core/GameObject.h"
#include <vector>

class Physics {
public:
    static void update(std::vector<GameObject*>& objects, float deltaTime);
    static bool checkCollision(const GameObject* a, const GameObject* b);
    static void resolveCollision(GameObject* a, GameObject* b);  // e.g., reverse velocity
};

#endif
