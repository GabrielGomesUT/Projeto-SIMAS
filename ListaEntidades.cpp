#include "ListaEntidades.hpp"
#include "Inimigo.hpp"

namespace Castelos_e_ruinas{

    namespace Listas{

        ListaEntidades::ListaEntidades():LEs(){

        }

        ListaEntidades::~ListaEntidades(){
            LEs.limpar();
        }

        void ListaEntidades::incluirEntidades(Entidades::Entidade* pEnt){
            LEs.incluirInfo(pEnt);
        }

        void ListaEntidades::removerEntidades(Entidades::Entidade* pE){
            LEs.removeElemento(pE);
        }

        Entidades::Entidade* ListaEntidades::operator[](int pos){
            return LEs.operator[](pos);
        }

        int ListaEntidades::getTam(){
            return LEs.getTam();
        }

        void ListaEntidades::setJogEnt(Entidades::Personagens::Jogador* pJ){
            Entidades::Entidade* pAux;
            for(int i = 0; i < LEs.getTam();i++){
                pAux = operator[](i);
                if((pAux->getID() == IDs::ID::cavaleiro) || (pAux->getID() == IDs::ID::zumbi) || (pAux->getID() == IDs::ID::dragao)){
                    Entidades::Personagens::Inimigo* pInimigo = static_cast<Entidades::Personagens::Inimigo*>(pAux);
                    pInimigo->setJogador(pJ);
                }
            }
        }

        void ListaEntidades::verificarMortos(){
            Entidades::Entidade* pAux;
            for(int i = 0;i < LEs.getTam();i++){
                pAux = operator[](i);
                if(pAux != NULL){
                    Entidades::Personagens::Personagem* pPers = dynamic_cast<Entidades::Personagens::Personagem*>(pAux);
                    if((pPers != NULL) && (pPers->getNumVida() <= 0) && (pPers->getAtivo())){
                        pPers->setAtivo(false);
                    }
                }
            }
        }

        int ListaEntidades::getInimigosAtivos(){
            int cont = 0;
            for(int i = 0; i < LEs.getTam();i++){
                Entidades::Entidade* pAux = operator[](i);
                if((pAux->getID() == IDs::ID::cavaleiro) || (pAux->getID() == IDs::ID::zumbi) || (pAux->getID() == IDs::ID::dragao)){
                    if(pAux->getAtivo())
                        cont++;
                }
            }
            return cont;
        }

        void ListaEntidades::percorrer(){
            Entidades::Entidade* pAux;
            for(int i = 0;i < LEs.getTam();i++){
                pAux = operator[](i);
                if((pAux != NULL) && (pAux->getAtivo()))
                    pAux->executar();
            }
        }

        void ListaEntidades::desenhar(){
            Entidades::Entidade* pAux;
            for(int i = 0; i < LEs.getTam();i++){
                pAux = operator[](i);
                if((pAux != NULL) && (pAux->getAtivo()))
                    pAux->desenhar();
            }
        }

    }
}