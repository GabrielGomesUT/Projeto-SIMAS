#include "CidadeMedieval.hpp"
#include "Ente.hpp"
#include "Zumbi.hpp"
#include "Jogador.hpp"
#include "Lama.hpp"

namespace Castelos_e_ruinas{

    namespace Fases{

        Cidade_Medieval::Cidade_Medieval():Fase(IDs::ID::casteloMedieval),maxZumbis((rand() % 7) + 4),maxLamas(10){
            criarCenario();
            criarInimigos();
            criarObstaculos();
        }

        Cidade_Medieval::~Cidade_Medieval(){

        }

        void Cidade_Medieval::criarInimigos(){
            criarCavaleiros();
            criarZumbis();
        }

        void Cidade_Medieval::criarObstaculos(){
            criarPiso();
            criarPlataformas();
            criarLamas();
        }

        void Cidade_Medieval::criarZumbis(){
            for(int i = 0 ;i < maxZumbis;i++){
                Entidades::Personagens::Zumbi* pZum = new Entidades::Personagens::Zumbi(sf::Vector2f(500.0f + 110.0f * i, ALTURA_TELA - 115.0F), sf::Vector2f(30, 50));
                lista_entes.incluirEntidades(static_cast<Entidades::Entidade*>(pZum));
            }
        }

        void Cidade_Medieval::criarLamas(){
            Entidades::Obstaculos::Lama* pLama1 = new Entidades::Obstaculos::Lama(sf::Vector2f(350.0f,ALTURA_TELA - 114.9f),sf::Vector2f(300.0f,100.0f));
            lista_entes.incluirEntidades(static_cast<Entidades::Entidade*>(pLama1));
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