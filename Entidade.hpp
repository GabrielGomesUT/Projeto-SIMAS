#pragma once
#include "Ente.hpp"
#include <ostream>

namespace nomeDoJogo{
    namespace Entidades{
        class Entidade:public Ente{
        protected:
            float x;
            float y;
            sf::RectangleShape corpo;
            //ostream buffer;
            void salvarDataBuffer();
        public:
            Entidade(const sf::Vector2f pos,const sf::Vector2f tam);
            virtual ~Entidade();
            virtual void executar() = 0;
            virtual void salvar() = 0;
            virtual sf::RectangleShape getSprite() const = 0;
        };
    }   
}