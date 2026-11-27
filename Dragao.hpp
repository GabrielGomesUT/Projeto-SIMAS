#pragma once
#include "Inimigo.hpp"
#define VIDA_DRAGAO 7
#define NIVEL_MALDADE_DRAGAO 10
#define VELOCIDADE_DRAGAO_X 1.0f
#define INTERVALO_DISPARO 2.5f

namespace Castelos_e_ruinas {
    namespace Entidades {

        //class Projetil; //Mesma declaração antecipada que usamos para Jogador em Inimigo.hpp

        namespace Personagens {

            class Dragao : public Inimigo {
            private:
                //Projetil* pProjetil; //Projétil do Dragão
                float tempo_disparo; //Pra controlar o intervalo entre tiros

                void atirar();

            public:
                Dragao(const sf::Vector2f pos, const sf::Vector2f tam, Jogador* pJog = NULL);
                ~Dragao();

                //void setProjetil(Projetil* pProj);

                void mover();
                void danificar(Jogador* pJog);
                void executar();
                void salvar();
            };

        }
    }
}