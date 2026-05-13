#include "CollisionMap.hpp"
#include <string.h>
#include "../function.hpp"

void CollisionMap::resizeAndClear(){
    m_map=(char**)malloc(m_windowSize.x*sizeof(char*));
    for(int i=0;i<m_windowSize.x;i++){
        m_map[i]=(char*)malloc(m_windowSize.y*sizeof(char));
    }
    memset(m_map,0,sizeof(char)*m_windowSize.x*m_windowSize.y);
}

CollisionMap::CollisionMap(sf::Vector2f windowSize,ResourceManager* resource_manager){
    m_windowSize=windowSize;
    m_resource_manager=resource_manager;
    resizeAndClear();
}

CollisionStates CollisionMap::getStates(sf::Vector2f pos){
    sf::Vector2i pos_i=f2i(pos);
    if(pos_i.x<0||pos_i.y<0||pos_i.x>m_windowSize.x||pos_i.y>m_windowSize.y){
        return CollisionStates::InValid;
    }
    else return static_cast<CollisionStates>(m_map[pos_i.x][pos_i.y]);
}

void CollisionMap::clear(){
    memset(m_map,0,sizeof(char)*m_windowSize.x*m_windowSize.y);
}

void CollisionMap::setStates(sf::Vector2f pos,CollisionStates state){
    sf::Vector2i pos_i=f2i(pos);
    m_map[pos_i.x][pos_i.y]=static_cast<char>(state);
}