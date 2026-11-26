#pragma once
#include "Ente.hpp"
#include "Texto.hpp"

namespace Castelos_e_ruinas{

    namespace Botoes{

        class Botao:public Ente{    // codigo adaptado dos videos do monitor Giovane Limas Salvi
        protected:
            bool selecionado;
        public:
            Botao(const sf::Vector2f pos,const sf::Vector2f tam,IDs::ID ID);
            virtual ~Botao();
            void setSelecionado(const bool selec);
            bool getSelecionado();
            virtual void executar() = 0;
        };
    }
}