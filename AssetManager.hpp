#pragma once
#include <map>
#include <string>
#include <SFML/Graphics.hpp>

namespace FBC
{

    class AssetManager
    {
        public:

        AssetManager(){}
        ~AssetManager(){}

        void LoadTexture(std::string name, std::string filename );
        sf::Texture &GetTexture( std::string name);

        void LoadFont(std::string name, std::string filename );
        sf::Font &GetFont( std::string name);


        private:

        std::map<std::string, sf::Texture>_textures;
        std::map<std::string, sf::Font>_fonts;
    };






}