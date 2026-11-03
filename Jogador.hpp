#pragma once
#include "Personagem.hpp"

#define VELOCIDADE_JOGADOR_X 100.0f
#define VELOCIDADE_JOGADOR_Y 100.0f

namespace Castelos_e_ruinas{
    namespace Entidades{
        namespace Personagens{
            class Inimigo;
            class Jogador:public Personagem{ 
            protected:
                int pontos;
            public:
                Jogador();
                ~Jogador();
                void Inicializa();
                void colidir(Inimigo* pIn);
                void operator++();
                void executar();
                void salvar();
                void mover();   // codigo adaptado dos videos do monitor Lucas Eduardo Bonâncio Skora
                sf::RectangleShape getSprite() const;
            };
        }
    }
}