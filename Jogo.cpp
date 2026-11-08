#include "Jogo.hpp"
 
namespace Castelos_e_ruinas{
    Jogo::Jogo():GG(GG->getGerenciadorGrafico()),GE(GE->getGerenciadorEventos()),GC(){
        pJog1 = new Entidades::Personagens::Jogador();
        GE->setJogador(pJog1);
        Entidades::Personagens::Inimigo* pIni = NULL;
        Entidades::Obstaculo* pObs = NULL;
        Entidades::Obstaculo* pObs2 = NULL;
        pIni = new Entidades::Personagens::Inimigo(sf::Vector2f(300.0f,300.0f),sf::Vector2f(50.0f,50.0f),pJog1);
        pObs = new Entidades::Obstaculo(sf::Vector2f(0.0f,400.0f),sf::Vector2f(800.0f,100.0f));
        pObs2 = new Entidades::Obstaculo(sf::Vector2f(100.0f,200.0f),sf::Vector2f(400.0f,100.0f));

        ListaEnt.incluirEntidades(static_cast<Entidades::Entidade*> (pJog1));
        ListaEnt.incluirEntidades(static_cast<Entidades::Entidade*> (pObs));
        ListaEnt.incluirEntidades(static_cast<Entidades::Entidade*> (pIni));
        ListaEnt.incluirEntidades(static_cast<Entidades::Entidade*> (pObs2));
        GC.conectaEntidades(&ListaEnt);
        
        executar();
    }
    Jogo::~Jogo(){
        
    }
    
    void Jogo::executar(){
        while(GG->verificaWindowOpen()){
            GE->executar();
            GG->limpaWindow();
            ListaEnt.percorrer(GG);
            GG->mostrar();
            GC.executar();
        }
    }
}