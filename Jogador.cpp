#include "Jogador.hpp"
#include "Inimigo.hpp"
#include "ID.hpp"

namespace Castelos_e_ruinas{
    namespace Entidades{
        namespace Personagens{
            Jogador::Jogador():Personagem(sf::Vector2f(0.0f,0.0f),sf::Vector2f(50.0f,50.0f),IDs::ID::jogador),pontos(0),podePular(false){
               corpo.setFillColor(sf::Color::Green); 
               Inicializa();
            }
            
            Jogador::~Jogador(){

            }
            
            void Jogador::Inicializa(){
                vel = sf::Vector2f(VELOCIDADE_JOGADOR_X,0.0f);
            }

            void Jogador::colisao(Inimigo* pIn,sf::Vector2f ds){
                float invasaoX = fabs(ds.x);
                float invasaoY = fabs(ds.y);
                if(invasaoX < invasaoY){ // colisão lateral
                    if(this->getPos().x < pIn->getPos().x){
                        this->setPos(sf::Vector2f((this->getPos().x - invasaoX),this->getPos().y));
                    }
                    else{
                        this->setPos(sf::Vector2f((this->getPos().x + invasaoX),this->getPos().y));
                    }
                }
                else{    //colisao vertical
                    if(this->getPos().y < pIn->getPos().y){  //piso
                        this->setPos(sf::Vector2f(this->getPos().x,(this->getPos().y - invasaoY)));
                        this->setPodePular(true);
                        this->setVelY(0.0f);
                    }
                }
            }

            void Jogador::setPodePular(bool b){
                podePular = b;
            }

            void Jogador::pular(){
                if(podePular){
                    this->setVelY(VELOCIDADE_PULO);
                }
            }

            void Jogador::operator++(){
                pontos++;
            }

            void Jogador::mover(){
                dt = relogio.getElapsedTime().asSeconds();
                setPodePular(false);
                if(podeAndar)
                    atualizaPosicao();
                gravidade();
                relogio.restart();
            }
            sf::RectangleShape Jogador::getSprite() const{
                return corpo;
            }
            void Jogador::salvar(){

            }
            void Jogador::executar(){

            }
        }
    }
}