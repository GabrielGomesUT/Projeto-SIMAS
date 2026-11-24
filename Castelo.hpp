#pragma once
#include "Fase.hpp"

namespace Castelos_e_ruinas{

    namespace Fases{

        class Castelo:public Fase{
        private:
            const int maxDragoes;
            const int maxChamas;
        protected:
            void criarDragoes();
            void criarInimigos();
            void criarObstaculos();
            void criarChamas();
            void criarCenario();
        public:
            Castelo();
            ~Castelo();
        };
    }
}