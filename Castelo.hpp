#pragma once
#include "Fase.hpp"

namespace Castelos_e_ruinas{

    namespace Fases{

        class Castelo:public Fase{
        private:
            const int maxDragoes;
            const int maxChamas;
        protected:
            void criarInimigos();
            void criarObstaculos();
            void criarCenario();
            void criarDragoes(sf::Vector2i pos);
            void criarChamas(sf::Vector2i pos);
        public:
            Castelo();
            ~Castelo();
        };
    }
}