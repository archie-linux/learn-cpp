#include "physics/Physics.h"

bool Physics::checkCollision(const GameObject* a, const GameObject* b) {
    return a->getBounds().intersects(b->getBounds());
}

void Physics::resolveCollision(GameObject* a, GameObject* b) {
    // Simple response: Reverse X velocity (for ball-paddle collision)
    sf::Vector2f velA = a->getVelocity();
    velA.x = -velA.x;
    a->setVelocity(velA);
}

void Physics::update(std::vector<GameObject*>& objects, float deltaTime) {
    for (auto& obj : objects) {
        obj->position += obj->velocity * deltaTime;
        obj->sprite.setPosition(obj->position);
    }
    // Check pairwise collisions (O(n^2) for simplicity; optimize with spatial partitioning for advanced)
    for (size_t i = 0; i < objects.size(); ++i) {
        for (size_t j = i + 1; j < objects.size(); ++j) {
            if (checkCollision(objects[i], objects[j])) {
                resolveCollision(objects[i], objects[j]);
            }
        }
    }
}
