
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
    _data->assets.LoadTexture("Land", LAND_IMG);
    _data->assets.LoadTexture("pipeup", PIPE_UP);
    _data->assets.LoadTexture("pipedown", PIPE_DOWN);

    _data->assets.LoadTexture("bird1", BIRD_FRAME_1_PATH);
    _data->assets.LoadTexture("bird2", BIRD_FRAME_2_PATH);
    _data->assets.LoadTexture("bird3", BIRD_FRAME_3_PATH);
    _data->assets.LoadTexture("bird4", BIRD_FRAME_4_PATH);

    _data->assets.LoadTexture("gameovermsg", GAME_OVER_MSG);

    
    _background.setTexture(_data->assets.GetTexture("Main Menu Background"));
    
     pipes = new Pipe(_data); 
     land  = new Land(_data);
     bird  = new Bird(_data);

    game_state = GameStates::eReady;
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
             if(this->game_state != GameStates::eGameOver)
             {
                 game_state = GameStates::ePlaying;
                 bird->Tap();
             }
         }
     }
}

void GameState::Update(float dt) 
{
   if(this->game_state != GameStates::eGameOver)
       {
            land->MoveLand( dt);
            bird->Animation(dt);
            pipes->MovePipes( dt );
       }
      
    if( game_state == GameStates::ePlaying)
    {
        if(clock.getElapsedTime().asSeconds() > PIPE_SPAWN_SPEED_FRECUENCY)
                {
                        pipes->RandomizePipeOffset();

                        pipes->SpawnInvisiblePipe();
                        pipes->SpawnBottomPipe();
                        pipes->SpawnTopPie();
                        
                        clock.restart();
                }
            
                bird->Update(dt);
            
                std::vector<sf::Sprite> landSprites = land->GetSprites();
        
                for(unsigned int i =0; i<landSprites.size(); i++)
                {
                    if( collision.CheckSpriteCollision(landSprites[i],0.7f, bird->GetSprite(),1.0f))
                    {
                      game_state = GameStates::eGameOver;
                       //// _data->machine.AddState(StateRef(new GameOverState(_data)),true);
                    }
                }

                std::vector<sf::Sprite> pipeSprites = pipes->GetSprites();
        
                for(unsigned int i =0; i<pipeSprites.size(); i++)
                {
                    if( collision.CheckSpriteCollision(pipeSprites[i],0.625f, bird->GetSprite(), 1.0f))
                    {
                        game_state = GameStates::eGameOver;
                       /// _data->machine.AddState(StateRef(new GameOverState(_data)),true);
                    }
                }
    }
}
void GameState::Draw( float dt)
{
    _data->window.clear();
    _data->window.draw(_background);
     pipes->DrawPipes();
     land->DrawLand();
     bird->Draw();
    _data->window.display();
}

}