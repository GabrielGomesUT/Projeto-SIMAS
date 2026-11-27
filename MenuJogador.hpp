#pragma once
#include "Menu.hpp"


namespace Castelos_e_ruinas{

    namespace Menus{

        class MenuJogador : public Menu{
        private:
            void criarBotoes();
            void criarFundo();
        public:
            MenuJogador();
            ~MenuJogador();
            void selecionar();
            void executar();
        };
    }
}