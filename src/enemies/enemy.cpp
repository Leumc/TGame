#include "enemy.hpp"
#include "../math.hpp"

Enemy::Enemy(float health,float attack,sf::Vector2f originalPos,ResourceManager*manager):Resource(manager,ResourceType::ENEMY){
    m_health=health;
    m_attack=attack;
    m_globalPos=originalPos;
    m_clock.restart();
}

void Enemy::damage(float value){
    m_health-=value;
}

void Enemy::attack(float value){
    
}

void Enemy::draw(sf::RenderTarget& target,sf::RenderStates states)const{
    sf::RectangleShape rect(sf::Vector2f(31,31));
    rect.setFillColor(sf::Color::White);
    rect.setPosition(m_globalPos);
    rect.setOrigin(16,16);
    target.draw(rect);
}

bool Enemy::isDead(){
    return m_health<0;
}

void Enemy::move(sf::Vector2f targetPos){
    float cosf,sinf;
    angleBetween(m_globalPos,targetPos,cosf,sinf);
    float current=m_clock.getElapsedTime().asSeconds();
    m_globalPos+=m_speedTimes*(current-m_lastTime)*sf::Vector2f(cosf,sinf);
    m_lastTime=current;
}

bool Enemy::isCollapse(sf::Vector2f detectPos){
    return abs(detectPos.x-m_globalPos.x)<=15||abs(detectPos.y-m_globalPos.y)<=15;
}