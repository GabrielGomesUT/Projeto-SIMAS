#pragma once
#include "Ente.hpp"
#include "ListaEntidades.hpp"
#include "GerenciadorColisoes.hpp"
#include "Jogador.hpp"

namespace Castelos_e_ruinas{

    namespace Fases{
        class Fase:public Ente{
        protected:
            Listas::ListaEntidades lista_entes;
            Gerenciadores::GerenciadorColisoes GC;
            Entidades::Personagens::Jogador* pJog1;
            const int maxCavaleiros;
            const int maxPlataformas;
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
            Entidades::Personagens::Jogador* getJogador();
            void conectaEntidadesGC();
            virtual void executar();
        };
    }
}