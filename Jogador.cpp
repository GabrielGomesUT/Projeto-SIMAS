#include "Jogador.hpp"
#include "Inimigo.hpp"
#include "GerenciadorGrafico.hpp"

namespace Castelos_e_ruinas{
    namespace Entidades{
        namespace Personagens{
            Jogador::Jogador(const sf::Vector2f pos, const sf::Vector2f tam):Personagem(pos,tam,IDs::ID::jogador),pontos(0),podePular(false),vel_lentidao(0.0f),lentidao(false){
               sf::Texture* text = carregarText("../assets/jogador.png");
               corpo.setTexture(text);
               num_vidas = 5;
               vel = sf::Vector2f(0.0f,0.0f);
            }

            Jogador::Jogador():Personagem(sf::Vector2f(0.0f,ALTURA_TELA - 145.0f),sf::Vector2f(50.0f,50.0f),IDs::ID::jogador),pontos(0),podePular(false),vel_lentidao(0.0f),lentidao(false){
            sf::Texture* text = carregarText("../assets/jogador.png");
               corpo.setTexture(text);
               num_vidas = 5;
               vel = sf::Vector2f(0.0f,0.0f);
            }
            
            Jogador::~Jogador(){

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

            void Jogador::operator++(){
                if(num_vidas < 5.0f)
                    num_vidas++;
            }

            void Jogador::mover(){
                dt = relogio.getElapsedTime().asSeconds();
                setPodePular(false);
                if(lentidao)
                    vel.x = vel_lentidao;
                else
                    vel.x = VELOCIDADE_JOGADOR_X;
                lentidao = false;
                if(podeAndar)
                    atualizaPosicao();
                gravidade();
                relogio.restart();
            }
            void Jogador::salvar(){

            }
            void Jogador::executar(){
                mover();
            }
        }
    }
}