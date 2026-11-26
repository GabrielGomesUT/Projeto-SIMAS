#include "CidadeMedieval.hpp"
#include "Ente.hpp"
#include "Zumbi.hpp"
#include "Jogador.hpp"
#include "Lama.hpp"

namespace Castelos_e_ruinas{

    namespace Fases{

        Cidade_Medieval::Cidade_Medieval():Fase(IDs::ID::cidadeMedieval),maxZumbis(6),maxLamas(5){
            criarCenario();
            criarInimigos();
            criarObstaculos();
        }

        Cidade_Medieval::~Cidade_Medieval(){

        }

        void Cidade_Medieval::criarInimigos(){
            std::ifstream arquivo;
            std::string linha;
            int contCav = 0;
            int contZum = 0;
            arquivo.open("../arquivo/cidade_medieval.txt");
            if(arquivo.is_open()){
                int j = 0;
                while(std::getline(arquivo,linha)){
                    for(int i = 0;i < linha.size();i++){
                        if(linha[i] == 'C'){
                            criarCavaleiros(sf::Vector2i(i,j));
                        }
                        else if(linha[i] == 'Z'){
                            criarZumbis(sf::Vector2i(i,j));
                        }
                        else if (linha[i] == 'c' && contCav < maxCavaleiros && (rand() % 2 == 0)) {
                            criarCavaleiros(sf::Vector2i(i, j));
                            contCav++;
                        }
                        else if (linha[i] == 'z' && contZum < maxZumbis && (rand() % 2 == 0)) {
                            criarZumbis(sf::Vector2i(i, j));
                            contZum++;
                        }
                    }
                    j++;
                }
            }
            arquivo.close();
        }

        void Cidade_Medieval::criarObstaculos(){
            std::ifstream arquivo("../arquivo/cidade_medieval.txt");
            std::string linha;
            int contPlat = 0;
            int contLama = 0;
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
                        else if (linha[i] == 'L') {
                            criarLamas(sf::Vector2i(i, j));
                        }
                        else if (linha[i] == 'p' && contPlat < maxPlataformas && (rand() % 2 == 0)) {
                            criarPlataformas(sf::Vector2i(i, j));
                            contPlat++;
                        }
                        else if (linha[i] == 'l' && contLama < maxLamas && (rand() % 2 == 0)) {
                            criarLamas(sf::Vector2i(i, j));
                            contLama++;
                        }
                    }
                    j++;
                }
                arquivo.close();
            }
        }

        void Cidade_Medieval::criarZumbis(sf::Vector2i pos){
            Entidades::Personagens::Zumbi* pZum = new Entidades::Personagens::Zumbi(sf::Vector2f(pos.x * TAM_TILE, pos.y * TAM_TILE), sf::Vector2f(50.0f, 70.0f));
            lista_entes.incluirEntidades(static_cast<Entidades::Entidade*>(pZum));
        }

        void Cidade_Medieval::criarLamas(sf::Vector2i pos){
            Entidades::Obstaculos::Lama* pLama = new Entidades::Obstaculos::Lama(sf::Vector2f(pos.x * TAM_TILE,pos.y * TAM_TILE),sf::Vector2f(2 * TAM_TILE,TAM_TILE));
            lista_entes.incluirEntidades(static_cast<Entidades::Entidade*>(pLama));
        }  

        void Cidade_Medieval::criarCenario(){
            sf::Texture* tex = carregarText("../assets/cenario1.png");
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