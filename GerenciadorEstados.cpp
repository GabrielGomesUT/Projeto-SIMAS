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
        pilhaEstados()
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
                pEJ->setJogadores(pJog1);
                pilhaEstados.push(static_cast<Estados::Estado*>(pEJ));
            }
            else if((ID == IDs::ID::menuPrincipal) || (ID == IDs::ID::menuPause) || (ID == IDs::ID::menuFim)){
                Estados::EstadoMenu* pEM = new Estados::EstadoMenu(ID);
                pilhaEstados.push(static_cast<Estados::Estado*>(pEM));
            }
            else
                cerr<<"Nao foi possivel criar Estado"<<endl;
        }

        void Gerenciador_Estados::setJogadores(Entidades::Personagens::Jogador* pJ1){
            pJog1 = pJ1;
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