#pragma once 

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"


namespace FBC
{
  
  class MainMenuState : public State
  {
      public:
         MainMenuState(GameDataRef data);
         virtual void Init() ;
         virtual void HandleInput();
         virtual void Update(float dt) ;
         virtual void Draw( float dt);
       
       private:
         GameDataRef _data;
   
         sf::Sprite _background;
         sf::Sprite _Playbutton;
         sf::Sprite _title;
  };


}