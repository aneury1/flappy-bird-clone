
#include "GameOverState.hpp"
#include <sstream>
#include <iostream>
#include "def.hpp"
#include "GameState.hpp"





namespace FBC
{
GameOverState::GameOverState(GameDataRef data):State(),_data(data)
{


}
void GameOverState::Init()
{
    _data->assets.LoadTexture("Gameover Menu Background", GAME_OVER_BACKGROUND);

    _gameOverMsg.setTexture(_data->assets.GetTexture("gameovermsg"));
    _background.setTexture(_data->assets.GetTexture("Gameover Menu Background"));
    _Playbutton.setTexture(_data->assets.GetTexture("Menu playbutton"));
    _gameOverMsg.setPosition(100,100);
    _Playbutton.setPosition(60,_gameOverMsg.getGlobalBounds().height+410);

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
         ///temporal
         if(_data->input.IsSpriteClicked(_Playbutton, sf::Mouse::Left, _data->window))
         {
             _data->machine.AddState(StateRef(new GameState(_data)),true);
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
    _data->window.draw(_gameOverMsg);
    _data->window.draw(_Playbutton);
    _data->window.display();
}

}