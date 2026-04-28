#include "../bullets/bullet.hpp"
#include <memory>
#include <vector>

class BulletManager:public sf::Drawable{
    private:
    std::vector<std::unique_ptr<Bullet>> m_bullets;
    sf::Vector2f& m_windowSize;
    public:
    BulletManager(sf::Vector2f& windowSize);
    void createBullet(sf::Vector2f originalPos,sf::Vector2f speed,float rotationAngle);
    void moveBullet();
    virtual void draw(sf::RenderTarget& target,sf::RenderStates states)const override;
};