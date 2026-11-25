#include "MenuPause.hpp"
#include "BotaoTexto.hpp"
#include "GerenciadorEstados.hpp"

namespace Castelos_e_ruinas{

    namespace Menus{

        MenuPause::MenuPause(Fases::Fase* pF):Menu(sf::Vector2f(350.0f, 160.0f),sf::Vector2f(1220.0f, 760.0f),IDs::ID::menuPause),pFase(pF){
            criarBotoes();
            criarFundo();
        }

        MenuPause::~MenuPause(){

        }

        void MenuPause::criarBotoes(){
            //float espacamento = 90.0f;
            Botoes::BotaoTexto* continuar = new Botoes::BotaoTexto("Continuar",sf::Vector2f(820.0f, 410.0f),sf::Vector2f(TAM_BOTAO_X,TAM_BOTAO_Y),sf::Color::Yellow);
            Botoes::BotaoTexto* opcoes = new Botoes::BotaoTexto("Opcoes",sf::Vector2f(820.0f, 520.0f),sf::Vector2f(TAM_BOTAO_X,TAM_BOTAO_Y),sf::Color::Yellow);
            Botoes::BotaoTexto* sair = new Botoes::BotaoTexto("Sair",sf::Vector2f(820.0f, 630.0f),sf::Vector2f(TAM_BOTAO_X,TAM_BOTAO_Y),sf::Color::Yellow);
            adicionaBotao(static_cast<Botoes::Botao*>(continuar));
            adicionaBotao(static_cast<Botoes::Botao*>(opcoes));
            adicionaBotao(static_cast<Botoes::Botao*>(sair));
            inicializaIterador();
        }

        void MenuPause::criarFundo(){
            sf::Texture* tex = carregarText("../assets/menuPause.png");
            if (tex != NULL) {
                corpo.setTexture(tex);
            }
            //tex = carregarText("../assets/titulo.png");
            //titulo.setTexture(tex);
        }

        void MenuPause::setFase(Fases::Fase* pFa){
            pFase = pFa;
        }

        Fases::Fase* MenuPause::getFase(){
            return pFase;
        }

        void MenuPause::selecionar() {
            if (listaBotao.empty()) return;

            Gerenciadores::Gerenciador_Estados* pGEstados = Gerenciadores::Gerenciador_Estados::getGerenciadorEstados();
            if (pGEstados == NULL) return;

            int indice = std::distance(listaBotao.begin(), it);
            switch (indice) {
                case 0:
                    pGEstados->removerEstado();
                    break;

                case 1:
                    // pGEstados->adicionarEstado(IDs::ID::menuOpcoes);
                    break;

                case 2:
                    pGEstados->removerEstado();
                    pGEstados->removerEstado();
                    break;
            }
        }

        void MenuPause::executar(){
            if(pFase != NULL)
                pFase->desenharEntidades();
            //Gerenciadores::Gerenciador_Grafico* pGG = pGG->getGerenciadorGrafico();
            this->desenhar();
            //pGG->getWindow()->draw(titulo);
            this->desenharBotoes();
        }
    }
}