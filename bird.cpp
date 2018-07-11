#include "bird.hpp"
namespace FBC
{

Bird::Bird(GameDataRef data): _data(data)
{
    _animation_iterator  = 0 ;

    _animation_frames.push_back( _data->assets.GetTexture("bird1") );
    _animation_frames.push_back( _data->assets.GetTexture("bird2") );
    _animation_frames.push_back( _data->assets.GetTexture("bird3") );
    _animation_frames.push_back( _data->assets.GetTexture("bird4") );

    _birdSprite.setTexture(_animation_frames.at(_animation_iterator));
    
    _birdSprite.setPosition(((_data->window.getSize().x / 4) - _birdSprite.getGlobalBounds().width/2) ,
                             ((_data->window.getSize().y / 2) - _birdSprite.getGlobalBounds().height/2)
                             );
    _birdState = BIRD_STATE_STILL;

    sf::Vector2f origin = sf::Vector2f( _birdSprite.getGlobalBounds().width  / 2, 
                                        _birdSprite.getGlobalBounds().height / 2
                                      );

    _birdSprite.setOrigin(origin);

    rotation = 0;

}

void Bird::Draw()
{
    _data->window.draw(_birdSprite);
}

void Bird::Animation( float dt)
{
    if(clock.getElapsedTime().asSeconds() > BIRD_ANIMATION_DURATION / _animation_frames.size() )
    {
        if( _animation_iterator < _animation_frames.size() - 1)
        {
            _animation_iterator++;
        }
        else
            _animation_iterator = 0;
        
        _birdSprite.setTexture(_animation_frames[_animation_iterator]);
        
        clock.restart();
    }
}

void Bird::Update(float dt)
{
    if(_birdState == BIRD_STATE_FALLING)
    {
        _birdSprite.move(0, GRAVITY * dt);

        rotation += ROTATION_SPEED * dt;

        if(rotation > 25.0f)
        {
            rotation  = 25.0f;
        }
         
         _birdSprite.setRotation(rotation);

    }
    else if(_birdState == BIRD_STATE_FLYING)
    {
        _birdSprite.move(0, -FLYING_SPEED * dt);

        rotation -= ROTATION_SPEED * dt;

        if(rotation < -25.0f)
        {
            rotation  = -25.0f;
        }
         
         _birdSprite.setRotation(rotation);


    }

    if( movementClock.getElapsedTime().asSeconds() > FLYING_DURATION)
    {
        movementClock.restart();
        _birdState = BIRD_STATE_FALLING;
    }

}
    
void Bird::Tap()
{
    movementClock.restart();
    _birdState = BIRD_STATE_FLYING;
}


}