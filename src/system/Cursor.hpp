#include <SFML/Graphics.hpp>
class Cursor:public sf::Drawable{
    private:
    sf::Vector2f& m_displayPos;
    public:
    Cursor(sf::Vector2f& displayPos);
    virtual void draw(sf::RenderTarget& target,sf::RenderStates states)const override;
};