#pragma once
#include <SFML/Graphics.hpp>

namespace FBC
{

class InputManager
{

public:

   bool IsSpriteClicked( sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow &window);
    
   sf::Vector2i getMousePosition(sf::RenderWindow &window);

};



}