#include "BulletManager.hpp"

BulletManager::BulletManager(){}

void BulletManager::createBullet(sf::Vector2f originalPos,sf::Vector2f speed,float rotationAngle){
    m_bullets.push_back(std::make_unique<Bullet>(originalPos,speed,rotationAngle));
}