#pragma once
#include "Ente.hpp"
#include "ListaEntidades.hpp"
#include "GerenciadorColisoes.hpp"
#include "Jogador.hpp"
#include <fstream>
#define TAM_TILE 60.0f

namespace Castelos_e_ruinas{

    namespace Fases{
        class Fase:public Ente{
        protected:
            Listas::ListaEntidades lista_entes;
            Gerenciadores::GerenciadorColisoes GC;
            Entidades::Personagens::Jogador* pJog1;
            Entidades::Personagens::Jogador* pJog2;
            const int maxCavaleiros;
            const int maxPlataformas;
            bool concluida;
            void criarCavaleiros(sf::Vector2i pos);
            void criarPlataformas(sf::Vector2i pos);
            void criarPiso(sf::Vector2i pos);
            virtual void criarObstaculos() = 0;
            virtual void criarInimigos() = 0;
            virtual void criarCenario() = 0;
            void salvar();
        public:
            Fase(IDs::ID ID);
            virtual ~Fase();
            void desenharEntidades();
            void incluirJogador(Entidades::Personagens::Jogador* pJ,Entidades::Personagens::Jogador* pJ2);
            Entidades::Personagens::Jogador* getJogador1();
            Entidades::Personagens::Jogador* getJogador2();
            void conectaEntidadesGC();
            void verificaConclusao();
            bool getConclusao();
            virtual void executar();
        };
    }
}