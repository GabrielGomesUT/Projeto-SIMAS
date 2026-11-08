#include "Inimigo.hpp"
#include "Jogador.hpp"

namespace Castelos_e_ruinas{
    namespace Entidades{
        namespace Personagens{
            Inimigo::Inimigo(const sf::Vector2f pos, const sf::Vector2f tam,Jogador* jog):Personagem(pos,tam,IDs::ID::inimigo),jogador(jog),moveAleatorio(rand() % 2),tempo_acumulado(0.0){
               corpo.setFillColor(sf::Color::Red); 
               srand(time(NULL));
               Inicializa();
            }

            Inimigo::~Inimigo(){
                jogador = NULL;
            }

            void Inimigo::Inicializa(){
                vel = sf::Vector2f(VELOCIDADE_INIMIGO_X,VELOCIDADE_INIMIGO_Y);
                podeAndar = true;
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
            
            void Inimigo::executar(){

            }// = 0;
            //virtual void danificar(Jogador* p) = 0;

            void Inimigo::salvar(){

            }// = 0;

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
                    cerr<<"Ponteiro para jogador não inicializado"<<endl;
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

            void Inimigo::tomarDano(){
                this->num_vidas--;
            }
            sf::RectangleShape Inimigo::getSprite() const{
                return corpo;
            }
        }
    }
}