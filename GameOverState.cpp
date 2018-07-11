
#include "GameOverState.hpp"
#include <sstream>
#include <iostream>
#include "def.hpp"






namespace FBC
{
GameOverState::GameOverState(GameDataRef data):State(),_data(data)
{


}
void GameOverState::Init()
{
    _data->assets.LoadTexture("Gameover Menu Background", GAME_OVER_BACKGROUND);


    _background.setTexture(_data->assets.GetTexture("Gameover Menu Background"));
 

}

void GameOverState::HandleInput()
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

void GameOverState::Update(float dt) 
{
}
void GameOverState::Draw( float dt)
{
    _data->window.clear();
    _data->window.draw(_background);
  
    _data->window.display();
}

}