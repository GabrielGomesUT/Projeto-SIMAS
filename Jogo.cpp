#include "Jogo.hpp"
 
namespace nomeDoJogo{
    Jogo::Jogo():GG(GG->getGerenciadorGrafico()),GE(GE->getGerenciadorEventos()){
        pJog1 = new Entidades::Personagens::Jogador();
        GE->setJogador(pJog1);
        Entidades::Personagens::Inimigo* pIni = NULL;
        Entidades::Obstaculo* pObs = NULL;
        pIni = new Entidades::Personagens::Inimigo(sf::Vector2f(300.0f,300.0f),sf::Vector2f(50.0f,50.0f),pJog1);
        pObs = new Entidades::Obstaculo(sf::Vector2f(0.0f,400.0f),sf::Vector2f(800.0f,100.0f));

        vetPersonagens.push_back(static_cast<Entidades::Personagens::Personagem*>(pJog1)); 
        vetPersonagens.push_back(static_cast<Entidades::Personagens::Personagem*>(pIni)); 
        vetObstaculos.push_back(static_cast<Entidades::Entidade*>(pObs));

        executar();
    }
    Jogo::~Jogo(){
        
    }
    void Jogo::executar(){
        while(GG->verificaWindowOpen()){
            GE->executar();
            GG->limpaWindow();
            for(int i = 0; i < vetPersonagens.size();i++){
                Entidades::Personagens::Personagem* pPers = vetPersonagens[i];
                pPers->mover();
                GG->desenharEnte(static_cast<Ente*>(pPers));
                pPers = NULL;
            }
            GG->desenharEnte(static_cast<Ente*>(vetObstaculos[0]));
            GG->mostrar();
        }
    }
}