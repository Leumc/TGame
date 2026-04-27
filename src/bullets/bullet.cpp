#include "bullet.hpp"

Bullet::Bullet(sf::Vector2f originalPos,sf::Vector2f speed,float rotationAngle){
    m_rotationAngle=rotationAngle;
    m_pos=originalPos;
    m_speed=speed;
    m_clock.restart();
}

void Bullet::draw(sf::RenderTarget& target,sf::RenderStates states)const{
    sf::RectangleShape rect(sf::Vector2f(10,5));
    rect.setFillColor(sf::Color::White);
    rect.setPosition(m_pos);
    rect.setRotation(m_rotationAngle);
    target.draw(rect);
}

void Bullet::move(){
    m_pos+=m_speed*m_clock.getElapsedTime().asSeconds();
}