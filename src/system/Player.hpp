#include <SFML/Graphics.hpp>
#include "../structs.hpp"

class Player:public sf::Drawable{
    private:
    sf::Vector2f& m_globalPos;
    float& m_rotationAngle;
    Timer& m_shootTimer;
    public:
    Player(sf::Vector2f& playerPos,Timer& shootTimer,float& rotationAngle);
    virtual void draw(sf::RenderTarget& target,sf::RenderStates states)const override;
    //void move(sf::Vector2f direction);
};