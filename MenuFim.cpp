#include "MenuFim.hpp"
#include "BotaoTexto.hpp"
#include "GerenciadorEstados.hpp"
#include "GerenciadorGrafico.hpp"
#include <string>
#include <stdexcept>

namespace Castelos_e_ruinas{

    namespace Menus{

        MenuFim::MenuFim():
        Menu(sf::Vector2f(0.0f,0.0f),sf::Vector2f(LARGURA_TELA,ALTURA_TELA),IDs::ID::menuFim),textoDigite(*(this->carregarFont("../fontes/MedievalSharp-Regular.ttf")),"Digite seu nome...",50),
        pontuacao(*(this->carregarFont("../fontes/MedievalSharp-Regular.ttf")),"Pontuacao",40),
        nomeExibido(*(this->carregarFont("../fontes/arial.ttf")),"",50)
        {
            textoDigite.setPos(sf::Vector2f(LARGURA_TELA/2.0f - textoDigite.getTam().x, 430.0f));
            nomeExibido.setPos(sf::Vector2f(LARGURA_TELA / 2.0f, 430.0f));
            pontuacao.setPos(sf::Vector2f((LARGURA_TELA - pontuacao.getTam().x) / 2.0f, 550.0f));
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

        void MenuFim::salvarColocacao(){
            try{
                arquivoEntrada.open("../arquivo/colocacao.txt",std::ios::app);  //ios::app evita sobreescreveer 
                if (!arquivoEntrada.is_open()){
                    return;
                }
                std::string nome = nomeExibido.getInfo();
                if(nome == "")
                    nome = "Sem nome";
                std::string pontos = pontuacao.getInfo().substr(11,pontuacao.getInfo().length());
                std::string linha = nome + " " + pontos + " " + "\n";
                arquivoEntrada << linha;
                arquivoEntrada.close();
            }
            catch (const std::exception& e){
                cerr<<"falha ao abrir arquivo"<<endl;
            }
        }

        void MenuFim::digitar(char caracter){
            std::string aux = nomeExibido.getInfo();
            if((caracter >= 'a') && (caracter <= 'z') || 
            ((caracter >= 'A') && (caracter <= 'Z')) ||
            ((caracter >= '0') && (caracter <= '9')) ||
            (caracter == ' ')){
                aux += caracter;
                nomeExibido.setInfo(aux);
            }
            else if(caracter == '\b'){
                if(!aux.empty()){
                    aux.pop_back();
                    nomeExibido.setInfo(aux);
                }
            }
        }

        void MenuFim::setPontos(Entidades::Personagens::Jogador* pJ1,Entidades::Personagens::Jogador* pJ2){
            int pontos = 0;
            if (pJ1 != NULL) {
                pontos += pJ1->getPontos();
            }
            if (pJ2 != NULL) {
                pontos += pJ2->getPontos();
            }
            pontuacao.setInfo("Pontuacao: " + std::to_string(pontos));
        }
       
        void MenuFim::selecionar() {
            if (listaBotao.empty()) return;

            Gerenciadores::Gerenciador_Estados* pGEstados = Gerenciadores::Gerenciador_Estados::getGerenciadorEstados();
            if (pGEstados == NULL) return;

            int indice = std::distance(listaBotao.begin(), it);
            switch (indice) {
                case 0:
                    salvarColocacao();
                    pGEstados->removerEstado();
                    pGEstados->removerEstado();
                    break;

                case 1:
                    pGEstados->removerEstado();
                    pGEstados->removerEstado();
                    break;
            }
        }

        void MenuFim::executar(){
            Gerenciadores::Gerenciador_Grafico* pGG = pGG->getGerenciadorGrafico();
            this->desenhar();
            pGG->desenharTitulo(titulo);
            this->desenharBotoes();
            pGG->desenharTexto(&textoDigite);
            pGG->desenharTexto(&nomeExibido);
            pGG->desenharTexto(&pontuacao);
        }
    }
}