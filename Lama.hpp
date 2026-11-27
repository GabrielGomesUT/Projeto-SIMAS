#pragma once
#include "Obstaculo.hpp"

namespace Castelos_e_ruinas{
    namespace Entidades{

        namespace Personagens{
            class jogador;
        }

        namespace Obstaculos{
            class Lama:public Obstaculo{
            private:
                float desaceleracao;
            public:
                Lama(const sf::Vector2f pos, const sf::Vector2f tam);
                ~Lama();
                void executar();
                void salvar();
                void obstaculizar(Personagens::Jogador* p);
            }; 
        }
    }
}