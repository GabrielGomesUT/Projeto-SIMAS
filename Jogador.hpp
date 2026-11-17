#pragma once
#include "Personagem.hpp"

#define VELOCIDADE_JOGADOR_X 140.0f
#define VELOCIDADE_PULO -630.0f

namespace Castelos_e_ruinas{
    namespace Entidades{
        namespace Personagens{
            class Inimigo;
            class Jogador:public Personagem{ 
            protected:
                int pontos;
                bool podePular;
                float vel_lentidao;
                bool lentidao;
            public:
                Jogador(const sf::Vector2f pos, const sf::Vector2f tam);
                Jogador();
                ~Jogador();
                void colisao(Inimigo* pIn,sf::Vector2f ds);
                void setPodePular(bool b);
                void desaceleracao(float f_lent);
                void pular();
                void operator++();
                void executar();
                void salvar();
                void mover();   // codigo adaptado dos videos do monitor Lucas Eduardo Bonâncio Skora
            };
        }
    }
}