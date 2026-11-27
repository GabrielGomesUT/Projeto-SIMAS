#include "Fase.hpp"
#include "Cavaleiro.hpp"
#include "Jogador.hpp"
#include "Piso.hpp"
#include "Plataforma.hpp"

namespace Castelos_e_ruinas{
    namespace Fases{

        Fase::Fase(IDs::ID ID):
        Ente(sf::Vector2f(0.0f,0.0f),sf::Vector2f(LARGURA_TELA,ALTURA_TELA),ID),lista_entes(),GC(),pJog1(NULL),pJog2(NULL),maxCavaleiros(10),maxPlataformas(6),concluida(false)
        {

        }

        Fase::~Fase(){
            if (pJog1 != NULL) {
                lista_entes.removerEntidades(static_cast<Entidades::Entidade*>(pJog1)); 
                pJog1 = NULL;
            }
            if (pJog2 != NULL) {
                lista_entes.removerEntidades(static_cast<Entidades::Entidade*>(pJog2));
                pJog2 = NULL;
            }
        }

        void Fase::criarCavaleiros(sf::Vector2i pos){
            Entidades::Personagens::Cavaleiro* pCav = new Entidades::Personagens::Cavaleiro(sf::Vector2f(pos.x * TAM_TILE, pos.y * TAM_TILE), sf::Vector2f(50.0f, 70.0f));
            lista_entes.incluirEntidades(static_cast<Entidades::Entidade*>(pCav));
        }

        void Fase::criarPlataformas(sf::Vector2i pos){
            Entidades::Obstaculos::Plataforma* pPlat = new Entidades::Obstaculos::Plataforma(sf::Vector2f(pos.x * TAM_TILE, pos.y * TAM_TILE),sf::Vector2f(2 * TAM_TILE,65.0f));
            lista_entes.incluirEntidades(static_cast<Entidades::Entidade*>(pPlat));
        }

        void Fase::criarPiso(sf::Vector2i pos){
            Entidades::Piso* pPiso = new Entidades::Piso(sf::Vector2f(pos.x * TAM_TILE, pos.y * TAM_TILE),sf::Vector2f(TAM_TILE, 2 * TAM_TILE));
            lista_entes.incluirEntidades(static_cast<Entidades::Entidade*>(pPiso));
        }

        void Fase::incluirJogador(Entidades::Personagens::Jogador* pJ,Entidades::Personagens::Jogador* pJ2){
            if(pJog1 == NULL)
                pJog1 = pJ;
            if(pJog2 == NULL)
                pJog2 = pJ2;
            pJog1->setPos(sf::Vector2f(0.0f, ALTURA_TELA - 145.0f));
            pJog2->setPos(sf::Vector2f(60.0f, ALTURA_TELA - 145.0f));
            lista_entes.setJogEnt(pJog1);
            lista_entes.setJogEnt(pJog2);
            lista_entes.incluirEntidades(static_cast<Entidades::Entidade*>(pJog1));
            lista_entes.incluirEntidades(static_cast<Entidades::Entidade*>(pJog2));
        }

        Entidades::Personagens::Jogador* Fase::getJogador1(){
            return pJog1;
        }

        Entidades::Personagens::Jogador* Fase::getJogador2(){
            return pJog2;
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

        void Fase::verificaConclusao(){
            if((lista_entes.getInimigosAtivos() == 0) || (!pJog1->getAtivo() && !pJog2->getAtivo()))
                concluida = true;
        }

        bool Fase::getConclusao(){
            return concluida;
        }

        void Fase::executar(){
            desenharEntidades();
            lista_entes.percorrer();
            GC.executar();
            lista_entes.verificarMortos();
            verificaConclusao();
        }
    }
}