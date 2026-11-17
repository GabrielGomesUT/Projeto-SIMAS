#pragma once
#include "Inimigo.hpp"
#define VIDA_CAVALEIRO 3
#define NIVEL_MALDADE_CAVALEIRO 1 
#define VELOCIDADE_CAVALEIRO_X 100.0f

namespace Castelos_e_ruinas {
    namespace Entidades {
        namespace Personagens {

            class Cavaleiro : public Inimigo {
            private:
                float raio;

            public:
                Cavaleiro(sf::Vector2f pos, sf::Vector2f tam);
                ~Cavaleiro();
                void danificar(Jogador* pJog);
                void executar();
                void salvar();
            };

        }
    }
}