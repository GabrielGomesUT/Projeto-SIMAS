#include "GerenciadorGrafico.hpp"
#include<iostream>
#include <sstream>
using namespace std;
using namespace nomeDoJogo;
using namespace Gerenciadores;

float Gerenciador_Grafico::dt = 0;

Gerenciador_Grafico::Gerenciador_Grafico(){     //código adaptado dos alunos Marco Antônio Kochem Vendramin e Raphael Bassil Costa Geraldine do PETECO
    window = new sf::RenderWindow(sf::VideoMode(1280,720),"nomeDoJogo");
    window->setFramerateLimit(144);

    /*if (!fonteName.loadFromFile(FONTE))
        cerr << "Erro de carregamento da Fonte no Menu" << endl;
    nameType.setFont(fonteName);*/
}

Gerenciador_Grafico::~Gerenciador_Grafico(){    //código adaptado dos alunos Marco Antônio Kochem Vendramin e Raphael Bassil Costa Geraldine do PETECO
    /*map<const char*, sf::Texture*>::iterator it;

    for (it = mapaTexturas.begin(); it != mapaTexturas.end(); ++it) 
    {
        if((*it).second)    
            delete ((*it).second);

        ((*it).second) = NULL;
    }

    mapaTexturas.clear();*/
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