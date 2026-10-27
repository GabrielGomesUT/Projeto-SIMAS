#pragma once
#include "Personagem.hpp"
#define RAIO_PERSEGUICAO_X 100.0f
#define RAIO_PERSEGUICAO_Y 100.0f
#define VELOCIDADE_INIMIGO_X 1.0f
#define VELOCIDADE_INIMIGO_Y 1.0f

namespace nomeDoJogo{
    namespace Entidades{
        namespace Personagens{

            class Jogador;

            class Inimigo:public Personagem{
            protected:
                Jogador* jogador;
                sf::Clock relogio;
                short moveAleatorio;
                int nivel_maldade;
                void Inicializa();
            public:
                Inimigo(const sf::Vector2f pos, const sf::Vector2f tam,Jogador* jog);
                ~Inimigo();
                void salvarDataBuffer();
                void setJogador(Jogador* pJog);
                void persegueJogador(sf::Vector2f posJog,sf::Vector2f posInim); // codigo adaptado dos videos do monitor Lucas Eduardo Bonâncio Skora
                virtual void executar();// = 0;
                //virtual void danificar(Jogador* p) = 0;
                virtual void salvar();// = 0;
                virtual void mover(); //= 0;
                void moverAleatorio(); // codigo adaptado dos videos do monitor Lucas Eduardo Bonâncio Skora
                virtual sf::RectangleShape getSprite() const;// = 0;
            };
        }
    }
}