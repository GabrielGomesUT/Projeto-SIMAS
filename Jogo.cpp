#include "Jogo.hpp"
#include "CidadeMedieval.hpp"
#include "Castelo.hpp"
#include "MenuPrincipal.hpp"
 
namespace Castelos_e_ruinas{
    Jogo::Jogo(Menus::MenuPrincipal* pMP):
    GG(GG->getGerenciadorGrafico()),GE(GE->getGerenciadorEventos()),pFase(NULL),pJog1(NULL),pJog2(NULL),pMenuPrincipal(pMP),
    pausado(false),sair(false){
        pJog1 = new Entidades::Personagens::Jogador(sf::Vector2f(0.0f,ALTURA_TELA - 111.0f),sf::Vector2f(50.0f,50.0f));
        //pJog2 = new Entidades::Personagens::Jogador(sf::Vector2f(10.0f,ALTURA_TELA - 145.0f),sf::Vector2f(50.0f,50.0f));
        GE->setJogador(pJog1);
        GE->setMenu(static_cast<Menus::Menu*>(pMenuPrincipal));
        GE->setJogo(this);
    }
    Jogo::~Jogo(){
        
    }

    void Jogo::criarFase(int nFase){
        if(pFase != NULL){
            delete pFase;
            pFase = NULL;
        }
        pausado = false;
        GE->setMenu(NULL);
        if(nFase == 1){
            pFase = new Fases::Cidade_Medieval();
        }
        else if(nFase == 2){
            pFase = new Fases::Castelo();
        }
        pFase->incluirJogador(pJog1);
        //pFase->incluirJogador(pJog2);
        pFase->conectaEntidadesGC();
    }

    void Jogo::pausar() {
        if ((pFase != NULL) && (!pausado) && (pMenuPrincipal != NULL)) {
            pausado = true;
            //pMenuPrincipal->ativarMenuPausa();
        }
    }

    void Jogo::continuar() {
        if (pFase != NULL && pausado) {
            pausado = false;
            GE->setMenu(NULL);
        }
    }

    void Jogo::setSair(bool s){
        sair = s;
    }
    
    void Jogo::executar(){
        while(GG->verificaWindowOpen()){
            if(sair)
                GG->closeWindow();
            GE->executar();
            GG->limpaWindow();
            if (pFase == NULL) {
                pMenuPrincipal->executar();
            }
            else if(pausado){
                //pMenuPrincipal->criarMenuPausado();
            }
            else {
                pFase->executar();
            }
            GG->mostrar();
        }
    }
}