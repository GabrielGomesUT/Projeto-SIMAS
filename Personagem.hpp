#pragma once
#include "Entidade.hpp"

namespace Castelos_e_ruinas{
    namespace Entidades{
        namespace Personagens{
            class Personagem:public Entidade{
            protected:
                int num_vidas;
                int vida_max;
                bool podeAndar;
                bool paraEsquerda;
                sf::RectangleShape barraVida;
                sf::RectangleShape barraFundo;
                
            public:
                Personagem(const sf::Vector2f pos, const sf::Vector2f tam, IDs::ID ID);
                virtual ~Personagem();
                void salvarDataBuffer();
                virtual void executar() = 0;
                virtual void mover() = 0;
                virtual void salvar() = 0;
                int getNumVida();
                void inicializaBarraVida();
                void atualizaBarraVida();
                void operator++();
                void operator--();
                void andar(bool paraEsq);
                void parar();
                void atualizaPosicao(); // codigo adaptado dos videos do monitor Lucas Eduardo Bonâncio Skora
                void operator--();
            };
        }
    }
}
