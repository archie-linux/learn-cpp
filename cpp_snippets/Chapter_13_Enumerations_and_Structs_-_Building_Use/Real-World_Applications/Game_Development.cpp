enum class EntityType { Player, Enemy, Projectile, Powerup };

struct GameObject 
{
    EntityType type;
    double x{}, y{};
    double velocityX{}, velocityY{};
    int health = 100;
    bool isActive = true;
    
    void update(double deltaTime) 
    {
        x += velocityX * deltaTime;
        y += velocityY * deltaTime;
    }
};
