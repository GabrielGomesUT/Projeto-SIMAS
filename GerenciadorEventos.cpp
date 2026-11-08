#include "GerenciadorEventos.hpp"
#include "Jogador.hpp"

namespace Castelos_e_ruinas{

    namespace Gerenciadores{

        Gerenciador_Eventos* Gerenciador_Eventos::pEvento(NULL);

        Gerenciador_Eventos::Gerenciador_Eventos():pGrafico(pGrafico->getGerenciadorGrafico()),pJogador(){
            
        }

        Gerenciador_Eventos::~Gerenciador_Eventos(){

        }

        Gerenciador_Eventos* Gerenciador_Eventos::getGerenciadorEventos(){
            if(pEvento == NULL)
                pEvento = new Gerenciador_Eventos();
            return pEvento;
        }

        void Gerenciador_Eventos::setJogador( Entidades::Personagens::Jogador* pJ){
            if(pJ != NULL)
                this->pJogador = pJ;
            else
                cerr<<"Ponteiro nulo passado por parametro"<<endl;
        }

        void Gerenciador_Eventos::verificaTeclaPressionada(sf::Keyboard::Key tecla){
            if(tecla == sf::Keyboard::A)
                pJogador->andar(true);
            else if(tecla == sf::Keyboard::D)
                pJogador->andar(false);
            else if(tecla == sf::Keyboard::W)
                pJogador->pular();
            else if(tecla == sf::Keyboard::Escape)
                pGrafico->closeWindow();
        }

        void Gerenciador_Eventos::verificaTeclaSolta(sf::Keyboard::Key tecla){
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

        void Gerenciador_Eventos::executar(){
            sf::Event evento;
            if((pGrafico != NULL) && (pJogador != NULL)){
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