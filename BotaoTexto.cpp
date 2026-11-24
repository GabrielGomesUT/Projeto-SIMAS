#include "BotaoTexto.hpp"
#include "GerenciadorGrafico.hpp"

namespace Castelos_e_ruinas{

    namespace Botoes{

        BotaoTexto::BotaoTexto(const std::string info, const sf::Vector2f pos,const sf::Vector2f tam,sf::Color corSel):
        Botao(pos,tam,IDs::ID::botaoTexto),texto(*(this->carregarFont("../fontes/arial.ttf")),info,TAM_FONTE),corSelecionado(corSel){

            // Centraliza o texto no botão
            sf::Vector2f tamTexto = texto.getTam();
            texto.setPos(sf::Vector2f(pos.x + (tam.x - tamTexto.x) / 2.0f, pos.y + (tam.y - tamTexto.y) / 2.0f));
            corpo.setFillColor(sf::Color::Black);
        }

        BotaoTexto::~BotaoTexto(){

        }

        void BotaoTexto::executar(){
            if(this->getSelecionado())
                texto.setCorTexto(sf::Color::Yellow);
            else
                texto.setCorTexto(sf::Color::White);
            this->desenhar();
            pGG->desenharTexto(&texto);
        }
    }
}