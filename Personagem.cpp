#include "Personagem.hpp"
#include "GerenciadorGrafico.hpp"

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

            void Personagem::inicializaBarraVida(){
                barraVida.setSize(sf::Vector2f(50.0f,6.0f));
                barraVida.setFillColor(sf::Color::Red);
                barraFundo.setSize(sf::Vector2f(50.0f,6.0f));
                barraFundo.setFillColor(sf::Color(40,40,40));
                barraFundo.setOutlineThickness(1.5f);
                barraFundo.setOutlineColor(sf::Color::Black);
            }

            void Personagem::atualizaBarraVida(){
                if(num_vidas > 0){
                    float proporcao = (float) num_vidas/vida_max;
                    if(proporcao > 1)
                        proporcao = 1;
                    else if(proporcao > 0.5)
                        barraVida.setFillColor(sf::Color::Red);
                    else if(proporcao > 0)
                        barraVida.setFillColor(sf::Color::Yellow);
                    else
                        proporcao = 0;
                    barraVida.setSize(sf::Vector2f(barraFundo.getSize().x * proporcao, barraFundo.getSize().y));
                    float posX = x + (this->getTam().x / 2.0f) - (barraFundo.getSize().x / 2.0f);
                    float posY = y - barraFundo.getSize().y - 6.0f;
                    barraFundo.setPosition(sf::Vector2f(posX, posY));
                    barraVida.setPosition(sf::Vector2f(posX, posY));
                    pGG->desenharTitulo(barraFundo);
                    pGG->desenharTitulo(barraVida);
                }
            }

            void Personagem::operator++(){
                num_vidas++;
            }

            void Personagem::operator--(){
                num_vidas--;
            }

            void Personagem::atualizaPosicao(){
                if(paraEsquerda) //se o corpo estiver olhando para esquerda, anda para a esquerda, e vice-versa
                    x -= vel.x;
                else
                     x += vel.x;
                corpo.setPosition(x,y);
            }
        }
    }
}
