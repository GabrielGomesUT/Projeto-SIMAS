#include "Entidade.hpp"

namespace Castelos_e_ruinas{
    namespace Entidades{
        Entidade::Entidade(const sf::Vector2f pos,const sf::Vector2f tam):Ente(),x(pos.x),y(pos.y),corpo(sf::RectangleShape(tam)){
            corpo.setPosition(pos);
        }
        Entidade::~Entidade(){

        }
    }
}