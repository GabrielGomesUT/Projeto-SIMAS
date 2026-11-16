#include "Entidade.hpp"

namespace Castelos_e_ruinas{
    namespace Entidades{
        Entidade::Entidade(const sf::Vector2f pos,const sf::Vector2f tam,IDs::ID ID):Ente(pos,tam,ID),x(pos.x),y(pos.y){

        }

        float Entidade::dt(0.0f);
        
        Entidade::~Entidade(){

        }

        sf::Vector2f Entidade::getPos() const{
            //return sf::Vector2f(x,y);    
            return corpo.getPosition();
        }

        void Entidade::setPos(sf::Vector2f Pos){
            corpo.setPosition(Pos);
            x = Pos.x;
            y = Pos.y;
        }

        sf::Vector2f Entidade::getTam() const{
            return corpo.getSize();
        }

        void Entidade::setTam(sf::Vector2f Tam){
           corpo.setSize(Tam);
        }
    }
}

