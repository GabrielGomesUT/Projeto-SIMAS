#include "CidadeMedieval.hpp"
#include "Ente.hpp"
#include "Zumbi.hpp"
#include "Jogador.hpp"
#include "Lama.hpp"

namespace Castelos_e_ruinas{

    namespace Fases{

        Cidade_Medieval::Cidade_Medieval():Fase(IDs::ID::casteloMedieval),maxZumbis(5){
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
            Entidades::Personagens::Zumbi* pZum1 = new Entidades::Personagens::Zumbi(sf::Vector2f(1000.0f, ALTURA_TELA - 115.0F), sf::Vector2f(50, 70));
            Entidades::Personagens::Zumbi* pZum2 = new Entidades::Personagens::Zumbi(sf::Vector2f(1200.0f, ALTURA_TELA - 115.0f), sf::Vector2f(50, 70));
            lista_entes.incluirEntidades(static_cast<Entidades::Entidade*>(pZum1));
            lista_entes.incluirEntidades(static_cast<Entidades::Entidade*>(pZum2));
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