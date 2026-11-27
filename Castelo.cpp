#include "Castelo.hpp"
#include "Ente.hpp"
#include "Dragao.hpp"
#include "Jogador.hpp"
#include "LancaChamas.hpp"

namespace Castelos_e_ruinas{

    namespace Fases{

        Castelo::Castelo():Fase(IDs::ID::castelo),maxDragoes(4),maxChamas(5){
            criarCenario();
            criarInimigos();
            criarObstaculos();
        }

        Castelo::~Castelo(){

        }

        void Castelo::criarInimigos(){
            std::ifstream arquivo;
            std::string linha;
            arquivo.open("../arquivo/castelo.txt");
            int contCav = 3;
            int contDragao = 3;
            if(arquivo.is_open()){
                int j = 0;
                while(std::getline(arquivo,linha)){
                    for(int i = 0;i < linha.size();i++){
                        if(linha[i] == 'C'){
                            criarCavaleiros(sf::Vector2i(i,j));
                        }
                        else if(linha[i] == 'D'){
                            criarDragoes(sf::Vector2i(i,j));
                        }
                        else if (linha[i] == 'c' && contCav < maxCavaleiros && (rand() % 2 == 0)) {
                            criarCavaleiros(sf::Vector2i(i, j));
                            contCav++;
                        }
                        else if (linha[i] == 'd' && contDragao < maxDragoes && (rand() % 2 == 0)) {
                            criarDragoes(sf::Vector2i(i, j));
                            contDragao++;
                        }
                    }
                    j++;
                }
            }
            arquivo.close();
        }

        void Castelo::criarObstaculos(){
            std::ifstream arquivo("../arquivo/castelo.txt");
            std::string linha;
            int contPlat = 3;
            int contChamas = 3;
            if (arquivo.is_open()) {
                int j = 0;
                while (std::getline(arquivo, linha)) {
                    for (int i = 0; i < static_cast<int>(linha.size()); i++) {
                        if (linha[i] == '#') {
                            criarPiso(sf::Vector2i(i, j));
                        }
                        else if (linha[i] == 'P') {
                            criarPlataformas(sf::Vector2i(i, j));
                        }
                        else if (linha[i] == 'F') {
                            criarChamas(sf::Vector2i(i, j));
                        }
                        else if (linha[i] == 'p' && contPlat <= maxPlataformas && (rand() % 2 == 0)) {
                            criarPlataformas(sf::Vector2i(i, j));
                            contPlat++;
                        }
                        else if (linha[i] == 'f' && contChamas <= maxChamas && (rand() % 2 == 0)) {
                            criarChamas(sf::Vector2i(i, j));
                            contChamas++;
                        }
                    }
                    j++;
                }
                arquivo.close();
            }
        }

        void Castelo::criarDragoes(sf::Vector2i pos){
            Entidades::Personagens::Dragao* pDrag = new Entidades::Personagens::Dragao(sf::Vector2f(pos.x * TAM_TILE, pos.y * TAM_TILE), sf::Vector2f(120.0f, 100.0f));
            lista_entes.incluirEntidades(static_cast<Entidades::Entidade*>(pDrag));
        }

        void Castelo::criarChamas(sf::Vector2i pos){
            Entidades::Obstaculos::LancaChamas* pLC = new Entidades::Obstaculos::LancaChamas(sf::Vector2f(pos.x * TAM_TILE,pos.y * TAM_TILE),sf::Vector2f(TAM_TILE * 2.0f,TAM_TILE));
            lista_entes.incluirEntidades(static_cast<Entidades::Entidade*>(pLC));
        } 

        void Castelo::criarCenario(){
            sf::Texture* tex = carregarText("../assets/castelo.png");
            if (tex != nullptr) {
                corpo.setTexture(tex);
                float proporcaoJanela = LARGURA_TELA/ ALTURA_TELA;
                int alturaTex = tex->getSize().y;
                int larguraProporcional = static_cast<int>(alturaTex * proporcaoJanela);
                corpo.setTextureRect(sf::IntRect(0, 0, larguraProporcional, alturaTex));
            }
        }
    }
}