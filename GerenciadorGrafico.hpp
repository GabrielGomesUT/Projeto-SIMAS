
#include <vector>
#include "Ente.hpp"
#include <SFML/Graphics.hpp>

namespace nomeDoJogo{
    
    namespace Gerenciadores{

        class Gerenciador_Grafico{    //código adaptado dos alunos ... e ... do PETECO
        private:
            sf::RenderWindow window;
            static float dt;
        protected:
            Gerenciador_Grafico();
        public:
            ~Gerenciador_Grafico();
             sf::RenderWindow* getWindow();
            void desenharEnte(Ente* pE);
            //void desenharTextoMenu (vector<sf::Text>& text);
            //void desenharMenu (Menu* pM, vector<sf::Text>& text);
            //void desenharRank(const vector<string>& linhasRank, sf::Sprite& fundo);
            //void desenharFase(Fase* pF);
            //void desenharVida(Jogador* pJ1, Jogador* pJ2);
            //void desenharComoJogar(sf::Sprite& fundo);
            //void desenharMenuPause(sf::Sprite& pause);
            //void mostrar();
        };
    }



}