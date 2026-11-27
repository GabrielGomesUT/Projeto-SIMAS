#pragma once
#include "Personagem.hpp"

#define VIDA_JOGADOR 15
#define VELOCIDADE_JOGADOR_X 1.3f
#define VELOCIDADE_PULO -9.8f

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
                Jogador(const sf::Vector2f pos, const sf::Vector2f tam,sf::Color cor);
                Jogador();
                ~Jogador();
                void inicializa();
                void recuperaAtributos();
                void colisao(Inimigo* pIn,sf::Vector2f ds);
                void setPodePular(bool b);
                void desaceleracao(float f_lent);
                void setPontos(int pTs);
                int getPontos();
                void pular();
                void executar();
                void salvar();
                void mover();   // codigo adaptado dos videos do monitor Giovane Limas Salvi
            };
        }
    }
}