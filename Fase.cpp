#include "Fase.hpp"
#include "Inimigo.hpp"
#include "Jogador.hpp"
#include "Piso.hpp"
#include "Plataforma.hpp"

namespace Castelos_e_ruinas{
    namespace Fases{

        Fase::Fase(IDs::ID ID):Ente(sf::Vector2f(0.0f,0.0f),sf::Vector2f(LARGURA_TELA,ALTURA_TELA),ID),lista_entes(),GC(){

        }

        Fase::~Fase(){

        }

        void Fase::criarCavaleiros(){
            Entidades::Personagens::Inimigo* pIni1 = new Entidades::Personagens::Inimigo(sf::Vector2f(400.0f, 500.0f), sf::Vector2f(50, 70));
            Entidades::Personagens::Inimigo* pIni2 = new Entidades::Personagens::Inimigo(sf::Vector2f(820.0f, 410.0f), sf::Vector2f(50, 70));
            lista_entes.incluirEntidades(static_cast<Entidades::Entidade*>(pIni1));
            lista_entes.incluirEntidades(static_cast<Entidades::Entidade*>(pIni2));
        }

        void Fase::criarPlataformas(){
            Entidades::Obstaculos::Plataforma* pPlat1 = new Entidades::Obstaculos::Plataforma(sf::Vector2f(300.0f,600.0f),sf::Vector2f(350.0f,100.0f));
            Entidades::Obstaculos::Plataforma* pPlat2 = new Entidades::Obstaculos::Plataforma(sf::Vector2f(770.0f,500.0f),sf::Vector2f(350.0f,100.0f));
            lista_entes.incluirEntidades(static_cast<Entidades::Entidade*>(pPlat1));
            lista_entes.incluirEntidades(static_cast<Entidades::Entidade*>(pPlat2));
        }

        void Fase::criarPiso(){
            Entidades::Obstaculos::Piso* pPiso = new Entidades::Obstaculos::Piso(sf::Vector2f(0.0f,ALTURA_TELA - 110.0f),sf::Vector2f(LARGURA_TELA,110.0f));
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