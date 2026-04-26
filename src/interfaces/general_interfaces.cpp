#include "general_interfaces.hpp"

void BasicAttributes::setGlobalPos(float x, float y) {
    m_global_pos.x = x;
    m_global_pos.y = y;
}

void BasicAttributes::setGlobalPos(sf::Vector2f globalPos){
    m_global_pos=globalPos;
}

sf::Vector2f BasicAttributes::getGlobalPos(){
    return m_global_pos;
}