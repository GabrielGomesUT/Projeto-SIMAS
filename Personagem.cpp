#include "Personagem.hpp"

namespace nomeDoJogo{
    namespace Entidades{
        namespace Personagens{
            Personagem::Personagem(const sf::Vector2f pos, const sf::Vector2f tam):Entidade(0,0),num_vidas(0),corpo(sf::RectangleShape(tam)){
                corpo.setPosition(pos);
            }
            Personagem::~Personagem(){

            }
        }
    }
}
