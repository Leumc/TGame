#include "CrossHair.hpp"
#include <SFML/Graphics.hpp>
#include "../math.hpp"
#include <algorithm>
#include <iostream>

CrossHair::CrossHair(sf::Vector2f &displayPos,Timer& execute_timer,Timer& reloading_timer) : m_displayPos(displayPos),m_execute_timer(execute_timer),m_reloading_timer(reloading_timer) {
    m_reloadTime=m_reloading_timer.m_duration.asSeconds();
}

void CrossHair::setColor(sf::Color color){
    m_color=color;
}

float easeOut01(Timer& timer) {
    return easeOut(timer.getPassedTime(), 0.15f);
}

void CrossHair::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    float scale=std::max(1.3-easeOut01(m_execute_timer),1.0);
    float rotation=15-15*easeOut01(m_execute_timer);
    sf::CircleShape out_circle(25);
    out_circle.setPosition(m_displayPos.x - 25*scale, m_displayPos.y - 25*scale);
    out_circle.setFillColor(sf::Color::Transparent);
    out_circle.setOutlineThickness(2);
    out_circle.setOutlineColor(m_color);
    out_circle.setScale(scale,scale);
    sf::CircleShape inner_circle(15);
    inner_circle.setPosition(m_displayPos.x - 15*scale, m_displayPos.y - 15*scale);
    inner_circle.setFillColor(sf::Color::Transparent);
    inner_circle.setOutlineThickness(2);
    inner_circle.setOutlineColor(m_color);
    inner_circle.setScale(scale,scale);
    sf::RectangleShape up_rect(sf::Vector2f(2,30));
    up_rect.setFillColor(m_color);
    up_rect.setPosition(m_displayPos.x-1*scale,m_displayPos.y);
    up_rect.setOrigin(1,35);
    up_rect.setRotation(rotation);
    up_rect.setScale(scale,scale);
    sf::RectangleShape down_rect(sf::Vector2f(2,30));
    down_rect.setFillColor(m_color);
    down_rect.setPosition(m_displayPos.x-1*scale,m_displayPos.y);
    down_rect.setOrigin(1,-5);
    down_rect.setRotation(rotation);
    down_rect.setScale(scale,scale);
    sf::RectangleShape left_rect(sf::Vector2f(30,2));
    left_rect.setFillColor(m_color);
    left_rect.setPosition(m_displayPos.x,m_displayPos.y-1*scale);
    left_rect.setOrigin(35,1);
    left_rect.setRotation(rotation);
    left_rect.setScale(scale,scale);
    sf::RectangleShape right_rect(sf::Vector2f(30,2));
    right_rect.setFillColor(m_color);
    right_rect.setPosition(m_displayPos.x,m_displayPos.y-1*scale);
    right_rect.setOrigin(-5,1);
    right_rect.setRotation(rotation);
    right_rect.setScale(scale,scale);
    sf::RectangleShape center(sf::Vector2f(2,2));
    center.setFillColor(m_color);
    center.setPosition(m_displayPos.x-1*scale,m_displayPos.y-1*scale);
    center.setScale(scale,scale);
    sf::RectangleShape bullet_block(sf::Vector2f(40,5));
    bullet_block.setPosition(m_displayPos.x-20,m_displayPos.y-50);
    bullet_block.setOutlineThickness(2);
    bullet_block.setOutlineColor(sf::Color::White);
    bullet_block.setFillColor(sf::Color::Transparent);
    sf::RectangleShape bullet_fill(sf::Vector2f(40,5));
    bullet_fill.setFillColor(sf::Color::White);
    bullet_fill.setPosition(m_displayPos.x-20,m_displayPos.y-50);
    bullet_fill.setSize(sf::Vector2f(40*(1.0*m_bullets/m_max_bullets),5));
    target.draw(bullet_fill);
    target.draw(bullet_block);
    target.draw(out_circle);
    target.draw(inner_circle);
    target.draw(up_rect);
    target.draw(down_rect);
    target.draw(left_rect);
    target.draw(right_rect);
    target.draw(center);
    if(m_is_reloading){
        sf::RectangleShape bullet_reloading(sf::Vector2f(40,2));
        bullet_reloading.setPosition(m_displayPos.x-20,m_displayPos.y-56);
        bullet_reloading.setSize(sf::Vector2f(40*(1.0*m_reloading_timer.getPassedTime()/m_reloadTime),2));
        target.draw(bullet_reloading);
    }
}

bool CrossHair::shoot(){
    if(m_bullets==0)return false;
    else{
        m_bullets-=1;
        return true;
    }
}

void CrossHair::reload(){
    m_bullets=m_max_bullets;
}

void CrossHair::setReloading(bool is_reloading){
    m_is_reloading=is_reloading;
}