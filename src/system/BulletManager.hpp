#include "../bullets/bullet.hpp"
#include <memory>
#include <vector>

class BulletManager{
    private:
    std::vector<std::unique_ptr<Bullet>> m_bullets;
    public:
    BulletManager();
    void createBullet(sf::Vector2f originalPos,sf::Vector2f speed,float rotationAngle);
    void move();
    void releaseBullet();
};