#include "ListaEntidades.hpp"

namespace Castelos_e_ruinas{

    namespace Listas{

        ListaEntidades::ListaEntidades(){

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

        void ListaEntidades::percorrer(Gerenciadores::Gerenciador_Grafico* pGG){
            Entidades::Entidade* pAux;
            for(int i = 0;i < LEs.getTam();i++){
                pAux = operator[](i);
                pAux->atualizar();
                pGG->desenharEnte(static_cast<Ente*>(pAux)); 
            }
        }

    }
}