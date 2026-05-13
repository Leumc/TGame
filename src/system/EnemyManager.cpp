#include "EnemyManager.hpp"

EnemyManager::EnemyManager(sf::Vector2f& playerPos,ResourceManager* manager):m_playerPos(playerPos){
    m_resource_manager=manager;
}

void EnemyManager::createEnemy(float health,float attack,sf::Vector2f originalPos){
    std::shared_ptr<Enemy> enemy=std::make_shared<Enemy>(health,attack,originalPos,m_resource_manager);
    m_enemies.push_back(enemy);
    m_resource_manager->AddResource(std::static_pointer_cast<Resource>(enemy));
}

void EnemyManager::moveEnemy(){
    auto it=m_enemies.begin();
    while(it!=m_enemies.end()){
        if(it->get()->isDead()){
            it->reset();
            it=m_enemies.erase(it);
        }
        it->get()->move(m_playerPos);
        it++;
    }
}

void EnemyManager::draw(sf::RenderTarget& target,sf::RenderStates states)const{
    for(auto& enemy:m_enemies){
        target.draw(*enemy);
    }
}