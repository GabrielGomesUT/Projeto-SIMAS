#pragma once
#include <vector>
#include <SFML/Graphics.hpp>

namespace Castelos_e_ruinas{
    namespace Entidades{
        class Entidade;
        class Obstaculo;
        namespace Personagens{
            class Personagem;
            class Inimigo;
            class Jogador;
        }
    }
    namespace Listas{
        class ListaEntidades;
    }
    namespace Gerenciadores{
        class GerenciadorColisoes{
        private:
            std::vector<Entidades::Personagens::Jogador*>* pListaJogadores;
            std::vector<Entidades::Personagens::Inimigo*>* pListaInimigos;
            std::vector<Entidades::Obstaculo*>* pListaObstaculos;
            
            sf::Vector2f calculaColisao(Entidades::Entidade* pE1, Entidades::Entidade* pE2);
            bool checaColisao(Entidades::Entidade* pE1, Entidades::Entidade* pE2);
            void colisaoJogadorInimigo();
            void colisaoPersonagemObstaculo();
        
        public:
            GerenciadorColisoes();
            ~GerenciadorColisoes();

            void conectaEntidades(Listas::ListaEntidades* LE);
            //void conectaJogadores(std::vector<Entidades::Personagens::Jogador*>* pLJ) { pListaJogadores = pLJ; }
            //void conectaInimigos(std::vector<Entidades::Personagens::Inimigo*>* pLI) { pListaInimigos = pLI; }
            //void conectaObstaculos(std::vector<Entidades::Obstaculo*>* pLO) { pListaObstaculos = pLO; }

            void executar();
            //Funcionalidade: Executa a verificação de colisões entre as entidades conectadas
            
        };
    }
}
