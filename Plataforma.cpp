#include "Plataforma.hpp"
#include "Jogador.hpp"

namespace Castelos_e_ruinas{
    namespace Entidades{
        namespace Obstaculos{
            Plataforma::Plataforma(const sf::Vector2f pos, const sf::Vector2f tam):Obstaculo(pos,tam,IDs::ID::plataforma),altura(pos.y){
                sf::Texture* text = carregarText("../assets/piso.png");
                text->setRepeated(true);
                corpo.setTexture(text);
                corpo.setTextureRect(sf::IntRect(0, 0, 200, text->getSize().y));
                danoso = false;
            }

            Plataforma::~Plataforma(){

            }

            void Plataforma::executar(){

            }

            void Plataforma::salvar(){

            }

            void Plataforma::atualizar(){

            }

            void Plataforma::obstaculizar(Personagens::Jogador* p){
            
            }
        }
    }
}