#include "Inimigo.hpp"
#include "Jogador.hpp"
#include <cmath>

namespace nomeDoJogo{
    namespace Entidades{
        namespace Personagens{
            Inimigo::Inimigo(const sf::Vector2f pos, const sf::Vector2f tam,Jogador* jog):Personagem(pos,tam),jogador(jog),moveAleatorio(rand() % 4),relogio(){
               corpo.setFillColor(sf::Color::Red); 
               srand(time(NULL));
               Inicializa();
            }

            Inimigo::~Inimigo(){
                jogador = NULL;
            }

            void Inimigo::Inicializa(){
                vel = sf::Vector2f(VELOCIDADE_INIMIGO_X,VELOCIDADE_INIMIGO_Y);
            }

            void Inimigo::salvarDataBuffer(){

            }

            void Inimigo::setJogador(Jogador* pJog){
                if(pJog)
                    jogador = pJog;
                else
                    cerr<<"Ponteiro passado eh nulo"<<endl;
            }

            void Inimigo::persegueJogador(sf::Vector2f posJog,sf::Vector2f posInim){
                if(posJog.x - posInim.x > 0.0f) // jogador a direita do inimigo
                    corpo.move(vel.x,0.0f);
                else
                    corpo.move(-vel.x,0.0f); // jogador a esquerda do inimigo

                if(posJog.y - posInim.y > 0.0f) // jogador em cima do inimigo
                    corpo.move(0.0f,vel.y);
                else
                    corpo.move(0.0f,-vel.y); // jogador abaixo do inimigo
            }
            
            void Inimigo::executar(){

            }// = 0;
            //virtual void danificar(Jogador* p) = 0;

            void Inimigo::salvar(){

            }// = 0;

            void  Inimigo::mover(){
                if(jogador != NULL){
                    sf::Vector2f posJogador = jogador->getSprite().getPosition();
                    sf::Vector2f posInimigo = corpo.getPosition();
                    
                    if(fabs(posJogador.x - posInimigo.x) <= RAIO_PERSEGUICAO_X && fabs(posJogador.y - posInimigo.y) <= RAIO_PERSEGUICAO_Y)
                        persegueJogador(posJogador,posInimigo);
                    else
                        moverAleatorio();
                }
                else
                    cerr<<"Ponteiro para jogador não inicializado"<<endl;
            }

            void Inimigo::moverAleatorio(){
                if(moveAleatorio == 0)
                    corpo.move(vel.x,0.0f);
                else if(moveAleatorio == 1)
                    corpo.move(-vel.x,0.0f);
                else if(moveAleatorio == 2)
                    corpo.move(0.0f,vel.y);
                else
                    corpo.move(0.0f,-vel.y);
                
                float dt = relogio.getElapsedTime().asSeconds(); // garante a aleatoriedade do movimento a cada segundo
                if(dt >= 1.0f){
                    moveAleatorio = rand() % 4;
                    relogio.restart();
                }

            }

            sf::RectangleShape Inimigo::getSprite() const{
                return corpo;
            }
        }
    }
}