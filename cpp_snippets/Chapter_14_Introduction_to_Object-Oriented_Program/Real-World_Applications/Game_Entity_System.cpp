// GameEntity.h
#ifndef GAME_ENTITY_H
#define GAME_ENTITY_H

#include <string>

class GameEntity {
private:
    static int s_nextId;
    
    int m_id;
    std::string m_name;
    double m_x, m_y;
    int m_health;
    int m_maxHealth;
    bool m_isActive;

public:
    // Constructors
    GameEntity(const std::string& name, double x = 0.0, double y = 0.0, int maxHealth = 100);
    ~GameEntity();
    
    // Accessors
    int getId() const { return m_id; }
    const std::string& getName() const { return m_name; }
    double getX() const { return m_x; }
    double getY() const { return m_y; }
    int getHealth() const { return m_health; }
    int getMaxHealth() const { return m_maxHealth; }
    bool isActive() const { return m_isActive; }
    bool isAlive() const { return m_health > 0; }
    
    // Mutators
    void setPosition(double x, double y);
    void move(double deltaX, double deltaY);
    void takeDamage(int damage);
    void heal(int amount);
    void setActive(bool active) { m_isActive = active; }
    
    // Utility functions
    double distanceTo(const GameEntity& other) const;
    void displayStatus() const;
    
    // Static function
    static int getTotalEntities() { return s_nextId - 1; }
};

#endif
