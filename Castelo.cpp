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
            criarCavaleiros();
            criarDragoes();
        }

        void Castelo::criarObstaculos(){
            criarPiso();
            criarPlataformas();
            criarChamas();
        }

        void Castelo::criarDragoes(){
            for(int i = 0;i < maxDragoes;i++){
                Entidades::Personagens::Dragao* pDrag = new Entidades::Personagens::Dragao(sf::Vector2f(1500.0f + 100.0f * i, 300.0F), sf::Vector2f(120, 100));
                lista_entes.incluirEntidades(static_cast<Entidades::Entidade*>(pDrag));
            }
        }

        void Castelo::criarChamas(){
            Entidades::Obstaculos::LancaChamas* pLC = new Entidades::Obstaculos::LancaChamas(sf::Vector2f(350.0f,ALTURA_TELA - 114.9f),sf::Vector2f(300.0f,100.0f));
            lista_entes.incluirEntidades(static_cast<Entidades::Entidade*>(pLC));
        } 

        void Castelo::criarCenario(){
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