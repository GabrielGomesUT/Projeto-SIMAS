#include "Entidade.hpp"

namespace Castelos_e_ruinas{
    namespace Entidades{
        Entidade::Entidade(const sf::Vector2f pos,const sf::Vector2f tam,IDs::ID ID):
        Ente(pos,tam,ID),x(pos.x),y(pos.y),ativo(true),vel(sf::Vector2f(0.0f,0.0f)),coolDown(0)
        {

        }
        
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

        void Entidade::setAtivo(const bool Ativo){
            ativo = Ativo;
        }

        void Entidade::setVelY(float Vely){
            vel.y = Vely;
        }

        void Entidade::setVelX(float Velx){
            vel.x = Velx;
        }

        sf::Vector2f Entidade::getVel(){
            return vel;
        }

        bool Entidade::getAtivo(){
            return ativo;
        }

        void Entidade::gravidade(){
            vel.y += GRAVIDADE;
            y += vel.y;
            corpo.setPosition(x,y);
        }
    }
}

