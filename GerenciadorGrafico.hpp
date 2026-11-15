#pragma once
#include <vector>
#include "Ente.hpp"
#include <SFML/Graphics.hpp>
#define LARGURA_TELA 1500.0f
#define ALTURA_TELA 900.0f

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
            static Gerenciador_Grafico* getGerenciadorGrafico();
            bool verificaWindowOpen();
            sf::Texture* carregarTextura(const char* caminhoTextura);
            void mostrar();
            sf::Vector2u getWindowSize();
            void limpaWindow();
            void closeWindow();
        };
    }
}
