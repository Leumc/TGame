#include "BulletManager.hpp"

BulletManager::BulletManager(sf::Vector2f& windowSize):m_windowSize(windowSize){}

void BulletManager::createBullet(sf::Vector2f originalPos,sf::Vector2f speed,float rotationAngle){
    m_bullets.push_back(std::make_unique<Bullet>(originalPos,speed,rotationAngle));
}

void BulletManager::moveBullet(){
    auto it=m_bullets.begin();
    while(it!=m_bullets.end()){
        sf::Vector2f bullet_pos=it->get()->getPos();
        if(bullet_pos.x<-30||bullet_pos.y<-30||bullet_pos.x>m_windowSize.x+30||bullet_pos.y>m_windowSize.y+30){
            it->reset();
            it=m_bullets.erase(it);
            continue;
        }
        it->get()->move();
        it++;
    }
}

void BulletManager::draw(sf::RenderTarget& target,sf::RenderStates states) const{
    for(auto& bullet:m_bullets){
        target.draw(*bullet);
    }
}