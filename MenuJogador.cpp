#include "MenuJogador.hpp"
#include "BotaoTexto.hpp"
#include "GerenciadorEstados.hpp"
#include "GerenciadorGrafico.hpp"

namespace Castelos_e_ruinas{

    namespace Menus{

        MenuJogador::MenuJogador():
        Menu(sf::Vector2f(0.0f,0.0f),sf::Vector2f(LARGURA_TELA,ALTURA_TELA),IDs::ID::menuJogador){
            criarFundo();
            criarBotoes();
        }


        MenuJogador::~MenuJogador(){

        }

        
        void MenuJogador::criarBotoes(){
            float posBotaoX = LARGURA_TELA/2.0f - TAM_BOTAO_X/2.0f;
            float espacamento = 90.0f;
            Botoes::BotaoTexto* solo = new Botoes::BotaoTexto("Um Jogador",sf::Vector2f(posBotaoX,ALTURA_TELA/2.0f),sf::Vector2f(TAM_BOTAO_X,TAM_BOTAO_Y),sf::Color::Yellow);
            Botoes::BotaoTexto* dupla = new Botoes::BotaoTexto("Dois Jogadores",sf::Vector2f(posBotaoX,ALTURA_TELA/2.0f + espacamento),sf::Vector2f(TAM_BOTAO_X,TAM_BOTAO_Y),sf::Color::Yellow);
            Botoes::BotaoTexto* sair = new Botoes::BotaoTexto("Sair",sf::Vector2f(posBotaoX,ALTURA_TELA/2.0f + espacamento*2),sf::Vector2f(TAM_BOTAO_X,TAM_BOTAO_Y),sf::Color::Yellow);
            adicionaBotao(static_cast<Botoes::Botao*>(solo));
            adicionaBotao(static_cast<Botoes::Botao*>(dupla));
            adicionaBotao(static_cast<Botoes::Botao*>(sair));
            inicializaIterador();
        }

        void MenuJogador::criarFundo(){
            sf::Texture* tex = carregarText("../assets/cenario1.png");
            if (tex != NULL) {
                corpo.setTexture(tex);
                float proporcaoJanela = LARGURA_TELA/ ALTURA_TELA;
                int alturaTex = tex->getSize().y;
                int larguraProporcional = static_cast<int>(alturaTex * proporcaoJanela);
                corpo.setTextureRect(sf::IntRect(0, 0, larguraProporcional, alturaTex));
            }
        }

        void MenuJogador::selecionar() {
            if (listaBotao.empty()) return;

            Gerenciadores::Gerenciador_Estados* pGEstados = Gerenciadores::Gerenciador_Estados::getGerenciadorEstados();
            if (pGEstados == NULL) return;

            int indice = std::distance(listaBotao.begin(), it);
            switch (indice) {
                case 0:
                    pGEstados->setSolo(true);
                    pGEstados->adicionarEstado(pGEstados->getNFase());
                    break;
                case 1:
                    pGEstados->setSolo(false);
                    pGEstados->adicionarEstado(pGEstados->getNFase());
                    break;
                case 2:
                    pGEstados->removerEstado();
                    break;                    
            }
        }

        void MenuJogador::executar(){
            this->desenhar();
            this->desenharBotoes();
        }
    }
}