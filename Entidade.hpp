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
            sf::Clock relogio;
            static float dt;
            //ostream buffer;
            void salvarDataBuffer();
        public:
            Entidade(const sf::Vector2f pos,const sf::Vector2f tam,IDs::ID ID);
            virtual ~Entidade();
            sf::Vector2f getPos() const;
            void setPos(sf::Vector2f Pos);
            sf::Vector2f getTam() const;
            void setTam(sf::Vector2f Tam);
            virtual void executar() = 0;
            virtual void salvar() = 0;
            virtual sf::RectangleShape getSprite() const = 0;
        };
    }   
}

