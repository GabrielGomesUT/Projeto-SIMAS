#include "EstadoJogar.hpp"
#include "CidadeMedieval.hpp"
#include "Castelo.hpp"

namespace Castelos_e_ruinas{

    namespace Estados{

        EstadoJogar::EstadoJogar(IDs::ID ID):
        Estado(ID),pFase(NULL){
            if(ID == IDs::ID::cidadeMedieval)
                criarCidadeMedieval();
            else if (ID == IDs::ID::castelo)
                criarCastelo();
        }

        EstadoJogar::~EstadoJogar(){
            if(pFase != NULL){
                delete pFase;
                pFase = NULL;
            }
        }

        void EstadoJogar::criarCidadeMedieval(){
            if(pFase != NULL){
                delete pFase;
            }
            pFase = new Fases::Cidade_Medieval();
        }

        void EstadoJogar::criarCastelo(){
            if(pFase != NULL){
                delete pFase;
            }
            pFase = new Fases::Castelo();
        }

        void EstadoJogar::setJogadores(Entidades::Personagens::Jogador* pJ,Entidades::Personagens::Jogador* pJ2){
            pFase->incluirJogador(pJ,pJ2);
            pFase->conectaEntidadesGC();
        }

        Entidades::Personagens::Jogador* EstadoJogar::getJogador1(){
            return pFase->getJogador1();
        }

        Entidades::Personagens::Jogador* EstadoJogar::getJogador2(){
            return pFase->getJogador2();
        }

        Fases::Fase* EstadoJogar::getFase(){
            return pFase;
        }

        void EstadoJogar::executar(){
            pFase->executar();

            if(pFase->getConclusao()){
                IDs::ID IDatual = this->getID();
                if((IDatual == IDs::ID::cidadeMedieval) && ((pFase->getJogador1()->getAtivo()) || (pFase->getJogador2()->getAtivo()))){
                    pGEstado->setTransicao(true);
                    pGEstado->trocarEstado(IDs::ID::castelo);
                }
                else{
                    pGEstado->trocarEstado(IDs::ID::menuFim);
                }
            }
        }
    }
}