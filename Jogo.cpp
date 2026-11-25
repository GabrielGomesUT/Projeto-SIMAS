#include "Jogo.hpp"
#include "CidadeMedieval.hpp"
#include "Castelo.hpp"
#include "MenuPrincipal.hpp"
 
namespace Castelos_e_ruinas{
    Jogo::Jogo():
    GG(GG->getGerenciadorGrafico()),GE(GE->getGerenciadorEventos()),GEs(GEs->getGerenciadorEstados()),pJog1(NULL),pJog2(NULL)
    {
        pJog1 = new Entidades::Personagens::Jogador(sf::Vector2f(0.0f,ALTURA_TELA - 111.0f),sf::Vector2f(50.0f,50.0f));
        //pJog2 = new Entidades::Personagens::Jogador(sf::Vector2f(10.0f,ALTURA_TELA - 145.0f),sf::Vector2f(50.0f,50.0f));
        GEs->setJogadores(pJog1);
        if(GEs != NULL){
            GEs->adicionarEstado(IDs::ID::menuPrincipal);
        }

        executar();
    }
    Jogo::~Jogo(){
        if(pJog1 != NULL){
            delete pJog1;
            pJog1 = NULL;
        }    
    }

    void Jogo::executar(){
        while(GG->verificaWindowOpen()){
            GE->executar();

            GG->limpaWindow();

            GEs->executar();
            
            GG->mostrar();
        }
    }
}