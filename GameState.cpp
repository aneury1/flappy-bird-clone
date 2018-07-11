
#include "GameState.hpp"
#include <sstream>
#include <iostream>
#include "def.hpp"
#include "GameOverState.hpp"
#include "Pipes.hpp"




namespace FBC
{
GameState::GameState(GameDataRef data):State(),_data(data)
{


}
void GameState::Init()
{
    _data->assets.LoadTexture("Main Menu Background", MAIN_MENU_BACKGROUND);
    _data->assets.LoadTexture("pipeup", PIPE_UP);
    _data->assets.LoadTexture("pipedown", PIPE_DOWN);
    _background.setTexture(_data->assets.GetTexture("Main Menu Background"));
     pipes = new Pipe(_data); 

}

void GameState::HandleInput()
{
     sf::Event event;
     while(_data->window.pollEvent(event))
     {
         if(sf::Event::Closed == event.type)
         {
                _data->machine.AddState(StateRef(new GameOverState(_data)),true);
         }
         if( _data->input.IsSpriteClicked(_background, sf::Mouse::Left, _data->window) )
         {
              pipes->SpawnInvisiblePipe();
              pipes->SpawnBottomPipe();
              pipes->SpawnTopPie();
         }
     }
}

void GameState::Update(float dt) 
{
    pipes->MovePipes( dt );
}
void GameState::Draw( float dt)
{
    _data->window.clear();
    _data->window.draw(_background);
     pipes->DrawPipes();
    _data->window.display();
}

}