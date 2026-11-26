#include "Castelo.hpp"
#include "Ente.hpp"
#include "Dragao.hpp"
#include "Jogador.hpp"
#include "LancaChamas.hpp"

namespace Castelos_e_ruinas{

    namespace Fases{

        Castelo::Castelo():Fase(IDs::ID::castelo),maxDragoes(1),maxChamas(10){
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
            if(arquivo.is_open()){
                int j = 0;
                while(std::getline(arquivo,linha)){
                    for(int i = 0;i < linha.size();i++){
                        if(linha[i] == 'C'){
                            criarCavaleiros(sf::Vector2i(i,j));
                        }
                        else if(linha[i] == 'D')
                            criarDragoes(sf::Vector2i(i,j));
                    }
                    j++;
                }
            }
            arquivo.close();
        }

        void Castelo::criarObstaculos(){
            std::ifstream arquivo("../arquivo/castelo.txt");
            std::string linha;
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
            Entidades::Obstaculos::LancaChamas* pLC = new Entidades::Obstaculos::LancaChamas(sf::Vector2f(pos.x * TAM_TILE,pos.y * TAM_TILE),sf::Vector2f(160.0f,35.0f));
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