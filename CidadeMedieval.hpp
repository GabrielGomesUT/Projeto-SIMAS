#pragma once
#include "Fase.hpp"

namespace Castelos_e_ruinas{

    namespace Fases{

        class Cidade_Medieval:public Fase{
        private:
            const int maxZumbis;
        protected:
            void criarZumbis();
            void criarInimigos();
            void criarObstaculos();
            void criarLamas();
            void criarCenario();
        public:
            Cidade_Medieval();
            ~Cidade_Medieval();
        };
    }
}