#include "Texto.hpp"

namespace Castelos_e_ruinas{

    namespace Botoes{

        Texto::Texto(sf::Font font,std::string inf,const unsigned int tamFont):
        fonte(font),info(inf),texto(),cor(sf::Color::White),tamFonte(tamFont){
            texto.setString(info);
            texto.setFont(fonte);
            texto.setCharacterSize(tamFonte);
            texto.setFillColor(cor);
        }

        Texto::~Texto(){

        }

        void Texto::setPos(const sf::Vector2f pos){
            texto.setPosition(pos);
        }

        sf::Text Texto::getTexto() const{
            return texto;
        }

        void Texto::setCorTexto(sf::Color corText){
            cor = corText;
            texto.setFillColor(cor);
        }

        sf::Vector2f Texto::getTam() const{
            return sf::Vector2f(texto.getGlobalBounds().width,texto.getGlobalBounds().height);
        }
    }
}