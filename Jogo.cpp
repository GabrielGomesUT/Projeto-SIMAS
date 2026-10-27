#include "Jogo.hpp"
 
namespace nomeDoJogo{
    Jogo::Jogo():GG(GG->getGerenciadorGrafico()){
        pJog1 = new Entidades::Personagens::Jogador();
        Entidades::Personagens::Inimigo* pIni = NULL;
        pIni = new Entidades::Personagens::Inimigo(sf::Vector2f(300.0f,300.0f),sf::Vector2f(50.0f,50.0f),pJog1);

        vetPersonagens.push_back(static_cast<Entidades::Personagens::Personagem*>(pJog1)); 
        vetPersonagens.push_back(static_cast<Entidades::Personagens::Personagem*>(pIni)); 

        executar();
    }
    Jogo::~Jogo(){
        
    }
    void Jogo::executar(){
        while(GG->verificaWindowOpen()){
            sf::Event evento;
            if(GG->getWindow()->pollEvent(evento)){
                if(evento.type == sf::Event::Closed)
                    GG->closeWindow();
                else if(evento.type == sf::Event::KeyPressed){
                    if(evento.key.code == sf::Keyboard::Escape){
                        GG->closeWindow();
                    }
                }
            }
            GG->limpaWindow();
            for(int i = 0; i < vetPersonagens.size();i++){
                Entidades::Personagens::Personagem* pPers = vetPersonagens[i];
                pPers->mover();
                GG->desenharEnte(static_cast<Ente*>(pPers));
                pPers = NULL;
            }
            GG->mostrar();
        }
    }
}