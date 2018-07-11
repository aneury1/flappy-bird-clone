
#include "SplashState.hpp"
#include <sstream>
#include <iostream>
#include "def.hpp"

#include "MainMenuState.hpp"




namespace FBC
{
SplashState::SplashState(GameDataRef data):State(),_data(data)
{


}
void SplashState::Init()
{
    _data->assets.LoadTexture("Splash State Background",SPLASH_SCENE_BG_PATH);
    _backgrund.setTexture(_data->assets.GetTexture("Splash State Background"));
}

void SplashState::HandleInput()
{
     sf::Event event;
     while(_data->window.pollEvent(event))
     {
         if(sf::Event::Closed == event.type)
         {
             std::cout <<"Cerrando...";
             _data->window.close();
         }
     }

}
void SplashState::Update(float dt) 
{
  if(_clock.getElapsedTime().asSeconds() > SPLASH_STATE_SHOW_TIME)
  {
      _data->machine.AddState(StateRef(new MainMenuState(_data)),true);

  }

}
void SplashState::Draw( float dt)
{
    _data->window.clear();
   
    _data->window.draw(_backgrund);
    
    _data->window.display();
}

}