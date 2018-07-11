#include "Game.hpp"

#include "SplashState.hpp"

namespace FBC
{
Game::Game(int w, int h, std::string title)
{
    _data->window.create(sf::VideoMode(w,h), title, sf::Style::Close|sf::Style::Titlebar);

    _data->machine.AddState( static_cast<StateRef>(new SplashState( this->_data )));


    this->Run();
}

void Game::Run()
{
    float newTime, frameTime, interpolation;

    float currentTime = this->_clock.getElapsedTime().asSeconds();

    float accumulator = 0.0f;

    while( _data->window.isOpen())
    {
       this->_data->machine.ProcessStateChanges( );

       newTime =this->_clock.getElapsedTime().asSeconds();

       frameTime = newTime - currentTime;

       if( frameTime > 0.25f)
       {
           frameTime = 0.25f;
       }
        
       currentTime = newTime;

       accumulator += frameTime;

       while( accumulator >= dt)
       {
           this->_data->machine.GetActiveState( )->HandleInput();

           this->_data->machine.GetActiveState( )->Update(dt);

            accumulator -= dt; 
       }

      interpolation = accumulator / dt;
        
      this->_data->machine.GetActiveState( )->Draw(interpolation);

    }
}

}