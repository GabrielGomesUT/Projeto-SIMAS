#pragma once
#include "Botao.hpp"
#include "Texto.hpp"
#define TAM_FONTE 20

namespace Castelos_e_ruinas{

    namespace Botoes{

        class BotaoTexto:public Botao{
        protected:
            Texto texto;
            sf::Color corSelecionado;
        public:
            BotaoTexto(const std::string info, const sf::Vector2f pos,const sf::Vector2f tam,sf::Color corSel);
            ~BotaoTexto();
            void executar();
        };
    }
}