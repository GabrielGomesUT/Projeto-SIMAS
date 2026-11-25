#include "Estado.hpp"

namespace Castelos_e_ruinas{

    namespace Estados{

        Estado::Estado(const IDs::ID ID):
        Ente(sf::Vector2f(0.0f, 0.0f),sf::Vector2f(0.0f, 0.0f),ID),remover(false)
        {

        }

        Estado::~Estado(){

        }

        void Estado::setRemover(const bool Remover){
            remover = Remover;
        }

        const bool Estado::getRemover(){
            return remover;
        }
    }
}