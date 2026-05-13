#pragma once

#include "../bullets/bullet.hpp"
#include <memory>
#include <vector>
#include "../system/ResourceManager.hpp"

class BulletManager:public sf::Drawable{
    private:
    std::vector<std::shared_ptr<Bullet>> m_bullets;
    sf::Vector2f& m_windowSize;
    ResourceManager* m_resource_manager;
    public:
    BulletManager(sf::Vector2f& windowSize,ResourceManager* resourceManager);
    void createBullet(sf::Vector2f originalPos,sf::Vector2f speed,float rotationAngle);
    void moveBullet();
    virtual void draw(sf::RenderTarget& target,sf::RenderStates states)const override;
};