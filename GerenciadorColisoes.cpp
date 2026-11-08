////////////////////////////////Adaptação do código do monitor Geovanni, com algumas alterações para se adequar à estrutura do projeto.
#include "GerenciadorColisoes.hpp"
#include "Jogador.hpp"
#include "Inimigo.hpp"
#include "Obstaculo.hpp"
#include "ListaEntidades.hpp"
#include "ID.hpp"
#include <cmath>
//Nesse código, "ds" significa distância de sobreposição, representando a quantidade de sobreposição entre duas entidades em cada eixo (X e Y). 

namespace Castelos_e_ruinas {
    namespace Gerenciadores {

        GerenciadorColisoes::GerenciadorColisoes()
        {
            pListaJogadores = new std::vector<Entidades::Personagens::Jogador*>();
            pListaInimigos = new std::vector<Entidades::Personagens::Inimigo*>();
            pListaObstaculos = new std::vector<Entidades::Obstaculo*>();
        }

        GerenciadorColisoes::~GerenciadorColisoes() {
            delete pListaJogadores;
            delete pListaInimigos;
            delete pListaObstaculos;
        }

        void GerenciadorColisoes::conectaEntidades(Listas::ListaEntidades* LE){
            Entidades::Entidade* pAux;
            for(int i = 0;i < LE->getTam();i++){
                pAux = LE->operator[](i);
                if(pAux->getID() == IDs::ID::jogador)
                    pListaJogadores->push_back(dynamic_cast<Entidades::Personagens::Jogador*>(pAux));
                else if(pAux->getID() == IDs::ID::inimigo)
                    pListaInimigos->push_back(dynamic_cast<Entidades::Personagens::Inimigo*>(pAux));
                else if(pAux->getID() == IDs::ID::obstaculo)
                    pListaObstaculos->push_back(dynamic_cast<Entidades::Obstaculo*>(pAux));
            }
        }

        sf::Vector2f GerenciadorColisoes::calculaColisao(Entidades::Entidade* pE1, Entidades::Entidade* pE2) {
            if (pE1 == NULL || pE2 == NULL) {
                return sf::Vector2f(0.0f, 0.0f);
            }

            sf::Vector2f pos1 = pE1->getPos();
            sf::Vector2f pos2 = pE2->getPos();
            sf::Vector2f tam1 = pE1->getTam();
            sf::Vector2f tam2 = pE2->getTam();

            sf::Vector2f distanciaEntreCentros(
                std::abs((pos1.x + tam1.x / 2.0f) - (pos2.x + tam2.x / 2.0f)),
                std::abs((pos1.y + tam1.y / 2.0f) - (pos2.y + tam2.y / 2.0f))
            );  

            sf::Vector2f somaMetadeRetangulo(
                tam1.x / 2.0f + tam2.x / 2.0f,
                tam1.y / 2.0f + tam2.y / 2.0f
            );

            return sf::Vector2f(
                distanciaEntreCentros.x - somaMetadeRetangulo.x,
                distanciaEntreCentros.y - somaMetadeRetangulo.y
            );
            //Funcionalidade: Calcula a distância entre os centros das entidades e retorna a diferença entre essa distância e a soma das metades
            //dos tamanhos das entidades, indicando se há sobreposição e qual a direção da colisão.
        }

        bool GerenciadorColisoes::checaColisao(Entidades::Entidade* pE1, Entidades::Entidade* pE2) {
            if (pE1 == NULL || pE2 == NULL) {
                return false;
            }
            sf::Vector2f ds = calculaColisao(pE1, pE2);
            return (ds.x < 0.0f && ds.y < 0.0f);
            //Funcionalidade: Verifica se há colisão, se houver sobreposição negativa em ambos os eixos simultaneamente, significa que as duas entidades 
            //estão colidindo no espaço 2D
        }

        void GerenciadorColisoes::colisaoJogadorInimigo() {
            if (pListaJogadores == NULL || pListaInimigos == NULL) return;

            for (std::size_t i = 0; i < pListaJogadores->size(); i++) {
                Entidades::Personagens::Jogador* pJogador = (*pListaJogadores)[i];
                if (pJogador == NULL) continue;

                for (std::size_t j = 0; j < pListaInimigos->size(); j++) {
                    Entidades::Personagens::Inimigo* pInimigo = (*pListaInimigos)[j];
                    if (pInimigo == NULL) continue;

                    sf::Vector2f ds = calculaColisao(pJogador, pInimigo);
                    if (ds.x < 0.0f && ds.y < 0.0f) {
                        pJogador->colisao(pInimigo, ds);
                    }
                }
            }
        }


        void GerenciadorColisoes::colisaoPersonagemObstaculo() {
            if (pListaObstaculos == NULL) return;

            if (pListaJogadores != NULL) {
                for (std::size_t i = 0; i < pListaJogadores->size(); i++) {
                    Entidades::Personagens::Jogador* pJogador = (*pListaJogadores)[i];
                    
                    if (pJogador != NULL) {
                        for (std::size_t j = 0; j < pListaObstaculos->size(); j++) {
                            Entidades::Obstaculo* pObs = (*pListaObstaculos)[j];
                            
                            if (pObs != NULL) {
                                sf::Vector2f ds = calculaColisao(pJogador, pObs);
                                if (ds.x < 0.0f && ds.y < 0.0f) {
                                    pObs->colisao(pJogador, ds);
                                }
                            }
                        }
                    }
                }
            //Funcionalidade: Colisão entre Jogadores e Obstáculos
            }

            if (pListaInimigos != NULL) {
                for (std::size_t i = 0; i < pListaInimigos->size(); i++) {
                    Entidades::Personagens::Inimigo* pInimigo = (*pListaInimigos)[i];
                    
                    if (pInimigo != NULL) {
                        for (std::size_t j = 0; j < pListaObstaculos->size(); j++) {
                            Entidades::Obstaculo* pObs = (*pListaObstaculos)[j];
                            
                            if (pObs != NULL) {
                                sf::Vector2f ds = calculaColisao(pInimigo, pObs);
                                if (ds.x < 0.0f && ds.y < 0.0f) {
                                    pObs->colisao(pInimigo, ds); 
                                }
                            }
                        }
                    }
                }
            //Funcionalidade: Colisão entre Inimigos e Obstáculos 
            }
        }        
        
        void GerenciadorColisoes::executar() {
            colisaoJogadorInimigo();
            colisaoPersonagemObstaculo();
        }

    }
}

///////////Talvez falte repulsão entre jogadores e inimigos, mas isso depende da lógica do jogo. 
//A função "executar" chama as funções de colisão para verificar e tratar as colisões entre jogadores, inimigos e obstáculos.
//Falta o dano de obstaculos, ex: espinhos
//Projeteis e entre inimigos vou fazer
