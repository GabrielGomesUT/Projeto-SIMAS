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

        void EstadoJogar::setJogadores(Entidades::Personagens::Jogador* pJ){
            pFase->incluirJogador(pJ);
            pFase->conectaEntidadesGC();
        }

        Entidades::Personagens::Jogador* EstadoJogar::getJogadores(){
            return pFase->getJogador();
        }

        Fases::Fase* EstadoJogar::getFase(){
            return pFase;
        }

        void EstadoJogar::executar(){
            pFase->executar();
        }
    }
}