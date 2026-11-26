#pragma once
#include "Entidade.hpp"

namespace Castelos_e_ruinas{

    namespace Entidades{

        namespace Personagens{

            class Jogador;
            class Inimigo;
        }

        namespace Obstaculos{

            class Obstaculo:public Entidade{
            protected:
                bool danoso;
                int coolDown;
            public:
                Obstaculo(const sf::Vector2f pos, const sf::Vector2f tam,IDs::ID ID);
                ~Obstaculo();
                void salvarDataBuffer();
                virtual void executar() = 0;
                virtual void salvar() = 0;
                void colisao(Personagens::Jogador* pJ,sf::Vector2f ds);
                void colisao(Personagens::Inimigo* pI,sf::Vector2f ds);
                void antigravidade();
                virtual void obstaculizar(Personagens::Jogador* p) = 0;
            };
        }

    }

}