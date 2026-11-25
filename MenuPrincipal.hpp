#pragma once
#include "Menu.hpp"

namespace Castelos_e_ruinas{

    namespace Menus{

        class MenuPrincipal : public Menu{
        private:
            void criarBotoes();
            void criarFundo();
        public:
            MenuPrincipal();
            ~MenuPrincipal();
            void selecionar();
            void executar();
        };
    }
}