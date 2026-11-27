#include "GerenciadorEstados.hpp"
#include "EstadoJogar.hpp"
#include "EstadoMenu.hpp"
#include <iostream>
#include "GerenciadorGrafico.hpp"
using namespace std;

namespace Castelos_e_ruinas{

    namespace Gerenciadores{

        Gerenciador_Estados* Gerenciador_Estados::pEstado = NULL;

        Gerenciador_Estados::Gerenciador_Estados():
        pilhaEstados(),pJog1(NULL),pJog2(NULL),Fase(),solo(true),transicao(false)
        {

        }

        Gerenciador_Estados::~Gerenciador_Estados(){
            while(!pilhaEstados.empty()){
                delete(pilhaEstados.top());
                pilhaEstados.top() = NULL;
                pilhaEstados.pop();
            }

            if(pEstado != NULL){
                pEstado = NULL;
            }
        }
        
        Gerenciador_Estados* Gerenciador_Estados::getGerenciadorEstados(){
            if(pEstado == NULL)
                pEstado = new Gerenciador_Estados();
            return pEstado;
        }        
        
        void Gerenciador_Estados::adicionarEstado(IDs::ID ID){
            if((ID == IDs::ID::cidadeMedieval) || (ID == IDs::ID::castelo)){
                Estados::EstadoJogar* pEJ = new Estados::EstadoJogar(ID);
                if(ID == IDs::ID::cidadeMedieval){
                    if(pJog1 != NULL)
                        pJog1->inicializa();
                    if((!solo) && (pJog2 != NULL))
                        pJog2->inicializa();
                }
                else if(ID == IDs::ID::castelo){
                    if((pJog1 != NULL) && (transicao))
                        pJog1->recuperaAtributos();
                    else if(!transicao)
                        pJog1->inicializa();

                    if((!solo) && (pJog2 != NULL) && (transicao))
                        pJog2->recuperaAtributos();
                    else if(!transicao)
                        pJog2->inicializa();
                }
                if(solo)
                    pJog2->setAtivo(false);    
                pEJ->setJogadores(pJog1,pJog2);
                pilhaEstados.push(static_cast<Estados::Estado*>(pEJ));
            }
            else if((ID == IDs::ID::menuPrincipal) || (ID == IDs::ID::menuPause) || (ID == IDs::ID::menuFim) || (ID == IDs::ID::menuJogador) || (ID == IDs::ID::menuColocacao)){
                Estados::EstadoMenu* pEM = new Estados::EstadoMenu(ID);
                pilhaEstados.push(static_cast<Estados::Estado*>(pEM));
            }
            else
                cerr<<"Nao foi possivel criar Estado"<<endl;
        }

        void Gerenciador_Estados::setSolo(bool Solo){
            solo = Solo;
        }

        void Gerenciador_Estados::setNFase(IDs::ID nFase){
            Fase = nFase;
        }

        void Gerenciador_Estados::setTransicao(bool Transicao){
            transicao = Transicao;
        }

        IDs::ID Gerenciador_Estados::getNFase(){
            return Fase;
        }

        void Gerenciador_Estados::setJogadores(Entidades::Personagens::Jogador* pJ1,Entidades::Personagens::Jogador* pJ2){
            pJog1 = pJ1;
            pJog2 = pJ2;
        }

        Entidades::Personagens::Jogador* Gerenciador_Estados::getJogador1(){
            return pJog1;
        }
        Entidades::Personagens::Jogador* Gerenciador_Estados::getJogador2(){
            return pJog2;
        }

        void Gerenciador_Estados::removerEstado(){
            if(!pilhaEstados.empty()){
                Estados::Estado* pAux = pilhaEstados.top();
                pilhaEstados.pop();
                if (pAux != NULL) {
                    delete pAux;
                    pAux = NULL;
                }
            }

            if(pilhaEstados.empty()){
                Gerenciador_Grafico* pG = pG->getGerenciadorGrafico();
                pG->closeWindow();
            }
        }

        void Gerenciador_Estados::trocarEstado(IDs::ID ID){
            removerEstado();
            adicionarEstado(ID);
            transicao = false;
        }

        Estados::Estado* Gerenciador_Estados::getEstadoAtual(){
            if(!pilhaEstados.empty())
                return pilhaEstados.top();
            return NULL;
        }

        void Gerenciador_Estados::executar(){
            if(!pilhaEstados.empty())
                pilhaEstados.top()->executar();
        }
    }
}