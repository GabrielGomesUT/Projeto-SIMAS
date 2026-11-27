#pragma once
#include "Obstaculo.hpp"
#define DESACELERACAO_CHAMAS 0.5f
#define TEMPO_DANO_CHAMAS 1.0f

namespace Castelos_e_ruinas {
    namespace Entidades {

        namespace Personagens {
            class Jogador;
        }

        namespace Obstaculos {

            class LancaChamas : public Obstaculo {
            private:
                float desaceleracao;
                float tempoDano;
                sf::Clock relogioDano;

            public:
                LancaChamas(const sf::Vector2f pos, const sf::Vector2f tam);
                ~LancaChamas();

                void executar();
                void salvar();
                void obstaculizar(Personagens::Jogador* p);
            };

        }
    }
}