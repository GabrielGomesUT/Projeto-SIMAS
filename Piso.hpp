#pragma once
#include "Entidade.hpp"

namespace Castelos_e_ruinas{
    namespace Entidades{

        namespace Personagens{

            class Personagem;
        }

        class Piso:public Entidade{
        private:
            float tempo_acumulado;
        public:
            Piso(const sf::Vector2f pos, const sf::Vector2f tam);
            ~Piso();
            void colisao(Personagens::Personagem* pPer,sf::Vector2f ds);
            void executar();
            void salvar();
        }; 
    }
}
