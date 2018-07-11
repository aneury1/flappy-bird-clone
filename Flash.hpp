#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include "Game.hpp"
#include "def.hpp"


namespace FBC
{

class Flash
{

   GameDataRef _data;
   
   sf::RectangleShape _shape;
 
   bool _flashOn;

  public:
   
   Flash(GameDataRef data);

   void show(float dt);

   void draw();

};

}