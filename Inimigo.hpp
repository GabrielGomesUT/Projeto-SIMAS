#pragma once
#include "Personagem.hpp"
#define RAIO_PERSEGUICAO_X 200.0f
#define RAIO_PERSEGUICAO_Y 200.0f

namespace Castelos_e_ruinas{
    namespace Entidades{
        namespace Personagens{

            class Jogador;

            class Inimigo:public Personagem{
            protected:
                Jogador* jogador;
                short moveAleatorio;
                int nivel_maldade;
                float tempo_acumulado;
            public:
                Inimigo(const sf::Vector2f pos, const sf::Vector2f tam,IDs::ID ID);
                virtual ~Inimigo(); //Eduardo: virtual, pois outras classes lidam com Inimigo
                void salvarDataBuffer();
                void setJogador(Jogador* pJog);
                void persegueJogador(sf::Vector2f posJog,sf::Vector2f posInim); // codigo adaptado dos videos do monitor Giovane Limas Salvi
                virtual void executar() = 0; //Eduardo
                virtual void danificar(Jogador* pJog) = 0; //Eduardo
                virtual void salvar() = 0; //Eduardo
                virtual void mover();
                void moverAleatorio(); // codigo adaptado dos videos do monitor Giovane Limas Salvi
            };
        }
    }
}