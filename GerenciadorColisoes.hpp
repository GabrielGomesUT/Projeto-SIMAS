#pragma once //Funcionalidade: Evita múltiplas inclusões do mesmo arquivo de cabeçalho,
//garantindo que o conteúdo seja incluído apenas uma vez durante a compilação.
#include <vector>
#include <SFML/Graphics.hpp>

namespace nomeDoJogo{
    namespace Entidades{
        class Entidade;
        namespace Personagens{
            class Personagem;
            //class Obstaculo;
            class Inimigo;
            class Jogador;
        }
    }
    namespace Gerenciadores{
        class GerenciadorColisoes{
        private:
            std::vector<Entidades::Personagens::Jogador*>* pListaJogadores;//Funcionaliade: Permiti o gerenciamento e verificação de colisões entre jogadores e outras entidades.
            std::vector<Entidades::Personagens::Inimigo*>* pListaInimigos;//Funcionalidade: Permiti o gerenciamento e verificação de colisões entre inimigos e outras entidades.
            //std::vector<Entidades::Obstaculo*>* pListaObstaculos;//Funcionalidade: Permiti o gerenciamento e verificação de colisões entre obstáculos e outras entidades.
            //Tudo privado para garantir que apenas o GerenciadorColisoes tenha acesso direto às listas de entidades, 
            //promovendo encapsulamento e evitando manipulações externas indesejadas, além de todos serem ponteriros
            //para permitir a manipulação eficiente das entidades sem a necessidade de cópias desnecessárias.
            
            sf::Vector2f calculaColisao(Entidades::Entidade* pE1, Entidades::Entidade* pE2);
            //Nota: "Vector2f" é uma classe da biblioteca SFML que representa um vetor bidimensional de ponto flutuante (float), nessa caso para (X,Y).
            //Pegamos de exemplo no jogo referenciado em nosso relatorio
            bool checaColisao(Entidades::Entidade* pE1, Entidades::Entidade* pE2);
            void colisaoJogadorInimigo();
            void colisaoPersonagemObstaculo();
        
        public:
            GerenciadorColisoes();
            ~GerenciadorColisoes();
            
            void conectaJogadores(std::vector<Entidades::Personagens::Jogador*>* pLJ) { pListaJogadores = pLJ; }
            void conectaInimigos(std::vector<Entidades::Personagens::Inimigo*>* pLI) { pListaInimigos = pLI; }
           // void conectaObstaculos(std::vector<Entidades::Obstaculo*>* pLO) { pListaObstaculos = pLO; }
            //Tudo público para permitir que outras partes do código interajam com o GerenciadorColisoes, "Fase"(e suas derivadas) ou "Jogo"

            void executar();
            //Funcionalidade: Executa a verificação de colisões entre as entidades conectadas
            
        };
    }
}
