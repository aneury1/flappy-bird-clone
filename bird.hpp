#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "def.hpp"
#include "Game.hpp"


namespace FBC
{

class Bird
{
public:
    Bird(GameDataRef data);

    void Draw();

    void Animation( float dt);

    void Update(float dt);
    
    void Tap();

    const sf::Sprite& GetSprite() const;

private:

    GameDataRef _data;
    sf::Sprite  _birdSprite;
    std::vector<sf::Texture>_animation_frames;
    unsigned int _animation_iterator;
    sf::Clock clock;
    sf::Clock movementClock;
    int _birdState;


    float rotation;
    


};


}
