#pragma once

#include <SFML/Graphics.hpp>
#include "BulletManager.hpp"

enum class CollisionStates:char{
    InValid=-1,
    Empty=0,
    Enemy=1,
    Player=2,
    Bullet=3
};

class MapExtract{
    virtual CollisionStates getStates(sf::Vector2f pos)=0;
};

class MapInsert{
    virtual void setStates(sf::Vector2f pos)=0;
};

class CollisionMap:public sf::Drawable,MapInsert,MapExtract{
    private:
    char** m_map;
    ResourceManager* m_resource_manager;
    sf::Vector2f m_windowSize;
    public:
    CollisionMap(sf::Vector2f windowSize,ResourceManager* resource_manager);
    void resizeAndClear();
    CollisionStates getStates(sf::Vector2f pos);
    void setStates(sf::Vector2f pos,CollisionStates state);
    void clear();
};