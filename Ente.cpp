#include "Ente.hpp"
#include "GerenciadorGrafico.hpp"

using namespace std;

namespace Castelos_e_ruinas{

    Gerenciadores::Gerenciador_Grafico* Ente::pGG(pGG->getGerenciadorGrafico());

    Ente::Ente(const sf::Vector2f pos,const sf::Vector2f tam,IDs::ID ID):id(ID),corpo(sf::RectangleShape(tam)){
        corpo.setPosition(pos);
    }

    float Ente::dt(0.0f);

    Ente::~Ente(){

    }

    sf::Texture* Ente::carregarText(const char* caminhoTextura){
        return pGG->carregarTextura(caminhoTextura);
    }

    sf::Font* Ente::carregarFont(const char* caminhoFonte){
        return pGG->carregarFonte(caminhoFonte);
    }

    void Ente::desenhar(){
        if(pGG != NULL)
            pGG->desenharEnte(this);
        else
            cerr<<"Erro: ponteiro para GerenciadorGrafico nulo." <<endl;
    }

    void Ente::setGG(Gerenciadores::Gerenciador_Grafico* pG){
        pGG = pG;
    }

    IDs::ID Ente::getID(){
        return id;
    }

    sf::RectangleShape Ente::getSprite() const{
        return corpo;
    }
}
