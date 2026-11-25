#pragma once
#include "Estado.hpp"
#include "Menu.hpp"
#include "Jogador.hpp"
#include "Fase.hpp"
#include "GerenciadorEstados.hpp"

namespace Castelos_e_ruinas{

    namespace Estados{

        class EstadoMenu:public Estado{
        private:
            Menus::Menu* pMenu;
            static Gerenciadores::Gerenciador_Estados* pGEstado;
            void criarMenu();   // codigo adaptado dos videos do monitor Giovane Limas Salvi
        public:
            EstadoMenu(const IDs::ID ID);
            ~EstadoMenu();
            Menus::Menu* getMenu() const;
            Fases::Fase* getFase();
            void executar();
            //void mudarEstadoObserver();
        };
    }
}