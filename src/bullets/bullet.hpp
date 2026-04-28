#include <SFML/Graphics.hpp>

class Bullet:public sf::Drawable{
    private:
    sf::Vector2f m_pos;
    sf::Vector2f m_speed;
    sf::Clock m_clock;
    float m_lastTime=0;
    float m_rotationAngle;
    float m_speedTimes=1000;
    public:
    Bullet(sf::Vector2f originalPos,sf::Vector2f speed,float rotationAngle);
    virtual void draw(sf::RenderTarget& target,sf::RenderStates states)const override;
    virtual void move();
    sf::Vector2f getPos();
};