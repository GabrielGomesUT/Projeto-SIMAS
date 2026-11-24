#include "Fase.hpp"
#include "Cavaleiro.hpp"
#include "Jogador.hpp"
#include "Piso.hpp"
#include "Plataforma.hpp"

namespace Castelos_e_ruinas{
    namespace Fases{

        Fase::Fase(IDs::ID ID):Ente(sf::Vector2f(0.0f,0.0f),sf::Vector2f(LARGURA_TELA,ALTURA_TELA),ID),lista_entes(),GC(),maxCavaleiros((rand() % 7) + 4){

        }

        Fase::~Fase(){

        }

        void Fase::criarCavaleiros(){
            for(int i = 0; i < maxCavaleiros;i++){
            Entidades::Personagens::Cavaleiro* pCav = new Entidades::Personagens::Cavaleiro(sf::Vector2f(400.0f + 150.0 * i, 500.0 + 100 * i), sf::Vector2f(50, 70));
            lista_entes.incluirEntidades(static_cast<Entidades::Entidade*>(pCav));
            }
        }

        void Fase::criarPlataformas(){
            Entidades::Obstaculos::Plataforma* pPlat1 = new Entidades::Obstaculos::Plataforma(sf::Vector2f(300.0f,780.0f),sf::Vector2f(350.0f,100.0f));
            Entidades::Obstaculos::Plataforma* pPlat2 = new Entidades::Obstaculos::Plataforma(sf::Vector2f(770.0f,660.0f),sf::Vector2f(350.0f,100.0f));
            lista_entes.incluirEntidades(static_cast<Entidades::Entidade*>(pPlat1));
            lista_entes.incluirEntidades(static_cast<Entidades::Entidade*>(pPlat2));
        }

        void Fase::criarPiso(){
            Entidades::Piso* pPiso = new Entidades::Piso(sf::Vector2f(0.0f,ALTURA_TELA - 110.0f),sf::Vector2f(LARGURA_TELA,110.0f));
            lista_entes.incluirEntidades(static_cast<Entidades::Entidade*>(pPiso));
        }

        void Fase::incluirJogador(Entidades::Personagens::Jogador* pJ){
            lista_entes.setJogEnt(pJ);
            lista_entes.incluirEntidades(static_cast<Entidades::Entidade*>(pJ));
        }

        void Fase::desenharEntidades(){
            desenhar();
            lista_entes.desenhar();
        }

        void Fase::salvar(){

        }

        void Fase::conectaEntidadesGC(){
            GC.conectaEntidades(&lista_entes);
        }

        void Fase::executar(){
            desenharEntidades();
            lista_entes.percorrer();
            GC.executar();
        }
    }
}