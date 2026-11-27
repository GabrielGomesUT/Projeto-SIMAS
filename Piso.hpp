#pragma once
#include "Entidade.hpp"

namespace Castelos_e_ruinas{
    namespace Entidades{

        namespace Personagens{

            class Personagem;
            class Jogador;
        }

        class Piso:public Entidade{
        private:
            bool ajuda;
        public:
            Piso(const sf::Vector2f pos, const sf::Vector2f tam);
            ~Piso();
            void colisao(Personagens::Personagem* pPer,sf::Vector2f ds);
            void ajudar(Entidades::Personagens::Jogador* pJ);
            void executar();
            void salvar();
        }; 
    }
}
