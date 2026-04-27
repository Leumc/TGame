#include "Cursor.hpp"

Cursor::Cursor(sf::Vector2f& displayPos):m_displayPos(displayPos){}

void Cursor::draw(sf::RenderTarget& target,sf::RenderStates states)const{
    sf::RectangleShape row_rect(sf::Vector2f(3,9));
    row_rect.setFillColor(sf::Color::White);
    row_rect.setPosition(m_displayPos.x,m_displayPos.y);
    sf::RectangleShape col_rect(sf::Vector2f(9,3));
    col_rect.setFillColor(sf::Color::White);
    col_rect.setPosition(m_displayPos.x,m_displayPos.y);
    target.draw(row_rect);
    target.draw(col_rect);
}