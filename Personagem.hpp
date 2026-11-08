#pragma once
#include "Entidade.hpp"
#define GRAVIDADE 980.0f

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
                Personagem(const sf::Vector2f pos, const sf::Vector2f tam, IDs::ID ID);
                virtual ~Personagem();
                void salvarDataBuffer();
                virtual void executar() = 0;
                virtual void mover() = 0;
                virtual void salvar() = 0;
                void atualizar();
                void setVelY(float Vely);
                virtual sf::RectangleShape getSprite() const = 0;
                void andar(bool paraEsq);
                void gravidade();
                void parar();
                void atualizaPosicao(); // codigo adaptado dos videos do monitor Lucas Eduardo Bonâncio Skora
            };
        }
    }
}