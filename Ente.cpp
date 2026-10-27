#include "Ente.hpp"
#include "GerenciadorGrafico.hpp"

using namespace std;

namespace nomeDoJogo{

    Gerenciadores::Gerenciador_Grafico* Ente::pGG = NULL;

    int Ente::cont(0); 

    Ente::Ente():id(cont++){

    }

    Ente::~Ente(){

    }

    void Ente::desenhar(){
        if(pGG != NULL)
            pGG->desenharEnte(this);
        else
            cerr<<"Erro: ponteiro para GerenciadorGrafico nulo." <<endl;
    }

    void Ente::setGG(nomeDoJogo::Gerenciadores::Gerenciador_Grafico* pG){
        pGG = pG;
    }

    int Ente::getID(){
        return id;
    }
}
