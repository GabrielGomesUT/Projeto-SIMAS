#include "Fase.hpp"
#include "Inimigo.hpp"
#include "Jogador.hpp"
#include "Piso.hpp"

namespace Castelos_e_ruinas{
    namespace Fases{

        Fase::Fase():Ente(IDs::ID::fase),lista_entes(),GC(){
            criarInimFaceis();
            criarPiso();
            criarCenario();
            GC.conectaEntidades(&lista_entes);
        }

        Fase::~Fase(){

        }

        void Fase::criarInimFaceis(){
            Entidades::Personagens::Inimigo* pIni1 = new Entidades::Personagens::Inimigo(sf::Vector2f(300, 100), sf::Vector2f(50, 70));
            Entidades::Personagens::Inimigo* pIni2 = new Entidades::Personagens::Inimigo(sf::Vector2f(200, 100), sf::Vector2f(50, 70));
            lista_entes.incluirEntidades(static_cast<Entidades::Entidade*>(pIni1));
            lista_entes.incluirEntidades(static_cast<Entidades::Entidade*>(pIni2));
        }

        void Fase::criarObstaculos(){
            
        }

        void Fase::criarPlataformas(){

        }

        void Fase::criarCenario(){
            sf::Texture* tex = carregarText("../assets/cenario1.png");
            if (tex != nullptr) {
                cenario.setSize(sf::Vector2f(LARGURA_TELA,ALTURA_TELA));
                cenario.setPosition(0.0f, 0.0f);
                cenario.setTexture(tex);
                float proporcaoJanela = LARGURA_TELA/ ALTURA_TELA;
                int alturaTex = tex->getSize().y;
                int larguraProporcional = static_cast<int>(alturaTex * proporcaoJanela);

                cenario.setTextureRect(sf::IntRect(0, 0, larguraProporcional, alturaTex));
            }
        }

        void Fase::criarPiso(){
            Entidades::Obstaculos::Piso* pPiso = new Entidades::Obstaculos::Piso(sf::Vector2f(0.0f,ALTURA_TELA - 110.0f),sf::Vector2f(LARGURA_TELA,110.0f));
            lista_entes.incluirEntidades(static_cast<Entidades::Entidade*>(pPiso));
        }

        void Fase::incluirJogador(Entidades::Personagens::Jogador* pJ){
            lista_entes.setJogEnt(pJ);
            lista_entes.incluirEntidades(static_cast<Entidades::Entidade*>(pJ));
        }

        void Fase::desenharEntidades(Gerenciadores::Gerenciador_Grafico* pGG){
            lista_entes.desenhar(pGG);
        }

        void Fase::atualizar(){

        }

        void Fase::salvar(){

        }

        sf::RectangleShape Fase::getSprite() const{
            return cenario;
        }

        void Fase::conectaEntidadesGC(){
            GC.conectaEntidades(&lista_entes);
        }

        void Fase::executar(){
            lista_entes.percorrer();
            GC.executar();
        }
    }
}