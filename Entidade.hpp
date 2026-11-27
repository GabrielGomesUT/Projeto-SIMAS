#pragma once
#include "Ente.hpp"
#include <ostream>
#define GRAVIDADE 0.25f

namespace Castelos_e_ruinas{
    namespace Entidades{
        class Entidade:public Ente{
        protected:
            float x;
            float y;
            bool ativo;
            int coolDown;
            sf::Vector2f vel;
            //ostream buffer;
            void salvarDataBuffer();
        public:
            Entidade(const sf::Vector2f pos,const sf::Vector2f tam,IDs::ID ID);
            virtual ~Entidade();
            sf::Vector2f getPos() const;
            void setPos(sf::Vector2f Pos);
            sf::Vector2f getTam() const;
            void setTam(sf::Vector2f Tam);
            void setAtivo(const bool Ativo);
            void setVelY(float Vely);
            void setVelX(float Velx);
            sf::Vector2f getVel();
            bool getAtivo();
            void gravidade();
            virtual void executar() = 0;
            virtual void salvar() = 0;
        };
    }   
}

