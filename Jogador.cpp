#include "Jogador.hpp"
#include "Inimigo.hpp"
#include "GerenciadorGrafico.hpp"

namespace Castelos_e_ruinas{
    namespace Entidades{
        namespace Personagens{                                                                                                                                                                                                                                                                     
            Jogador::Jogador(const sf::Vector2f pos, const sf::Vector2f tam,sf::Color cor):
            Personagem(pos,tam,IDs::ID::jogador),pontos(0),podePular(false),vel_lentidao(0.0f),lentidao(false)
            {
               sf::Texture* text = carregarText("../assets/jogador.png");
               corpo.setTexture(text);
               corpo.setFillColor(cor);
               inicializa();
               inicializaBarraVida();
            }

            Jogador::Jogador():
            Personagem(sf::Vector2f(0.0f,ALTURA_TELA - 145.0f),sf::Vector2f(50.0f,50.0f),IDs::ID::jogador),pontos(0),podePular(false),vel_lentidao(0.0f),lentidao(false)
            {
            sf::Texture* text = carregarText("../assets/jogador.png");
               corpo.setTexture(text);
               inicializa();
               inicializa();
               inicializaBarraVida();
            }
            
            Jogador::~Jogador(){

            }

            void Jogador::inicializa(){
                num_vidas = VIDA_JOGADOR;
                vida_max = VIDA_JOGADOR;
                ativo = true;
                pontos = 0;
                vel = sf::Vector2f(0.0f,0.0f);
                podePular = false;
                lentidao = false;
                podeAndar =false;
            }

            void Jogador::recuperaAtributos(){
                num_vidas = VIDA_JOGADOR;
                vida_max = VIDA_JOGADOR;
                ativo = true;
                vel = sf::Vector2f(0.0f,0.0f);
                podePular = false;
                lentidao = false;
                podeAndar =false;
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
                    pIn->danificar(this);
                }
                else{    //colisao vertical
                    if(this->getPos().y < pIn->getPos().y){  //piso
                        this->setPos(sf::Vector2f(this->getPos().x,(this->getPos().y - invasaoY)));
                        this->setPodePular(true);
                        this->setVelY(0.0f);
                        this->pular();
                        pIn->operator--();
                        if(pIn->getID() == IDs::ID::cavaleiro)
                            setPontos(3);
                        else if(pIn->getID() == IDs::ID::zumbi)
                            setPontos(5);
                        else if(pIn->getID() == IDs::ID::dragao)
                            setPontos(7);
                    }
                }
            }

            void Jogador::setPodePular(bool b){
                podePular = b;
            }

            void Jogador::desaceleracao(float f_lent){
                if(f_lent > 0){
                    lentidao = true;
                    vel_lentidao = f_lent;
                }
            }

            void Jogador::pular(){
                if(podePular){
                    this->setVelY(VELOCIDADE_PULO);
                }
            }

            void Jogador::setPontos(int pTs){
                pontos+=pTs;
            }

            int Jogador::getPontos(){
                return pontos;
            }

            void Jogador::mover(){
                setPodePular(false);
                if(lentidao)
                    vel.x = vel_lentidao;
                else
                    vel.x = VELOCIDADE_JOGADOR_X; 
                    
                lentidao = false;
                if(podeAndar)
                    atualizaPosicao();
                gravidade();
            }
            void Jogador::salvar(){

            }
            void Jogador::executar(){
                mover();
                atualizaBarraVida();
            }
        }
    }
}