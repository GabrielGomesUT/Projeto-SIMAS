#pragma once
#include "Entidade.hpp"

namespace Castelos_e_ruinas{

    namespace Entidades{

        namespace Personagens{

            class Jogador;
        }

        class Obstaculo:public Entidade{
        protected:
            bool danoso;
        public:
            Obstaculo(const sf::Vector2f pos, const sf::Vector2f tam);
            ~Obstaculo();
            void salvarDataBuffer();
            virtual void executar();// = 0;
            virtual void salvar();// = 0;
            //virtual void obstaculizar(Personagens::Jogador* p); //=0;
            virtual sf::RectangleShape getSprite() const;// = 0;
        };

    }

}