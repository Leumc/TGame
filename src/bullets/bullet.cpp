#include "bullet.hpp"

Bullet::Bullet(sf::Vector2f originalPos,sf::Vector2f speed,float rotationAngle){
    m_rotationAngle=rotationAngle;
    m_pos=originalPos;
    m_speed=speed;
    m_clock.restart();
}

void Bullet::draw(sf::RenderTarget& target,sf::RenderStates states)const{
    sf::RectangleShape rect(sf::Vector2f(20,5));
    rect.setFillColor(sf::Color::White);
    rect.setPosition(m_pos);
    rect.setRotation(m_rotationAngle);
    rect.setOrigin(0,3);
    target.draw(rect);
}

void Bullet::move(){
    m_pos+=m_speed*(m_speedTimes*(m_clock.getElapsedTime().asSeconds()-m_lastTime));
    m_lastTime=m_clock.getElapsedTime().asSeconds();
}

sf::Vector2f Bullet::getPos(){
    return m_pos;
}