#pragma once
#include "Inimigo.hpp"

namespace Castelos_e_ruinas {
    namespace Entidades {
        namespace Personagens {

            class Cavaleiro : public Inimigo {
            private:
                //float raio; Tem que ver com o professor se vai precisar, pois tem no diagrama mas nos usamos o raio 
                //de perseguição da classe Inimigo

            public:
                Cavaleiro(sf::Vector2f pos, sf::Vector2f tam, Jogador* pJog = NULL);
                ~Cavaleiro();

                void danificar(Jogador* pJog);
                void executar();
                void salvar();
            };

        }
    }
}