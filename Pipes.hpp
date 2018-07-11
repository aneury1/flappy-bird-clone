#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "Game.hpp"


namespace FBC
{
class Pipe
{
   
   GameDataRef _data;
   std::vector<sf::Sprite> pipeSprites;

 public:
    
    Pipe(GameDataRef data);

    void DrawPipes();

    void SpawnBottomPipe();
    void SpawnTopPie();
    void SpawnInvisiblePipe();
    void MovePipes(float dt);

};


}