#include "Player.hpp"
#include "../math.hpp"

Player::Player(sf::Vector2f& playerPos,Timer& shootTimer,float& rotationAngle):m_shootTimer(shootTimer),m_globalPos(playerPos),m_rotationAngle(rotationAngle){}

//void Player::move(sf::Vector2f direction){
//     if(m_moveTimer.isDone()){
//         m_globalPos+=direction;
//         m_moveTimer.restart();
//     }
//     else return;
// }

void Player::draw(sf::RenderTarget& target,sf::RenderStates states)const{
    float length=50-10*(1.0f-easeOut(m_shootTimer.getPassedTime(),0.1f));
    sf::RectangleShape main_body(sf::Vector2f(length,31));
    main_body.setFillColor(sf::Color::White);
    main_body.setPosition(m_globalPos);
    main_body.setOrigin(length,16);
    main_body.setRotation(m_rotationAngle);
    sf::RectangleShape extend_body(sf::Vector2f(length+50,11));
    extend_body.setFillColor(sf::Color::White);
    extend_body.setPosition(m_globalPos);
    extend_body.setOrigin(length+50,6);
    extend_body.setRotation(m_rotationAngle);
    sf::CircleShape circle(30);
    circle.setPosition(m_globalPos.x-30,m_globalPos.y-30);
    sf::CircleShape c1(15.5);
    c1.setPosition(m_globalPos);
    c1.setOrigin(length+10,16);
    c1.setRotation(m_rotationAngle);
    sf::CircleShape out_circle(35);
    out_circle.setPosition(m_globalPos.x-35,m_globalPos.y-35);
    out_circle.setFillColor(sf::Color::Transparent);
    out_circle.setOutlineThickness(3);
    out_circle.setOutlineColor(sf::Color::White);
    sf::RectangleShape ul(sf::Vector2f(85,7));
    ul.setOrigin(65,60);
    ul.setRotation(m_rotationAngle-20);
    ul.setPosition(m_globalPos);
    sf::RectangleShape ur(sf::Vector2f(85,7));
    ur.setOrigin(65,-55);
    ur.setRotation(m_rotationAngle+20);
    ur.setPosition(m_globalPos);
    target.draw(ul);
    target.draw(ur);
    target.draw(extend_body);
    target.draw(main_body);
    target.draw(circle);
    target.draw(out_circle);
    target.draw(c1);
}