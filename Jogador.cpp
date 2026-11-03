#include "Jogador.hpp"

namespace Castelos_e_ruinas{
    namespace Entidades{
        namespace Personagens{
            Jogador::Jogador():Personagem(sf::Vector2f(0.0f,0.0f),sf::Vector2f(50.0f,50.0f)),pontos(0){
               corpo.setFillColor(sf::Color::Green); 
               Inicializa();
            }
            
            Jogador::~Jogador(){

            }
            
            void Jogador::Inicializa(){
                vel = sf::Vector2f(VELOCIDADE_JOGADOR_X,VELOCIDADE_JOGADOR_Y);
            }

            void Jogador::colidir(Inimigo* p){

            }

            void Jogador::operator++(){
                pontos++;
            }

            void Jogador::mover(){
                if(podeAndar)
                    atualizaPosicao();
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