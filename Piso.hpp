#include "Obstaculo.hpp"

namespace Castelos_e_ruinas{
    namespace Entidades{

        namespace Personagens{
            class jogador;
        }

        namespace Obstaculos{
            class Piso:public Obstaculo{
            private:
                float tempo_acumulado;
            public:
                Piso(const sf::Vector2f pos, const sf::Vector2f tam);
                ~Piso();
                void executar();
                void salvar();
                void obstaculizar(Personagens::Jogador* p);
            }; 
        }
    }

}