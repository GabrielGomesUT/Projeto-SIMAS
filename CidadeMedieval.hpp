#pragma once
#include "Fase.hpp"

namespace Castelos_e_ruinas{

    namespace Fases{

        class Cidade_Medieval:public Fase{
        private:
            const int maxZumbis;
            const int maxLamas;
        protected:
            void criarInimigos();
            void criarObstaculos();
            void criarCenario();
            void criarZumbis(sf::Vector2i pos);
            void criarLamas(sf::Vector2i pos);
        public:
            Cidade_Medieval();
            ~Cidade_Medieval();
        };
    }
}