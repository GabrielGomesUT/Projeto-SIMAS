#pragma once
#include "Entidade.hpp"

namespace Castelos_e_ruinas{
    namespace Entidades{
        namespace Personagens{
            class Personagem:public Entidade{
            protected:
                int num_vidas;
                sf::Vector2f vel;
                bool podeAndar;
                bool paraEsquerda;
                sf::Clock relogio;
                float dt;
            public:
                Personagem(const sf::Vector2f pos, const sf::Vector2f tam);
                virtual ~Personagem();
                void salvarDataBuffer();
                virtual void executar() = 0;
                virtual void mover() = 0;
                virtual void salvar() = 0;
                virtual sf::RectangleShape getSprite() const = 0;
                void andar(bool paraEsq);
                void parar();
                void atualizaPosicao(); // codigo adaptado dos videos do monitor Lucas Eduardo Bonâncio Skora
            };
        }
    }
}