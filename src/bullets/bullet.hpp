#pragma once

#include <SFML/Graphics.hpp>
#include "../system/CollisionMap.hpp"
#include "../system/ResourceManager.hpp"

class MapInsert;

class Bullet:public sf::Drawable,public Resource{
    private:
    sf::Vector2f m_pos;
    sf::Vector2f m_speed;
    sf::Clock m_clock;
    float m_lastTime=0;
    float m_rotationAngle;
    float m_speedTimes=1000;
    MapInsert* interface_mapInsert;
    public:
    Bullet(sf::Vector2f originalPos,sf::Vector2f speed,float rotationAngle,ResourceManager* manager);
    virtual void draw(sf::RenderTarget& target,sf::RenderStates states)const override;
    virtual void move();
    sf::Vector2f getPos();
};