#pragma once
#include "Inimigo.hpp"
#define VIDA_ZUMBIE 5
#define NIVEL_MALDADE_ZUMBIE 1
#define VELOCIDADE_ZUMBIE_X 40.0f

namespace Castelos_e_ruinas {
    namespace Entidades {
        namespace Personagens {

            class Jogador;

            class Zumbi : public Inimigo {
            private:
                int tamanho;

            public:
                Zumbi(const sf::Vector2f pos, const sf::Vector2f tam);
                ~Zumbi();
                void danificar(Jogador* pJog) override;
                void executar() override;
                void salvar() override;
            };

        }
    }
}