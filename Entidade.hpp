#pragma once
#include "Ente.hpp"
#include <ostream>

namespace nomeDoJogo{
    namespace Entidades{
        class Entidade:public Ente{
        protected:
            int x;
            int y;
            //ostream buffer;
            void salvarDataBuffer();
        public:
            Entidade(int X = 0,int Y = 0);
            virtual ~Entidade();
            virtual void executar() = 0;
            virtual void salvar() = 0;
            virtual sf::RectangleShape getSprite() const = 0;
        };
    }   
}