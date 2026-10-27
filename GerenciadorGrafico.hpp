#pragma once
#include <vector>
#include "Ente.hpp"
#include <SFML/Graphics.hpp>

namespace nomeDoJogo{
    
    namespace Gerenciadores{

        class Gerenciador_Grafico{    //código adaptado dos alunos Marco Antônio Kochem Vendramin e Raphael Bassil Costa Geraldine do PETECO
        private:
            sf::RenderWindow *window;
            static Gerenciador_Grafico* pGrafico;
            static float dt;
        protected:
            Gerenciador_Grafico(); // padrao de projeto Singleton
        public:
            ~Gerenciador_Grafico();
             sf::RenderWindow* getWindow();
            void desenharEnte(Ente* pE);
            static Gerenciador_Grafico* getGerenciadorGrafico();
            bool verificaWindowOpen();
            //void desenharTextoMenu (vector<sf::Text>& text);
            //void desenharMenu (Menu* pM, vector<sf::Text>& text);
            //void desenharRank(const vector<string>& linhasRank, sf::Sprite& fundo);
            //void desenharFase(Fase* pF);
            //void desenharVida(Jogador* pJ1, Jogador* pJ2);
            //void desenharComoJogar(sf::Sprite& fundo);
            //void desenharMenuPause(sf::Sprite& pause);
            void mostrar();
            void limpaWindow();
            void closeWindow();
        };
    }



}