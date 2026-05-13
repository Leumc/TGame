#include <SFML/Graphics.hpp>

inline sf::Vector2i f2i(sf::Vector2f source){
    return sf::Vector2i((int)source.x,(int)source.y);
}