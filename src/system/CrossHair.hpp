#pragma once

#include "../interfaces/general_interfaces.hpp"
#include <SFML/Graphics.hpp>
#include "../structs.hpp"

// float RELOADING_TIME=0.5f;

class CrossHair : public sf::Drawable {
  protected:
    sf::Vector2f& m_displayPos;
    sf::Color m_color=sf::Color::White;
    Timer& m_execute_timer;
    Timer& m_reloading_timer;
    float m_reloadTime;
    int m_bullets=6;
    int m_max_bullets=6;
    bool m_is_reloading=false;
  public:
  CrossHair(sf::Vector2f& displayPos,Timer& execute_timer,Timer& reloading_timer);
  void display();
  void setColor(sf::Color color);
  virtual void draw(sf::RenderTarget& target,sf::RenderStates states)const override;
  void setReloadingTime(float reload_time){m_reloadTime=reload_time;}
  void reload();
  bool shoot();
  void setReloading(bool is_reloading);
  bool isreloading(){return m_is_reloading;}
};
