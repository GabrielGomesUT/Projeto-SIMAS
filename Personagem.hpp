#pragma once
#include "Entidade.hpp"

namespace nomeDoJogo{
    namespace Entidades{
        namespace Personagens{
            class Personagem:public Entidade{
            protected:
                int num_vidas;
                sf::RectangleShape corpo;
                sf::Vector2f vel;
            public:
                Personagem(const sf::Vector2f pos, const sf::Vector2f tam);
                virtual ~Personagem();
                void salvarDataBuffer();
                virtual void executar() = 0;
                virtual void mover() = 0;
                virtual void salvar() = 0;
                virtual sf::RectangleShape getSprite() const = 0;
            };
        }
    }
}