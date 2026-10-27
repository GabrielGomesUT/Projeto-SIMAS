#include "Jogador.hpp"

namespace nomeDoJogo{
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
            void Jogador::mover(){
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
                    corpo.move(-vel.x,0.0f);
                else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                    corpo.move(vel.x,0.0f);
                else if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
                    corpo.move(0.0f,-vel.y);
                else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
                    corpo.move(0.0f,vel.y);
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