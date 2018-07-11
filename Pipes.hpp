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
   std::vector<sf::Sprite> ScoringSprites;
   int _landHeight;
   int _pipeSpawnYOffset;

 public:
    
    Pipe(GameDataRef data);
    void DrawPipes();
    void SpawnBottomPipe();
    void SpawnTopPie();
    void SpawnInvisiblePipe();
    void SpawnScoringPipe();
    void MovePipes(float dt);

    void RandomizePipeOffset();

    inline const std::vector<sf::Sprite>& GetSprites()const{return pipeSprites;}
    inline   std::vector<sf::Sprite>& GetScoringSprites() {return ScoringSprites;}

};


}