#include "Land.hpp"

namespace FBC
{
Land::Land(GameDataRef data):_data(data)
{
     sf::Sprite sprite1( _data->assets.GetTexture("Land"));
     sf::Sprite sprite2( _data->assets.GetTexture("Land"));

     sprite1.setPosition(0,_data->window.getSize().y - sprite1.getGlobalBounds().height);

     sprite2.setPosition(sprite1.getGlobalBounds().width,_data->window.getSize().y - sprite1.getGlobalBounds().height);
 
     _landSprites.push_back(sprite1);
     _landSprites.push_back(sprite2);
}

void Land::MoveLand(float dt)
{
    for(unsigned int i=0;i<_landSprites.size(); i++)
    {
       float movement = PIPE_MOVE_SPEED * dt;
       _landSprites[i].move(-movement, 0.0f );

       if( _landSprites[i].getPosition().x < 0 - _landSprites[i].getGlobalBounds().width)
       {
           sf::Vector2f position(_data->window.getSize().x , _landSprites[i].getPosition().y);
           _landSprites[i].setPosition(position);
       }

    }
} 

void Land::DrawLand()
{
   for(unsigned int i=0;i<_landSprites.size(); i++)
    {
        _data->window.draw(_landSprites.at(i));
    }

}



}