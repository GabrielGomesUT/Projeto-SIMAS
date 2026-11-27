#include "Estado.hpp"

namespace Castelos_e_ruinas{

    namespace Estados{

        Gerenciadores::Gerenciador_Estados* Estado::pGEstado = Gerenciadores::Gerenciador_Estados::getGerenciadorEstados();

        Estado::Estado(const IDs::ID ID):
        Ente(sf::Vector2f(0.0f, 0.0f),sf::Vector2f(0.0f, 0.0f),ID)
        {

        }

        Estado::~Estado(){

        }
    }
}