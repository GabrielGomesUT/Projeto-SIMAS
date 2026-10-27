#include "Jogador.hpp"

namespace nomeDoJogo{
    namespace Entidades{
        namespace Personagens{
            Jogador::Jogador():Personagem(),corpo(){
               Inicializa();
            }
            Jogador::Jogador(const sf::RectangleShape corpo):Personagem(),corpo(corpo){
                Inicializa();
            }
            Jogador::Jogador(const sf::Vector2f pos, const sf::Vector2f tam):corpo(sf::RectangleShape(tam)){
                corpo.setPosition(pos);
                corpo.setFillColor(sf::Color::Green);
                Inicializa();
            }
            Jogador::~Jogador(){

            }
            void Jogador::Inicializa(){
                vel = sf::Vector2f(1.0f,1.0f);
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