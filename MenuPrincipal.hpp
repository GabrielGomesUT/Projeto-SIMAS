#pragma once
#include "Menu.hpp"

namespace Castelos_e_ruinas{

    class Jogo;

    namespace Menus{

        class MenuPrincipal : public Menu{
        private:
            Jogo* pJogo;
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