#pragma once 

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"
#include "Pipes.hpp"
#include "Land.hpp"
#include "Bird.hpp"
#include "Collision.hpp"
#include "Flash.hpp"


namespace FBC
{
  
  class GameState : public State
  {
      public:
         GameState(GameDataRef data);
         virtual void Init() ;
         virtual void HandleInput();
         virtual void Update(float dt) ;
         virtual void Draw( float dt);
       
       private:
         GameDataRef _data;
        
         sf::Clock clock;
         sf::Sprite _background;
         Pipe *pipes;
         Land *land;
         Bird *bird;
         Flash *flash;
         Collision collision;

         int game_state;
 

  };


}