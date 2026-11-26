#pragma once
#include <vector>
#include "Ente.hpp"
#include "Texto.hpp"
#include <SFML/Graphics.hpp>
#define LARGURA_TELA 1920.0f
#define ALTURA_TELA 1080.0f

namespace Castelos_e_ruinas{
    
    namespace Gerenciadores{

        class Gerenciador_Grafico{    //código adaptado dos alunos Marco Antônio Kochem Vendramin e Raphael Bassil Costa Geraldine do PETECO
        private:
            sf::RenderWindow *window;
            static Gerenciador_Grafico* pGrafico;
    
        protected:
            Gerenciador_Grafico(); // padrao de projeto Singleton
        public:
            ~Gerenciador_Grafico();
             sf::RenderWindow* getWindow();
            void desenharEnte(Ente* pE);
            void desenharTexto(Botoes::Texto* pText);
            void desenharTitulo(sf::RectangleShape titulo);
            static Gerenciador_Grafico* getGerenciadorGrafico();
            bool verificaWindowOpen();
            sf::Texture* carregarTextura(const char* caminhoTextura);
            sf::Font* carregarFonte(const char* caminhoFonte);
            void mostrar();
            void limpaWindow();
            void closeWindow();
        };
    }
}
