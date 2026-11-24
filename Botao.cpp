#include "Botao.hpp"

namespace Castelos_e_ruinas{

    namespace Botoes{

        Botao::Botao(const sf::Vector2f pos,const sf::Vector2f tam,IDs::ID ID):
        Ente(pos,tam,ID),selecionado(false),tempoAcumulado(0.0f){

        }

        Botao::~Botao(){

        }
        
        void Botao::setSelecionado(const bool selec){
            selecionado = selec;
        }

        bool Botao::getSelecionado(){
            return selecionado;
        }
    }
}
