#include "GerenciadorEventos.hpp"
#include "Jogador.hpp"
#include "Menu.hpp"
#include "Jogo.hpp"

namespace Castelos_e_ruinas{

    namespace Gerenciadores{

        Gerenciador_Eventos* Gerenciador_Eventos::pEvento(NULL);

        Gerenciador_Eventos::Gerenciador_Eventos():pGrafico(pGrafico->getGerenciadorGrafico()),pJogador(NULL),pMenu(NULL),pJogo(NULL){
            
        }
    
        Gerenciador_Eventos::~Gerenciador_Eventos(){

        }

        Gerenciador_Eventos* Gerenciador_Eventos::getGerenciadorEventos(){
            if(pEvento == NULL)
                pEvento = new Gerenciador_Eventos();
            return pEvento;
        }

        void Gerenciador_Eventos::setJogador( Entidades::Personagens::Jogador* pJ){
            pJogador = pJ;
        }

        void Gerenciador_Eventos::setMenu(Menus::Menu* pM){
            pMenu = pM;
        }

        void Gerenciador_Eventos::setJogo(Jogo* pJo){
            pJogo = pJo;
        }

        void Gerenciador_Eventos::verificaTeclaPressionada(sf::Keyboard::Key tecla){
            if(pMenu != NULL){
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
                    pGrafico->closeWindow();
                }
            }
            else{
                if((pJogo != NULL) && (tecla == sf::Keyboard::Escape)){
                    pJogo->pausar();
                }
                else if(pJogador != NULL){
                    if(tecla == sf::Keyboard::A)
                        pJogador->andar(true);
                    else if(tecla == sf::Keyboard::D)
                        pJogador->andar(false);
                    else if(tecla == sf::Keyboard::W)
                        pJogador->pular();
                }
            }
        }

        void Gerenciador_Eventos::verificaTeclaSolta(sf::Keyboard::Key tecla){
            if((pJogador != NULL) && pMenu == NULL){
                if(tecla == sf::Keyboard::A){
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                        pJogador->andar(false);
                    else
                        pJogador->parar();
                }
                else if(tecla == sf::Keyboard::D){
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
                        pJogador->andar(true);
                    else
                        pJogador->parar();
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