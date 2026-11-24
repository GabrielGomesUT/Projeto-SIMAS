#pragma once
#include "Menu.hpp"

namespace Castelos_e_ruinas{

    class Jogo;

    namespace Menus{

        class MenuPrincipal : public Menu{
        private:
            Jogo* pJogo;
            void criarBotoes();
        public:
            MenuPrincipal();
            ~MenuPrincipal();
            void criarFundo();
            void selecionar();
            void executar();
        };
    }
}