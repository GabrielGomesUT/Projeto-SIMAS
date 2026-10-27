#pragma once
#include "Entidade.hpp"

namespace nomeDoJogo{
    namespace Entidades{
        namespace Personagens{
            class Personagem:public Entidade{
            protected:
                int num_vidas;
            public:
                Personagem(int X = 0,int Y = 0);
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