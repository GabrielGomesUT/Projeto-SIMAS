#include "Lama.hpp"
#include "Jogador.hpp"

namespace Castelos_e_ruinas{
    namespace Entidades{
        namespace Obstaculos{
            Lama::Lama(const sf::Vector2f pos, const sf::Vector2f tam):Obstaculo(pos,tam,IDs::ID::lama),desaceleracao(0.3f)
            {
                sf::Texture* text = carregarText("../assets/lama.png");
                corpo.setTexture(text);
                danoso = false;
                coolDown = 200;
            }

            Lama::~Lama(){

            }
            
            void Lama::executar(){
                danoso = false;
                if(coolDown < 0){
                    int aleatorio = rand() % 1000;
                    if(aleatorio < 1){
                        danoso = true;
                        coolDown = 200;
                    }
                }
                coolDown--;
                gravidade();
                antigravidade();
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
