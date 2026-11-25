#include "GerenciadorEventos.hpp"
#include "Jogador.hpp"
#include "Menu.hpp"
#include "Jogo.hpp"
#include "EstadoJogar.hpp"
#include "EstadoMenu.hpp"

namespace Castelos_e_ruinas{

    namespace Gerenciadores{

        Gerenciador_Eventos* Gerenciador_Eventos::pEvento(NULL);

        Gerenciador_Eventos::Gerenciador_Eventos():pGrafico(pGrafico->getGerenciadorGrafico()),pEstado(pEstado->getGerenciadorEstados()){
            
        }
    
        Gerenciador_Eventos::~Gerenciador_Eventos(){

        }

        Gerenciador_Eventos* Gerenciador_Eventos::getGerenciadorEventos(){
            if(pEvento == NULL)
                pEvento = new Gerenciador_Eventos();
            return pEvento;
        }

        void Gerenciador_Eventos::verificaTeclaPressionada(sf::Keyboard::Key tecla){
            if((pEstado->getEstadoAtual()->getID() == IDs::ID::cidadeMedieval) || (pEstado->getEstadoAtual()->getID() == IDs::ID::castelo)){
                Estados::EstadoJogar* pEst = dynamic_cast<Estados::EstadoJogar*>(pEstado->getEstadoAtual());
                if(pEst != NULL){
                    if (tecla == sf::Keyboard::Escape) {
                        pEstado->adicionarEstado(IDs::ID::menuPause);
                        return;
                    }
                    Entidades::Personagens::Jogador* pJogador = pEst->getJogadores();
                    if (pJogador != NULL) {
                        if (tecla == sf::Keyboard::A)
                            pJogador->andar(true);
                        else if (tecla == sf::Keyboard::D)
                            pJogador->andar(false);
                        else if (tecla == sf::Keyboard::W || tecla == sf::Keyboard::Space)
                            pJogador->pular();
                    }
                }
            }

            else if ((pEstado->getEstadoAtual()->getID() == IDs::ID::menuPrincipal) || (pEstado->getEstadoAtual()->getID() == IDs::ID::menuPause) || (pEstado->getEstadoAtual()->getID()== IDs::ID::menuFim)){
                Estados::EstadoMenu* pEstM = dynamic_cast<Estados::EstadoMenu*>(pEstado->getEstadoAtual());
                if (pEstM != NULL) {
                    Menus::Menu* pMenu = pEstM->getMenu();
                    if (pMenu != NULL) {
                        if (tecla == sf::Keyboard::Up || tecla == sf::Keyboard::W) {
                            pMenu->selecionaPCima();
                        }
                        else if (tecla == sf::Keyboard::Down || tecla == sf::Keyboard::S) {
                            pMenu->selecionaPBaixo();
                        }
                        else if (tecla == sf::Keyboard::Enter) {
                            pMenu->selecionar();
                        }
                        else if (tecla == sf::Keyboard::Escape) {
                            if (pEstado->getEstadoAtual()->getID() == IDs::ID::menuPause)
                                pEstado->removerEstado();
                            else
                                pGrafico->closeWindow();
                        }
                    }
                }
            }
        }

        void Gerenciador_Eventos::verificaTeclaSolta(sf::Keyboard::Key tecla){
            if ((pEstado->getEstadoAtual()->getID() == IDs::ID::cidadeMedieval) || (pEstado->getEstadoAtual()->getID() == IDs::ID::castelo)) {
                Estados::EstadoJogar* pEst = dynamic_cast<Estados::EstadoJogar*>(pEstado->getEstadoAtual());
                if (pEst != NULL) {
                    Entidades::Personagens::Jogador* pJogador = pEst->getJogadores();
                    if (pJogador != NULL) {
                        if (tecla == sf::Keyboard::A) {
                            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                                pJogador->andar(false);
                            else
                                pJogador->parar();
                        }
                        else if (tecla == sf::Keyboard::D) {
                            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
                                pJogador->andar(true);
                            else
                                pJogador->parar();
                        }
                    }
                }
            }
        }

        void Gerenciador_Eventos::executar(){
            sf::Event evento;
            if(pGrafico != NULL){
                while(pGrafico->getWindow()->pollEvent(evento)){
                    if(evento.type == sf::Event::KeyPressed)
                        verificaTeclaPressionada(evento.key.code);
                    else if(evento.type == sf::Event::KeyReleased)
                        verificaTeclaSolta(evento.key.code);
                    else if(evento.type == sf::Event::Closed)
                        pGrafico->closeWindow();
                }
            }
            else
                cerr<<"Ponteiro para gerenciador grafico ou jogador nao inicializado"<<endl;
        }

    }
}