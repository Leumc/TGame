#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>
#include "../enemies/enemy.hpp"
#include "BulletManager.hpp"

class Enemy;

class EnemyManager:public sf::Drawable{
    private:
    std::vector<std::shared_ptr<Enemy>> m_enemies;
    sf::Vector2f& m_playerPos;
    ResourceManager* m_resource_manager;
    public:
    EnemyManager(sf::Vector2f& playerPos,ResourceManager* manager);
    virtual void draw(sf::RenderTarget& target,sf::RenderStates states)const override;
    void createEnemy(float health,float attack,sf::Vector2f originalPos);
    void moveEnemy();
};