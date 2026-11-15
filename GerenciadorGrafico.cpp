#include "GerenciadorGrafico.hpp"
#include<iostream>
#include <sstream>
using namespace std;
using namespace Castelos_e_ruinas;
using namespace Gerenciadores;

Gerenciador_Grafico::Gerenciador_Grafico(){     //código adaptado dos alunos Marco Antônio Kochem Vendramin e Raphael Bassil Costa Geraldine do PETECO
    window = new sf::RenderWindow(sf::VideoMode(LARGURA_TELA,ALTURA_TELA),"Castelos_e_ruinas");
    window->setFramerateLimit(144);

}

Gerenciador_Grafico::~Gerenciador_Grafico(){    //código adaptado dos alunos Marco Antônio Kochem Vendramin e Raphael Bassil Costa Geraldine do PETECO
   
}

Gerenciador_Grafico* Gerenciador_Grafico::pGrafico(NULL);

sf::RenderWindow* Gerenciador_Grafico::getWindow(){
    return window;
 }

Gerenciador_Grafico* Gerenciador_Grafico::getGerenciadorGrafico(){
    if(pGrafico == NULL)
        pGrafico = new Gerenciador_Grafico();
    return pGrafico;
}

bool Gerenciador_Grafico::verificaWindowOpen(){
    if(window->isOpen())
        return true;
    else
        return false;
}

sf::Texture* Gerenciador_Grafico::carregarTextura(const char* caminhoTextura){
    sf::Texture* text = new sf::Texture();
    if(!text->loadFromFile(caminhoTextura)){
        cerr<<"Nao foi possivel carregar a textura"<<endl;
        delete text;
        text = NULL;
    }
    return text;
}

sf::Vector2u Gerenciador_Grafico::getWindowSize(){
    return window->getSize();
}

void Gerenciador_Grafico::limpaWindow(){
    window->clear();
}

void Gerenciador_Grafico::closeWindow(){
    window->close();
}

void Gerenciador_Grafico::mostrar(){
    window->display();
}

void Gerenciador_Grafico::desenharEnte(Ente* pE) {
    if (pE != NULL) {
        window->draw(pE->getSprite()); 
    }
    else
        cerr<<"Erro: ponteiro para Ente nulo."<<endl;
}