#include "Inimigo.hpp"
#include "Jogador.hpp"

namespace Castelos_e_ruinas{
    namespace Entidades{
        namespace Personagens{
            Inimigo::Inimigo(const sf::Vector2f pos, const sf::Vector2f tam,IDs::ID ID):Personagem(pos,tam,ID),jogador(NULL),moveAleatorio(rand() % 2),tempo_acumulado(0.0){
                srand(time(NULL));
                podeAndar = true;
            }

            Inimigo::~Inimigo(){
                jogador = NULL;
            }

            void Inimigo::salvarDataBuffer(){

            }

            void Inimigo::setJogador(Jogador* pJog){
                if(pJog)
                    jogador = pJog;
                else
                    cerr<<"Ponteiro nulo passado por parametro"<<endl;
            }

            void Inimigo::persegueJogador(sf::Vector2f posJog,sf::Vector2f posInim){
                if(posJog.x - posInim.x > 0.0f) // jogador a direita do inimigo
                    andar(false);
                else    // jogador a esquerda do inimigo
                    andar(true); 

            }

            void Inimigo::mover(){
                if(jogador != NULL){
                    dt = relogio.getElapsedTime().asSeconds();

                    sf::Vector2f posJogador = jogador->getSprite().getPosition();
                    sf::Vector2f posInimigo = corpo.getPosition();
                    
                    if(fabs(posJogador.x - posInimigo.x) <= RAIO_PERSEGUICAO_X && fabs(posJogador.y - posInimigo.y) <= RAIO_PERSEGUICAO_Y)
                        persegueJogador(posJogador,posInimigo);
                    else
                        moverAleatorio();

                    if(podeAndar)
                        atualizaPosicao();
                    gravidade();
                    relogio.restart();
                }
                else
                    cerr<<"Ponteiro para jogador nao inicializado"<<endl;
            }

            void Inimigo::moverAleatorio(){
                if(podeAndar){
                    if(moveAleatorio == 0)
                        andar(false);
                    else if(moveAleatorio == 1)
                        andar(true);
                    // garante a aleatoriedade do movimento a cada segundo
                    tempo_acumulado+=dt;
                    if(tempo_acumulado >= 1.0f){
                        moveAleatorio = rand() % 2;
                        tempo_acumulado = 0.0f;
                    }
                }
            }
        }
    }
}
