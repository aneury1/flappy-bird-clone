#include "AssetManager.hpp"


namespace FBC
{

void AssetManager::LoadTexture(std::string name, std::string filename)
{
   sf::Texture textures;
   if(textures.loadFromFile(filename))
   {
       _textures[name]= textures;
   }
}

sf::Texture &AssetManager::GetTexture( std::string name)
{
    return _textures[name];
}

void AssetManager::LoadFont(std::string name, std::string filename)
{
   sf::Font font;
   if(font.loadFromFile(filename))
   {
       _fonts[name]= font;
   }
}

sf::Font &AssetManager::GetFont( std::string name)
{
    return _fonts[name];
}


}