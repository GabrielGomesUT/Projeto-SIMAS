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
            sf::RectangleShape cenario;
            void criarInimFaceis();
            void criarPlataformas();
            void criarCenario();
            void criarPiso();
            /*virtual*/ void criarObstaculos(); //= 0;
            /*virtual*/ void criarInimigos(); //= 0;
        public:
            Fase();
            /*virtual*/ ~Fase();
            void incluirJogador(Entidades::Personagens::Jogador* pJ);
            void desenharEntidades(Gerenciadores::Gerenciador_Grafico* pGG);
            /*virtual*/ void executar();
            void atualizar();
            void salvar();
            void conectaEntidadesGC();
            /*virtual*/ sf::RectangleShape getSprite() const;
        };
    }
}