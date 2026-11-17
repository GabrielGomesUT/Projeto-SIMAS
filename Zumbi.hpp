#pragma once

#include "Inimigo.hpp"

namespace Castelos_e_ruinas {
    namespace Entidades {
        namespace Personagens {

            class Jogador;

            class Zumbi : public Inimigo {
            private:
                /*int tamanho; Tem que ver com o sor se vamos usar, mesmo caso do cavaleiro*/

            public:
                Zumbi(const sf::Vector2f pos, const sf::Vector2f tam, Jogador* pJog = NULL);
                ~Zumbi();

                void danificar(Jogador* pJog) override;
                void executar() override;
                void salvar() override;
            };

        }
    }
}