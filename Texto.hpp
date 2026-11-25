#pragma once
#include <SFML/Graphics.hpp>
#include <string>

namespace Castelos_e_ruinas{

    namespace Botoes{

        class Texto{    // codigo adaptado dos videos do monitor Giovane Limas Salvi
        private:
            sf::Font fonte;
            std::string info;
            sf::Text texto;
            sf::Color cor;
            unsigned int tamFonte;
        public:
            Texto(const sf::Font font,std::string inf,const unsigned int tamFont);
            ~Texto();
            void setPos(const sf::Vector2f pos);
            sf::Text getTexto() const;
            void setCorTexto(sf::Color corText);
            sf::Vector2f getTam() const;
        };
    } 
}