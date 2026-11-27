#include "MenuPrincipal.hpp"
#include "BotaoTexto.hpp"
#include "GerenciadorEstados.hpp"
#include "GerenciadorGrafico.hpp"

namespace Castelos_e_ruinas{

    namespace Menus{

        MenuPrincipal::MenuPrincipal():
        Menu(sf::Vector2f(0.0f,0.0f),sf::Vector2f(LARGURA_TELA,ALTURA_TELA),IDs::ID::menuPrincipal){
            criarFundo();
            criarBotoes();
        }


        MenuPrincipal::~MenuPrincipal(){

        }

        
        void MenuPrincipal::criarBotoes(){
            float posBotaoX = LARGURA_TELA/2.0f - TAM_BOTAO_X/2.0f;
            float espacamento = 90.0f;
            Botoes::BotaoTexto* novoJogo = new Botoes::BotaoTexto("Novo Jogo",sf::Vector2f(posBotaoX,ALTURA_TELA/2.0f),sf::Vector2f(TAM_BOTAO_X,TAM_BOTAO_Y),sf::Color::Yellow);
            Botoes::BotaoTexto* castelo = new Botoes::BotaoTexto("Comecar Jogo: Castelo",sf::Vector2f(posBotaoX,ALTURA_TELA/2.0f + espacamento),sf::Vector2f(TAM_BOTAO_X,TAM_BOTAO_Y),sf::Color::Yellow);
            Botoes::BotaoTexto* carregarJogo = new Botoes::BotaoTexto("Carregar Jogo",sf::Vector2f(posBotaoX,ALTURA_TELA/2.0f + espacamento*2),sf::Vector2f(TAM_BOTAO_X,TAM_BOTAO_Y),sf::Color::Yellow);
            Botoes::BotaoTexto* colocacao = new Botoes::BotaoTexto("Colocacao",sf::Vector2f(posBotaoX,ALTURA_TELA/2.0f + espacamento*3),sf::Vector2f(TAM_BOTAO_X,TAM_BOTAO_Y),sf::Color::Yellow);
            Botoes::BotaoTexto* sair = new Botoes::BotaoTexto("Sair",sf::Vector2f(posBotaoX,ALTURA_TELA/2.0f + espacamento*4),sf::Vector2f(TAM_BOTAO_X,TAM_BOTAO_Y),sf::Color::Yellow);
            adicionaBotao(static_cast<Botoes::Botao*>(novoJogo));
            adicionaBotao(static_cast<Botoes::Botao*>(castelo));
            adicionaBotao(static_cast<Botoes::Botao*>(carregarJogo));
            adicionaBotao(static_cast<Botoes::Botao*>(colocacao));
            adicionaBotao(static_cast<Botoes::Botao*>(sair));
            inicializaIterador();
        }

        void MenuPrincipal::criarFundo(){
            sf::Texture* tex = carregarText("../assets/cenario1.png");
            if (tex != NULL) {
                corpo.setTexture(tex);
                float proporcaoJanela = LARGURA_TELA/ ALTURA_TELA;
                int alturaTex = tex->getSize().y;
                int larguraProporcional = static_cast<int>(alturaTex * proporcaoJanela);
                corpo.setTextureRect(sf::IntRect(0, 0, larguraProporcional, alturaTex));
            }
            tex = carregarText("../assets/titulo.png");
            titulo.setTexture(tex);
        }

        void MenuPrincipal::selecionar() {
            if (listaBotao.empty()) return;

            Gerenciadores::Gerenciador_Estados* pGEstados = Gerenciadores::Gerenciador_Estados::getGerenciadorEstados();
            if (pGEstados == NULL) return;

            int indice = std::distance(listaBotao.begin(), it);
            switch (indice) {
                case 0: // Novo Jogo
                    pGEstados->setNFase(IDs::ID::cidadeMedieval);
                    pGEstados->adicionarEstado(IDs::ID::menuJogador);
                    break;
                case 1:
                    pGEstados->setNFase(IDs::ID::castelo);
                    pGEstados->adicionarEstado(IDs::ID::menuJogador);
                    break;
                case 2:
                    break;
                case 3:
                    break;
                case 4: // Sair
                    pGEstados->removerEstado();
                    break;
            }
        }

        void MenuPrincipal::executar(){
            Gerenciadores::Gerenciador_Grafico* pGG = pGG->getGerenciadorGrafico();
            this->desenhar();
            pGG->desenharTitulo(titulo);
            this->desenharBotoes();
        }
    }
}