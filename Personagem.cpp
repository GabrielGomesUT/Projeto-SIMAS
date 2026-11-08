#include "Personagem.hpp"

namespace Castelos_e_ruinas{
    namespace Entidades{
        namespace Personagens{
            Personagem::Personagem(const sf::Vector2f pos, const sf::Vector2f tam,IDs::ID ID):Entidade(pos,tam,ID),num_vidas(0),vel(sf::Vector2f(0.0f,0.0f)),podeAndar(false),paraEsquerda(false),dt(0){
            }
            Personagem::~Personagem(){

            }
            void Personagem::parar(){
                podeAndar = false;
            }
            void Personagem::andar(bool paraEsq){
                podeAndar = true;
                this->paraEsquerda = paraEsq;
            }

            void Personagem::atualizar(){
                mover();
                executar();
            }

            void Personagem::setVelY(float VelY){
                vel.y = VelY;
            }

            void Personagem::atualizaPosicao(){
                float dx = 0; //elemento de deslocamento
                dx = vel.x * dt; // Velocidade instantanea
                if(paraEsquerda) //se o corpo estiver olhando para esquerda, anda para a esquerda, e vice-versa
                    dx *= -1;
                corpo.move(dx,0.0f);
            }
            void Personagem::gravidade(){
                vel.y += GRAVIDADE*dt;
                float dy = 0;
                dy = vel.y * dt;
                corpo.move(0.0f,dy);
            }
        }
    }
}
