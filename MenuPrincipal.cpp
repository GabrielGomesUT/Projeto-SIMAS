#include "MenuPrincipal.hpp"
#include "BotaoTexto.hpp"
#include "Jogo.hpp"
#define TAM_BOTAO_X 280.0f
#define TAM_BOTAO_Y 60.0f

namespace Castelos_e_ruinas{

    namespace Menus{

        MenuPrincipal::MenuPrincipal():
        Menu(sf::Vector2f(0.0f,0.0f),sf::Vector2f(LARGURA_TELA,ALTURA_TELA),IDs::ID::menuPrincipal),pJogo(NULL){
            criarFundo();
            criarBotoes();
            pJogo = new Jogo(this);
            pJogo->executar();
        }


        MenuPrincipal::~MenuPrincipal(){

        }

        
        void MenuPrincipal::criarBotoes(){
            float posBotaoX = LARGURA_TELA/2.0f - TAM_BOTAO_X/2.0f;
            float espacamento = 90.0f;
            Botoes::BotaoTexto* novoJogo = new Botoes::BotaoTexto("Novo Jogo",sf::Vector2f(posBotaoX,ALTURA_TELA/2.0f),sf::Vector2f(TAM_BOTAO_X,TAM_BOTAO_Y),sf::Color::Yellow);
            Botoes::BotaoTexto* carregarJogo = new Botoes::BotaoTexto("Carregar Jogo",sf::Vector2f(posBotaoX,ALTURA_TELA/2.0f + espacamento),sf::Vector2f(TAM_BOTAO_X,TAM_BOTAO_Y),sf::Color::Yellow);
            Botoes::BotaoTexto* colocacao = new Botoes::BotaoTexto("Colocacao",sf::Vector2f(posBotaoX,ALTURA_TELA/2.0f + espacamento*2),sf::Vector2f(TAM_BOTAO_X,TAM_BOTAO_Y),sf::Color::Yellow);
            Botoes::BotaoTexto* opcoes = new Botoes::BotaoTexto("Opcoes",sf::Vector2f(posBotaoX,ALTURA_TELA/2.0f + espacamento*3),sf::Vector2f(TAM_BOTAO_X,TAM_BOTAO_Y),sf::Color::Yellow);
            Botoes::BotaoTexto* sair = new Botoes::BotaoTexto("Sair",sf::Vector2f(posBotaoX,ALTURA_TELA/2.0f + espacamento*4),sf::Vector2f(TAM_BOTAO_X,TAM_BOTAO_Y),sf::Color::Yellow);
            adicionaBotao(static_cast<Botoes::Botao*>(novoJogo));
            adicionaBotao(static_cast<Botoes::Botao*>(carregarJogo));
            adicionaBotao(static_cast<Botoes::Botao*>(colocacao));
            adicionaBotao(static_cast<Botoes::Botao*>(opcoes));
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

            int indice = std::distance(listaBotao.begin(), it);
            switch (indice) {
                case 0: // Novo Jogo
                    pJogo->criarFase(1);
                    break;
                case 1: // Carregar Jogo
                    break;
                case 2: // Colocacao
                    break;
                case 3: // Opcoes
                    break;
                case 4: // Sair
                    pJogo->setSair(true);
                    break;
            }
        }

        void MenuPrincipal::executar(){
            this->desenhar();
            pGG->getWindow()->draw(titulo);
            this->desenharBotoes();
        }
    }
}