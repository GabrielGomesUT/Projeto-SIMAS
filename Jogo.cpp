#include "Jogo.hpp"
 
namespace Castelos_e_ruinas{
    Jogo::Jogo():GG(GG->getGerenciadorGrafico()),GE(GE->getGerenciadorEventos()){
        pJog1 = new Entidades::Personagens::Jogador(sf::Vector2f(0.0f,ALTURA_TELA - 145.0f),sf::Vector2f(50.0f,50.0f));
        pCidade = new Fases::Cidade_Medieval();
        pCidade->incluirJogador(pJog1);
        GE->setJogador(pJog1);
        pCidade->conectaEntidadesGC();
        
        executar();
    }
    Jogo::~Jogo(){
        
    }
    
    void Jogo::executar(){
        while(GG->verificaWindowOpen()){
            GE->executar();
            GG->limpaWindow();
            pCidade->executar();
            GG->mostrar();
        }
    }
}