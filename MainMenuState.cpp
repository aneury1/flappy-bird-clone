
#include "MainMenuState.hpp"
#include <sstream>
#include <iostream>
#include "def.hpp"
#include "GameState.hpp"





namespace FBC
{
MainMenuState::MainMenuState(GameDataRef data):State(),_data(data)
{


}
void MainMenuState::Init()
{
    _data->assets.LoadTexture("Main Menu Background", MAIN_MENU_BACKGROUND);
    _data->assets.LoadTexture("Menu title", TITLE_SCENE_BG_PATH);
    _data->assets.LoadTexture("Menu playbutton", PLAYBUTTON_PATH);

    _background.setTexture(_data->assets.GetTexture("Main Menu Background"));
    _title.setTexture(_data->assets.GetTexture("Menu title"));
    _Playbutton.setTexture(_data->assets.GetTexture("Menu playbutton"));

    _title.setPosition(((SCREEN_WIDTH / 2 ) -( _title.getGlobalBounds().width/2)), _title.getGlobalBounds().height/2);

    _Playbutton.setPosition(
                          ((SCREEN_WIDTH / 2 ) -( _Playbutton.getGlobalBounds().width/2)),
                          ((SCREEN_HEIGHT / 2 ) -( _Playbutton.getGlobalBounds().height/2))
                             );


}

void MainMenuState::HandleInput()
{
     sf::Event event;
     while(_data->window.pollEvent(event))
     {
         if(sf::Event::Closed == event.type)
         {
             std::cout <<"Cerrando...";
             _data->window.close();
         }
         if( _data->input.IsSpriteClicked(_Playbutton, sf::Mouse::Left, _data->window))
         {
              _data->machine.AddState(StateRef(new GameState(_data)),true);
         }
     }
}

void MainMenuState::Update(float dt) 
{
}
void MainMenuState::Draw( float dt)
{
    _data->window.clear();
    _data->window.draw(_background);
    _data->window.draw(_title);
    _data->window.draw(_Playbutton);
    _data->window.display();
}

}