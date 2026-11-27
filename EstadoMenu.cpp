#include "EstadoMenu.hpp"
#include "MenuPrincipal.hpp"
#include "MenuPause.hpp"
#include "EstadoJogar.hpp"
#include "MenuFim.hpp"
#include "MenuJogador.hpp"
#include "MenuColocacao.hpp"

namespace Castelos_e_ruinas {

    namespace Estados{

        EstadoMenu::EstadoMenu(const IDs::ID ID) :
            Estado(ID),pMenu(NULL)
        {
            criarMenu();
        }

        EstadoMenu::~EstadoMenu() {
            if (pMenu != NULL) {
                delete pMenu;
                pMenu = NULL;
            }
        }

        void EstadoMenu::criarMenu(){
            Estado* estadoAtual = pGEstado->getEstadoAtual();
            Fases::Fase* pFase = NULL;
            if(estadoAtual != NULL){
                if(estadoAtual->getID() == IDs::ID::cidadeMedieval || estadoAtual->getID() == IDs::ID::castelo){
                    EstadoJogar* estadoJogar = static_cast<EstadoJogar*>(estadoAtual);
                    pFase = estadoJogar->getFase();
                }
                else if(estadoAtual->getID() == IDs::ID::menuPause){
                    EstadoMenu* estadoMenu = static_cast<EstadoMenu*>(estadoAtual);
                    pFase = estadoMenu->getFase();
                }
            }
            if (this->getID() == IDs::ID::menuPrincipal) {
                if (pMenu != NULL) {
                    delete pMenu;
                    pMenu = NULL;
                }
                pMenu = new Menus::MenuPrincipal();
            }

            else if (this->getID() == IDs::ID::menuPause) {
                if (pMenu != NULL) {
                    delete pMenu;
                    pMenu = NULL;
                }
                pMenu = new Menus::MenuPause(pFase);
            }

            else if (this->getID() == IDs::ID::menuFim) {
                if (pMenu != NULL) {
                    delete pMenu;
                    pMenu = NULL;
                }
                pMenu = new Menus::MenuFim();
                Menus::MenuFim* menuFim = dynamic_cast<Menus::MenuFim*>(pMenu);
                menuFim->setPontos(pGEstado->getJogador1(),pGEstado->getJogador2());
            }

            else if (this->getID() == IDs::ID::menuJogador){
                if(pMenu != NULL){
                    delete pMenu;
                    pMenu = NULL;
                }
                pMenu = new Menus::MenuJogador(); 
            }

            else if (this->getID() == IDs::ID::menuColocacao){
                if(pMenu != NULL){
                    delete pMenu;
                    pMenu = NULL;
                }
                pMenu = new Menus::MenuColocacao(); 
            }
        }

        Menus::Menu* EstadoMenu::getMenu() const {
            return pMenu;
        }

        Fases::Fase* EstadoMenu::getFase(){
            if(pMenu->getID() == IDs::ID::menuPause ){
                Menus::MenuPause* menuFase = dynamic_cast<Menus::MenuPause*>(pMenu);
                return menuFase->getFase();
            }
            return NULL;
        }

        void EstadoMenu::executar() {
            if (pMenu != NULL) {
                pMenu->executar();
            }
        }

    }
}