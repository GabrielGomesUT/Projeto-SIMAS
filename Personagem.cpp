#include "Personagem.hpp"

namespace Castelos_e_ruinas{
    namespace Entidades{
        namespace Personagens{
            Personagem::Personagem(const sf::Vector2f pos, const sf::Vector2f tam):Entidade(pos,tam),num_vidas(0),vel(sf::Vector2f(0.0f,0.0f)),podeAndar(false),paraEsquerda(false),dt(0){
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
            void Personagem::atualizaPosicao(){
                dt = relogio.getElapsedTime().asSeconds(); 
                float ds = 0; //elemento de deslocamento infinitesimal
                ds = vel.x * dt; // Velocidade instantanea
                if(paraEsquerda) //se o corpo estiver olhando para esquerda, anda para a esquerda, e vice-versa
                    ds *= -1;
                corpo.move(ds,0.0f);
            }
        }
    }
}
