#include "ListaEntidades.hpp"
#include "Inimigo.hpp"

namespace Castelos_e_ruinas{

    namespace Listas{

        ListaEntidades::ListaEntidades():LEs(){

        }

        ListaEntidades::~ListaEntidades(){

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
                if(pAux->getID() == IDs::ID::inimigo){
                    Entidades::Personagens::Inimigo* pInimigo = static_cast<Entidades::Personagens::Inimigo*>(pAux);
                    pInimigo->setJogador(pJ);
                }
            }
        }

        void ListaEntidades::percorrer(){
            Entidades::Entidade* pAux;
            for(int i = 0;i < LEs.getTam();i++){
                pAux = operator[](i);
                pAux->executar();
            }
        }

        void ListaEntidades::desenhar(Gerenciadores::Gerenciador_Grafico* pGG){
            Entidades::Entidade* pAux;
            for(int i = 0; i < LEs.getTam();i++){
                pAux = operator[](i);
                pAux->setGG(pGG);
                pGG->desenharEnte(static_cast<Ente*>(pAux));
            }
        }

    }
}