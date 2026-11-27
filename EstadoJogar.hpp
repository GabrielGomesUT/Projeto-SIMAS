#pragma once
#include "Estado.hpp"
#include "Fase.hpp"
#include "Jogador.hpp"

namespace Castelos_e_ruinas{

    namespace Estados{

        class EstadoJogar:public Estado{
        private:
            Fases::Fase* pFase;
            void criarCidadeMedieval();
            void criarCastelo();
        public:
            EstadoJogar(const IDs::ID ID);
            ~EstadoJogar();
            void setJogadores(Entidades::Personagens::Jogador* pJ,Entidades::Personagens::Jogador* pJ2);
            Entidades::Personagens::Jogador* getJogador1();
            Entidades::Personagens::Jogador* getJogador2();
            Fases::Fase* getFase();
            void executar();
        };
    }
}