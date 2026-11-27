#include "MenuColocacao.hpp"
#include "BotaoTexto.hpp"
#include "GerenciadorEstados.hpp"
#include "GerenciadorGrafico.hpp"

namespace Castelos_e_ruinas{

    namespace Menus{

        MenuColocacao::MenuColocacao():
        Menu(sf::Vector2f(0.0f,0.0f),sf::Vector2f(LARGURA_TELA,ALTURA_TELA),IDs::ID::menuColocacao),rank(),arquivo(){
            criarFundo();
            criarBotoes();
            criarColocacao();
        }


        MenuColocacao::~MenuColocacao(){
            if(!rank.empty()){
                for(int i = 0; i < rank.size();i++){
                    Botoes::Texto* pAux = rank[i];
                    if(pAux != NULL){
                        delete pAux;
                        pAux = NULL;
                    }
                }
            }
        }   

        
        void MenuColocacao::criarBotoes(){
            float posBotaoX = LARGURA_TELA/2.0f - TAM_BOTAO_X/2.0f;
            float espacamento = 90.0f;
            Botoes::BotaoTexto* sair = new Botoes::BotaoTexto("Sair",sf::Vector2f(posBotaoX,ALTURA_TELA/2.0f + espacamento*4),sf::Vector2f(TAM_BOTAO_X,TAM_BOTAO_Y),sf::Color::Yellow);
            adicionaBotao(static_cast<Botoes::Botao*>(sair));
            inicializaIterador();
        }

        void MenuColocacao::criarFundo(){
            sf::Texture* tex = carregarText("../assets/cenario1.png");
            if (tex != NULL) {
                corpo.setTexture(tex);
                float proporcaoJanela = LARGURA_TELA/ ALTURA_TELA;
                int alturaTex = tex->getSize().y;
                int larguraProporcional = static_cast<int>(alturaTex * proporcaoJanela);
                corpo.setTextureRect(sf::IntRect(0, 0, larguraProporcional, alturaTex));
                corpo.setFillColor(sf::Color(100, 100,100));
            }
        }

        void MenuColocacao::criarColocacao(){
            arquivo.open("../arquivo/colocacao.txt");
            if(arquivo.is_open()){
                std::string linha;
                const int qnt = 5;
                int i = 0;
                while(std::getline(arquivo,linha) && i < 5){
                    criarTexto(linha);
                    i++;
                }
                arquivo.close();
            }
        }

        void MenuColocacao::criarTexto(std::string String){
            Botoes::Texto* texto = new Botoes::Texto(*(this->carregarFont("../fontes/MedievalSharp-Regular.ttf")),String,30);
            int qnt = rank.size();
            texto->setPos(sf::Vector2f(10.0f,50.0f + 50.0 * qnt));
            rank.push_back(texto);
        }

        void MenuColocacao::desenharColocacao(){
            if(!rank.empty()){
                for(int i = 0;i < rank.size();i++){
                    Botoes::Texto* pText = rank[i];
                    pGG->desenharTexto(pText);
                }
            }
        }

        void MenuColocacao::selecionar() {
            if (listaBotao.empty()) return;

            Gerenciadores::Gerenciador_Estados* pGEstados = Gerenciadores::Gerenciador_Estados::getGerenciadorEstados();
            if (pGEstados == NULL) return;

            int indice = std::distance(listaBotao.begin(), it);
            switch (indice) {
                case 0: // Sair
                    pGEstados->removerEstado();
            }
        }

        void MenuColocacao::executar(){
            Gerenciadores::Gerenciador_Grafico* pGG = pGG->getGerenciadorGrafico();
            desenhar();
            //pGG->desenharTitulo(titulo);
            desenharBotoes();
            desenharColocacao();
            
        }
    }
}