#pragma once
#include "Ente.hpp"
#include "ListaEntidades.hpp"
#include "GerenciadorColisoes.hpp"

namespace Castelos_e_ruinas{

    namespace Fases{
        class Fase:public Ente{
        protected:
            Listas::ListaEntidades lista_entes;
            Gerenciadores::GerenciadorColisoes GC;
            void criarCavaleiros();
            void criarPlataformas();
            void criarPiso();
            virtual void criarObstaculos() = 0;
            virtual void criarInimigos() = 0;
            virtual void criarCenario() = 0;
            void salvar();
        public:
            Fase(IDs::ID ID);
            virtual ~Fase();
            void desenharEntidades();
            void incluirJogador(Entidades::Personagens::Jogador* pJ);
            void conectaEntidadesGC();
            virtual void executar();
        };
    }
}