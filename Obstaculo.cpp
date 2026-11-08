#include "Obstaculo.hpp"
#include "Jogador.hpp"
#include "Inimigo.hpp"

namespace Castelos_e_ruinas{

    namespace Entidades{

        Obstaculo::Obstaculo(const sf::Vector2f pos, const sf::Vector2f tam):Entidade(pos,tam,IDs::ID::obstaculo),danoso(false){
            corpo.setFillColor(sf::Color::Yellow);
        }

        Obstaculo::~Obstaculo(){

        }

        void Obstaculo::salvarDataBuffer(){

        }

        void Obstaculo::salvar(){

        }

        void Obstaculo::executar(){

        }

        void Obstaculo::atualizar(){
            executar();
        }

        void Obstaculo::colisao(Personagens::Jogador* pJ,sf::Vector2f ds){
            if(pJ != NULL){
                float invasaoX = fabs(ds.x);
                float invasaoY = fabs(ds.y);
                if(invasaoX < invasaoY){ // colisão lateral
                    if(pJ->getPos().x < this->getPos().x){
                        pJ->setPos(sf::Vector2f((pJ->getPos().x - invasaoX),pJ->getPos().y));
                    }
                    else{
                        pJ->setPos(sf::Vector2f((pJ->getPos().x + invasaoX),pJ->getPos().y));
                    }
                }
                else{    //colisao vertical
                    if(pJ->getPos().y < this->getPos().y){  //piso
                        pJ->setPos(sf::Vector2f(pJ->getPos().x,(pJ->getPos().y - invasaoY)));
                        pJ->setPodePular(true);
                    }
                    else  //teto
                        pJ->setPos(sf::Vector2f(pJ->getPos().x,(pJ->getPos().y)+ invasaoY));
                     pJ->setVelY(0.0f);
                }
            }
        }

        void Obstaculo::colisao(Personagens::Inimigo* pI,sf::Vector2f ds){
            if(pI != NULL){
                float invasaoX = fabs(ds.x);
                float invasaoY = fabs(ds.y);
                if(invasaoX < invasaoY){ // colisão lateral
                    if(pI->getPos().x < this->getPos().x){
                        pI->setPos(sf::Vector2f((pI->getPos().x - invasaoX),pI->getPos().y));
                    }
                    else{
                        pI->setPos(sf::Vector2f((pI->getPos().x + invasaoX),pI->getPos().y));
                    }
                }
                else{    //colisao vertical
                    if(pI->getPos().y < this->getPos().y){  //piso
                        pI->setPos(sf::Vector2f(pI->getPos().x,(pI->getPos().y - invasaoY)));
                        pI->setVelY(0.0f);
                    }
                    else  //teto
                        pI->setPos(sf::Vector2f(pI->getPos().x,(pI->getPos().y)+ invasaoY));
                }
            }
        }
        //void obstaculizar(Personagens::Jogador* p);


        sf::RectangleShape Obstaculo::getSprite() const{
            return corpo;
        }
    }

}