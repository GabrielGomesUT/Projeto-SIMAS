#pragma once
#include "Menu.hpp"

namespace Castelos_e_ruinas{

    namespace Menus{

        class MenuFim:public Menu{
        private:
            void criarBotoes();
            void criarFundo();
        public:
            MenuFim();
            ~MenuFim();
            void selecionar();
            void executar();
        };
    }
}