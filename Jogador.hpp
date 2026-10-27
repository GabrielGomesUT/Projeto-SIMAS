#pragma once
#include "Personagem.hpp"

namespace nomeDoJogo{
    namespace Entidades{
        namespace Personagens{
            //class Inimigo;
            class Jogador:public Personagem{ // codigo adaptado dos videos do monitor Lucas Eduardo Bonâncio Skora
            protected:
                int pontos;
                sf::RectangleShape corpo;
                sf::Vector2f vel;
            public:
                Jogador(const sf::Vector2f pos, const sf::Vector2f tam);
                Jogador(const sf::RectangleShape corpo);
                Jogador();
                ~Jogador();
                void Inicializa();
                //void colidir(Inimigo* pIn);
                void executar();
                void salvar();
                void mover();
                sf::RectangleShape getSprite() const;
            };
        }
    }
}