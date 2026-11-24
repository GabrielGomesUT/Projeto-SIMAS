/*#pragma once
#include "Menu.hpp"
#include "Fase.hpp"

namespace Castelos_e_ruinas{

    namespace Menus{

        class MenuPause:public Menu{
        private:
            Fases::Fase* pFase;
            void criarFundos();
            void atualizarNomeFundo();

        public:
            MenuPause(Fases::Fase* pF);
            ~MenuPause();
            void setFase(Fases::Fase* pFa);
            void executar();
        };
    }
}*/