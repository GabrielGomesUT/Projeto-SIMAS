#include "Personagem.hpp"

namespace Castelos_e_ruinas{
    namespace Entidades{
        namespace Personagens{

            Personagem::Personagem(const sf::Vector2f pos, const sf::Vector2f tam,IDs::ID ID):
            Entidade(pos,tam,ID),num_vidas(0),vida_max(0),podeAndar(false),paraEsquerda(false),barraVida(),barraFundo()
            {

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

            int Personagem::getNumVida(){
                return num_vidas;
            }

            void Personagem::inicializaBarraVida(sf::Vector2f Tam){
                barraVida.setSize(Tam);
                barraVida.setFillColor(sf::Color::Red);
                barraFundo.setSize(Tam);
                barraFundo.setFillColor(sf::Color::Black);
                barraFundo.setOutlineThickness(1.5f);
                barraFundo.setOutlineColor(sf::Color::Black);
            }

            void Personagem::atualizaBarraVida(){
                if(num_vidas > 0){
                    float proporcao = (float) vida_max/num_vidas;
                    barraVida.setSize(sf::Vector2f(barraFundo.getSize().x * proporcao,barraFundo.getSize().y));
                    barraVida.setPosition(sf::Vector2f(x + (this->getTam().x/2.0f) - (barraFundo.getSize().x/2.0f),y + 8.0f));
                    barraFundo.setPosition(sf::Vector2f(x + (this->getTam().x/2.0f) - (barraFundo.getSize().x/2.0f),y + 8.0f));
                }
            }

            void Personagem::operator--(){
                num_vidas--;
            }

            void Personagem::atualizaPosicao(){
                float dx = 0; //elemento de deslocamento
                dx = vel.x * dt; // Velocidade instantanea
                if(paraEsquerda) //se o corpo estiver olhando para esquerda, anda para a esquerda, e vice-versa
                    dx *= -1;
                corpo.move(dx,0.0f);
            }
        }
    }
}
