#pragma once
#include "Ente.hpp"
#include "Texto.hpp"

namespace Castelos_e_ruinas{

    namespace Botoes{

        class Botao:public Ente{
        protected:
            bool selecionado;
            float tempoAcumulado;
        public:
            Botao(const sf::Vector2f pos,const sf::Vector2f tam,IDs::ID ID);
            virtual ~Botao();
            //void atualizarTexto();
            void setSelecionado(const bool selec);
            bool getSelecionado();
            virtual void executar() = 0;
        };
    }
}