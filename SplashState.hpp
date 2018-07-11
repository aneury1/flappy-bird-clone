#pragma once 

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"


namespace FBC
{
  
  class SplashState : public State
  {
      public:
         SplashState(GameDataRef data);
         virtual void Init() ;
         virtual void HandleInput();
         virtual void Update(float dt) ;
         virtual void Draw( float dt);
       
       private:
         GameDataRef _data;
         sf::Clock _clock;
         
         sf::Texture _backgroundTexture;
         sf::Sprite _backgrund;
  };


}