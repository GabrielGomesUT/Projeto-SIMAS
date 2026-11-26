#include "Plataforma.hpp"
#include "Jogador.hpp"

namespace Castelos_e_ruinas{
    namespace Entidades{
        namespace Obstaculos{
            Plataforma::Plataforma(const sf::Vector2f pos, const sf::Vector2f tam):Obstaculo(pos,tam,IDs::ID::plataforma),altura(pos.y){
                sf::Texture* text = carregarText("../assets/piso.png");
                corpo.setTexture(text);
                danoso = false;
                coolDown = 600;
            }

            Plataforma::~Plataforma(){

            }

            void Plataforma::executar(){
                if(coolDown < 0){
                    float aleatorio = rand() % 1000 * altura;
                    if(aleatorio < 1)
                        danoso = true;
                }
                //gravidade();
                //antigravidade();
            }

            void Plataforma::salvar(){

            }

            void Plataforma::obstaculizar(Personagens::Jogador* p){
                if(danoso)
                    p->operator--();
                danoso = false;
                coolDown = 600;
            }
        }
    }
}