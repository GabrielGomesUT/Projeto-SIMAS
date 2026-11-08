#pragma once
#include "Ente.hpp"
#include <ostream>

namespace Castelos_e_ruinas{
    namespace Entidades{
        class Entidade:public Ente{
        protected:
            float x;
            float y;
            sf::RectangleShape corpo;
            //ostream buffer;
            void salvarDataBuffer();
        public:
            Entidade(const sf::Vector2f pos,const sf::Vector2f tam,IDs::ID ID);
            virtual ~Entidade();
            sf::Vector2f getPos() const;
            void setPos(sf::Vector2f Pos);
            sf::Vector2f getTam() const;
            virtual void atualizar() = 0;
            virtual void executar() = 0;
            virtual void salvar() = 0;
            virtual sf::RectangleShape getSprite() const = 0;
        };
    }   
}