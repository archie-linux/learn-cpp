#include <iostream>
#include <vector>
#include <memory>
#include <string>

// Abstract base class for all game entities
class GameEntity {
protected:
    std::string m_name;
    double m_x, m_y;
    int m_health;
    bool m_isActive;

public:
    GameEntity(const std::string& name, double x = 0.0, double y = 0.0, int health = 100)
        : m_name{name}, m_x{x}, m_y{y}, m_health{health}, m_isActive{true} {}
    
    virtual ~GameEntity() = default;
    
    // Non-virtual interface
    const std::string& getName() const { return m_name; }
    double getX() const { return m_x; }
    double getY() const { return m_y; }
    int getHealth() const { return m_health; }
    bool isActive() const { return m_isActive; }
    bool isAlive() const { return m_health > 0; }
    
    void setPosition(double x, double y) { m_x = x; m_y = y; }
    void setActive(bool active) { m_isActive = active; }
    
    // Virtual interface - polymorphic behavior
    virtual void update(double deltaTime) = 0;  // Pure virtual
    virtual void render() const = 0;            // Pure virtual
    virtual void takeDamage(int damage) {       // Virtual with default implementation
        m_health -= damage;
        if (m_health <= 0) {
            m_health = 0;
            m_isActive = false;
            onDeath();
        }
    }
    
    virtual void onDeath() {
        std::cout << m_name << " has died!\n";
    }
    
    virtual void displayStats() const {
        std::cout << m_name << " at (" << m_x << ", " << m_y 
                  << ") Health: " << m_health << '\n';
    }
};

class Player : public GameEntity {
private:
    int m_score;
    double m_speed;
    int m_ammo;

public:
    Player(const std::string& name, double x = 0.0, double y = 0.0)
        : GameEntity{name, x, y, 100}, m_score{0}, m_speed{5.0}, m_ammo{30} {}
    
    int getScore() const { return m_score; }
    int getAmmo() const { return m_ammo; }
    
    void addScore(int points) { m_score += points; }
    
    void reload() { 
        m_ammo = 30; 
        std::cout << m_name << " reloaded! Ammo: " << m_ammo << '\n';
    }
    
    bool shoot() {
        if (m_ammo > 0) {
            --m_ammo;
            std::cout << m_name << " shoots! Ammo remaining: " << m_ammo << '\n';
            return true;
        }
        std::cout << m_name << " is out of ammo!\n";
        return false;
    }
    
    // Override virtual functions
    void update(double deltaTime) override {
        // Player movement logic (simplified)
        // In real game, would handle input here
        std::cout << m_name << " player update (deltaTime: " << deltaTime << ")\n";
    }
    
    void render() const override {
        std::cout << "Rendering player " << m_name << " at (" << m_x << ", " << m_y << ")\n";
    }
    
    void takeDamage(int damage) override {
        std::cout << m_name << " takes " << damage << " damage!\n";
        GameEntity::takeDamage(damage);  // Call base implementation
    }
    
    void onDeath() override {
        std::cout << "GAME OVER! " << m_name << " died with score: " << m_score << '\n';
    }
    
    void displayStats() const override {
        GameEntity::displayStats();
        std::cout << "  Score: " << m_score << ", Ammo: " << m_ammo << '\n';
    }
};

class Enemy : public GameEntity {
private:
    double m_speed;
    int m_damage;
    double m_attackRange;
    GameEntity* m_target;

public:
    Enemy(const std::string& name, double x, double y, int health = 50, 
          int damage = 10, double attackRange = 2.0)
        : GameEntity{name, x, y, health}, m_speed{2.0}, m_damage{damage}, 
          m_attackRange{attackRange}, m_target{nullptr} {}
    
    void setTarget(GameEntity* target) { m_target = target; }
    int getDamage() const { return m_damage; }
    
    double distanceToTarget() const {
        if (!m_target) return std::numeric_limits<double>::max();
        double dx = m_target->getX() - m_x;
        double dy = m_target->getY() - m_y;
        return std::sqrt(dx * dx + dy * dy);
    }
    
    bool canAttackTarget() const {
        return m_target && m_target->isAlive() && distanceToTarget() <= m_attackRange;
    }
    
    void update(double deltaTime) override {
        if (!m_target || !m_target->isAlive()) {
            std::cout << m_name << " has no target\n";
            return;
        }
        
        double distance = distanceToTarget();
        
        if (distance <= m_attackRange) {
            // Attack target
            std::cout << m_name << " attacks " << m_target->getName() << "!\n";
            m_target->takeDamage(m_damage);
        } else {
            // Move towards target (simplified)
            double dx = m_target->getX() - m_x;
            double dy = m_target->getY() - m_y;
            double length = std::sqrt(dx * dx + dy * dy);
            
            if (length > 0) {
                dx /= length;  // Normalize
                dy /= length;
                
                m_x += dx * m_speed * deltaTime;
                m_y += dy * m_speed * deltaTime;
                
                std::cout << m_name << " moves toward " << m_target->getName() 
                          << " to (" << m_x << ", " << m_y << ")\n";
            }
        }
    }
    
    void render() const override {
        std::cout << "Rendering enemy " << m_name << " at (" << m_x << ", " << m_y << ")\n";
    }
    
    void onDeath() override {
        std::cout << m_name << " enemy defeated!\n";
        if (m_target) {
            // Give points to player if target is player
            Player* player = dynamic_cast<Player*>(m_target);
            if (player) {
                player->addScore(100);
                std::cout << "Player gained 100 points!\n";
            }
        }
    }
};

class PowerUp : public GameEntity {
private:
    std::string m_powerType;
    int m_value;

public:
    PowerUp(const std::string& powerType, double x, double y, int value = 50)
        : GameEntity{"PowerUp", x, y, 1}, m_powerType{powerType}, m_value{value} {}
    
    const std::string& getPowerType() const { return m_powerType; }
    int getValue() const { return m_value; }
    
    void applyTo(Player* player) {
        if (m_powerType == "Health") {
            // Heal player (would need to add healing method to GameEntity)
            std::cout << "Health powerup applied to " << player->getName() << "!\n";
        } else if (m_powerType == "Ammo") {
            player->reload();
            std::cout << "Ammo powerup applied to " << player->getName() << "!\n";
        } else if (m_powerType == "Score") {
            player->addScore(m_value);
            std::cout << "Score powerup +" << m_value << " applied to " 
                      << player->getName() << "!\n";
        }
        m_isActive = false;  // Consumed
    }
    
    void update(double deltaTime) override {
        // Simple floating animation
        static double time = 0;
        time += deltaTime;
        std::cout << m_powerType << " powerup floating (time: " << time << ")\n";
    }
    
    void render() const override {
        std::cout << "Rendering " << m_powerType << " powerup at (" 
                  << m_x << ", " << m_y << ")\n";
    }
};

// Game engine that manages entities polymorphically
class GameEngine {
private:
    std::vector<std::unique_ptr<GameEntity>> m_entities;

public:
    void addEntity(std::unique_ptr<GameEntity> entity) {
        m_entities.push_back(std::move(entity));
    }
    
    void update(double deltaTime) {
        std::cout << "=== Game Update (deltaTime: " << deltaTime << ") ===\n";
        
        // Update all entities polymorphically
        for (auto& entity : m_entities) {
            if (entity->isActive()) {
                entity->update(deltaTime);
            }
        }
        
        // Remove inactive entities
        m_entities.erase(
            std::remove_if(m_entities.begin(), m_entities.end(),
                [](const std::unique_ptr<GameEntity>& entity) {
                    return !entity->isActive();
                }),
            m_entities.end()
        );
    }
    
    void render() {
        std::cout << "=== Game Render ===\n";
        for (const auto& entity : m_entities) {
            if (entity->isActive()) {
                entity->render();
            }
        }
    }
    
    void displayAll

# Chapters 19-23: Templates, Operator Overloading & Advanced C++ Features

## Building Advanced C++ Applications: Generic Programming and Custom Operators

Having mastered the fundamentals of C++ and object-oriented programming, we now venture into advanced territories that make C++ truly powerful: **templates** for generic programming, **operator overloading** for intuitive class interfaces, and advanced **object-oriented techniques**. These features enable you to write flexible, reusable, and elegant code that forms the backbone of professional C++ applications.

---

## Chapter 19: Function Templates and Generic Programming

### 19.1 - Introduction to Function Templates

#### The Problem: Code Duplication

Consider these similar functions for finding the maximum of two values:

```cpp
// Separate functions for each type - lots of duplication!
int max(int a, int b) 
{
    return (a > b) ? a : b;
}

double max(double a, double b) 
{
    return (a > b) ? a : b;
}

std::string max(const std::string& a, const std::string& b) 
{
    return (a > b) ? a : b;
}
// ... and so on for every type we want to support
