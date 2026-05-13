#pragma once

#include <SFML/Graphics.hpp>
#include "../structs.hpp"
#include "../system/ResourceManager.hpp"

class Enemy:public sf::Drawable,public Resource{
    private:
    float m_health,m_attack;
    sf::Vector2f m_globalPos;
    sf::Clock m_clock;
    float m_speedTimes=100;
    float m_lastTime=0;
    public:
    Enemy(float health,float attack,sf::Vector2f originalPos,ResourceManager* manager);
    virtual void draw(sf::RenderTarget& target,sf::RenderStates states)const override;
    virtual void damage(float value);
    virtual void attack(float value);
    virtual void move(sf::Vector2f targetPos);
    virtual bool isCollapse(sf::Vector2f detectPos);
    bool isDead();
};