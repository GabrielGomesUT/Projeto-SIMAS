#include "Lama.hpp"
#include "Jogador.hpp"

namespace Castelos_e_ruinas{
    namespace Entidades{
        namespace Obstaculos{
            Lama::Lama(const sf::Vector2f pos, const sf::Vector2f tam):Obstaculo(pos,tam,IDs::ID::lama),desaceleracao(70.0f),largura(pos.x){
                sf::Texture* text = carregarText("../assets/lama.png");
                corpo.setTexture(text);
                danoso = false;
                coolDown = 400;
            }

            Lama::~Lama(){

            }
            
            void Lama::executar(){
                danoso = false;
                if(coolDown < 0){
                    int aleatorio = rand() % 8*largura;
                    if(aleatorio < 2000)
                        danoso = true;
                    coolDown = 400;
                }
                coolDown--;
            }

            void Lama::salvar(){

            }

            void Lama::obstaculizar(Personagens::Jogador* p){
                if(p != NULL){
                    if(p->getVel().x > 0)
                        p->desaceleracao(desaceleracao);
                    else
                        p->desaceleracao(-desaceleracao); 
                    p->setPodePular(false);
                }
            }
        }
    }
}
