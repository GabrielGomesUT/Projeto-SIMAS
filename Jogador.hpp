#pragma once
#include "Personagem.hpp"

#define VELOCIDADE_JOGADOR_X 100.0f
#define VELOCIDADE_PULO -500.0f

namespace Castelos_e_ruinas{
    namespace Entidades{
        namespace Personagens{
            class Inimigo;
            class Jogador:public Personagem{ 
            protected:
                int pontos;
                bool podePular;
            public:
                Jogador();
                ~Jogador();
                void Inicializa();
                void colisao(Inimigo* pIn,sf::Vector2f ds);
                void setPodePular(bool b);
                void pular();
                void operator++();
                void executar();
                void salvar();
                void mover();   // codigo adaptado dos videos do monitor Lucas Eduardo Bonâncio Skora
                sf::RectangleShape getSprite() const;
            };
        }
    }
}