#include "MenuFim.hpp"
#include "BotaoTexto.hpp"
#include "GerenciadorEstados.hpp"
#include "GerenciadorGrafico.hpp"

namespace Castelos_e_ruinas{

    namespace Menus{

        MenuFim::MenuFim():
        Menu(sf::Vector2f(0.0f,0.0f),sf::Vector2f(LARGURA_TELA,ALTURA_TELA),IDs::ID::menuFim){
            criarBotoes();
            criarFundo();
        }

        MenuFim::~MenuFim(){

        }

        void MenuFim::criarBotoes(){
            //float espacamento = 90.0f;
            Botoes::BotaoTexto* salvarPontos = new Botoes::BotaoTexto("Salvar Pontos",sf::Vector2f(820.0f, 720.0f),sf::Vector2f(TAM_BOTAO_X,TAM_BOTAO_Y),sf::Color::Yellow);
            Botoes::BotaoTexto* sair = new Botoes::BotaoTexto("Sair",sf::Vector2f(820.0f, 830.0f),sf::Vector2f(TAM_BOTAO_X,TAM_BOTAO_Y),sf::Color::Yellow);
            adicionaBotao(static_cast<Botoes::Botao*>(salvarPontos));
            adicionaBotao(static_cast<Botoes::Botao*>(sair));
            inicializaIterador();
        }

        void MenuFim::criarFundo(){
            corpo.setFillColor(sf::Color::Black);
            sf::Texture* tex = carregarText("../assets/tituloFim.png");
            titulo.setTexture(tex);
            titulo.setSize(sf::Vector2f(800.0f,300.0f));
        }
       
        void MenuFim::selecionar() {
            if (listaBotao.empty()) return;

            Gerenciadores::Gerenciador_Estados* pGEstados = Gerenciadores::Gerenciador_Estados::getGerenciadorEstados();
            if (pGEstados == NULL) return;

            int indice = std::distance(listaBotao.begin(), it);
            switch (indice) {
                case 0:
                    break;

                case 1:
                    pGEstados->removerEstado();
                    break;
            }
        }

        void MenuFim::executar(){
            Gerenciadores::Gerenciador_Grafico* pGG = pGG->getGerenciadorGrafico();
            this->desenhar();
            pGG->desenharTitulo(titulo);
            this->desenharBotoes();
        }
    }
}