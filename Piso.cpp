#include "Piso.hpp"
#include "Jogador.hpp"

namespace Castelos_e_ruinas{
    namespace Entidades{
        namespace Obstaculos{
            Piso::Piso(const sf::Vector2f pos, const sf::Vector2f tam):Obstaculo(pos,tam,IDs::ID::piso){
                sf::Texture* text = carregarText("../assets/piso.png");
                text->setRepeated(true);
                corpo.setTexture(text);
                corpo.setTextureRect(sf::IntRect(0, 0, 400, text->getSize().y));
            }
            Piso::~Piso(){

            }
            void Piso::executar(){

            }
            void Piso::salvar(){

            }

            void Piso::atualizar(){

            }

            void Piso::obstaculizar(Personagens::Jogador* p){
                dt = relogio.getElapsedTime().asSeconds();
                if(dt >= 5.0f){
                    p->operator++();
                }
            }

            sf::RectangleShape Piso::getSprite() const{
                return corpo;
            }
        }
    }
}