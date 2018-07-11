#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Pipes.hpp"
#include "def.hpp"
namespace FBC{
    
Pipe::Pipe(GameDataRef data):_data(data)
{
   srand(time(nullptr));
   _landHeight = _data->assets.GetTexture("Land").getSize().y;
   _pipeSpawnYOffset = 0;
    
}

void Pipe::DrawPipes()
{
   for(unsigned short int i=0; i<pipeSprites.size(); i++)
   {
       _data->window.draw(pipeSprites.at(i));
   }
}

void Pipe::SpawnBottomPipe()
{
  sf::Sprite sprite( _data->assets.GetTexture("pipeup"));
  sprite.setPosition(_data->window.getSize().x,  _data->window.getSize().y - sprite.getGlobalBounds().height - _pipeSpawnYOffset);
  pipeSprites.push_back(sprite);
}

void Pipe::SpawnTopPie()
{
  sf::Sprite sprite( _data->assets.GetTexture("pipedown"));
  sprite.setPosition(_data->window.getSize().x, - _pipeSpawnYOffset  );
  pipeSprites.push_back(sprite);
}

void Pipe::SpawnInvisiblePipe()
{
  sf::Sprite sprite( _data->assets.GetTexture("pipeup"));
  sprite.setPosition(_data->window.getSize().x,  _data->window.getSize().y - sprite.getGlobalBounds().height );
  sprite.setColor(sf::Color(0,0,0,0));
  pipeSprites.push_back(sprite);

}
void Pipe::MovePipes(float dt)
{
 
for(unsigned int i =0; i<pipeSprites.size();i++)
   {
      if(pipeSprites[i].getPosition().x < 0 - pipeSprites[i].getGlobalBounds().width)
      {
           pipeSprites.erase(pipeSprites.begin()+i);
      }
      else
      {
        float movement = dt * PIPE_MOVE_SPEED;
        pipeSprites[i].move(-movement, 0);
      }
   }
 
}

  void Pipe::RandomizePipeOffset()
  {
     this->_pipeSpawnYOffset = (std::rand() % _landHeight + 1)   ;

  }

}