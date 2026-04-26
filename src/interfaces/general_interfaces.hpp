#include <SFML/Graphics.hpp>

#pragma once

class BasicAttributes {
  private:
    sf::Vector2f m_global_pos;

  public:
    void setGlobalPos(float x, float y);
    void setGlobalPos(sf::Vector2f globalPos);
    sf::Vector2f getGlobalPos();
};