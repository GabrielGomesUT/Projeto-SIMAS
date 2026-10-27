#include "Jogo.hpp"

namespace nomeDoJogo{
    Jogo::Jogo():GG(GG->getGerenciadorGrafico()){
        pJog1 = new Entidades::Personagens::Jogador(sf::RectangleShape(sf::Vector2f(50.0f,50.0f)));
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
            pJog1->mover();
            GG->desenharEnte(static_cast<Ente*>(pJog1));
            GG->mostrar();
        }
    }
}