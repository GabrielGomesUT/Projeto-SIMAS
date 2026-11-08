#include "Ente.hpp"
#include "GerenciadorGrafico.hpp"

using namespace std;

namespace Castelos_e_ruinas{

    Gerenciadores::Gerenciador_Grafico* Ente::pGG = NULL;

    Ente::Ente(IDs::ID ID):id(ID){

    }

    Ente::~Ente(){

    }

    void Ente::desenhar(){
        if(pGG != NULL)
            pGG->desenharEnte(this);
        else
            cerr<<"Erro: ponteiro para GerenciadorGrafico nulo." <<endl;
    }

    void Ente::setGG(Gerenciadores::Gerenciador_Grafico* pG){
        pGG = pG;
    }

    IDs::ID Ente::getID(){
        return id;
    }
}
