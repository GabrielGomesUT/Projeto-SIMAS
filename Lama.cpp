#include "Lama.hpp"
#include "Jogador.hpp"

namespace Castelos_e_ruinas{
    namespace Entidades{
        namespace Obstaculos{
            Lama::Lama(const sf::Vector2f pos, const sf::Vector2f tam):Obstaculo(pos,tam,IDs::ID::lama),desaceleracao(70.0f){
                sf::Texture* text = carregarText("../assets/lama.png");
                text->setRepeated(true);
                corpo.setTexture(text);
                corpo.setTextureRect(sf::IntRect(0, 0, 100, text->getSize().y));
                danoso = false;
            }
            Lama::~Lama(){

            }
            void Lama::executar(){

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
