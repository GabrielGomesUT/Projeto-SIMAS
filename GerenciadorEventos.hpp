#pragma once
#include "GerenciadorGrafico.hpp"

namespace Castelos_e_ruinas{

    class Jogo;

    namespace Entidades{

        namespace Personagens{

            class Jogador;
        }
    }
    namespace Menus{
        class Menu;
    }

    namespace Gerenciadores{

        class Gerenciador_Eventos{
        protected:
            Gerenciador_Grafico* pGrafico;
            static Gerenciador_Eventos* pEvento;
            Entidades::Personagens::Jogador* pJogador;
            Menus::Menu* pMenu;
            Jogo* pJogo;
            Gerenciador_Eventos(); // Padrao Singleton para garantir unicidade do gerenciador de eventos
        public:
            ~Gerenciador_Eventos();
            static Gerenciador_Eventos* getGerenciadorEventos();
            void setJogador( Entidades::Personagens::Jogador* pJ);
            void setMenu(Menus::Menu* pM);
            void setJogo(Jogo* pJo);
            void verificaTeclaPressionada(sf::Keyboard::Key tecla);
            void verificaTeclaSolta(sf::Keyboard::Key tecla);
            void executar();    // codigo adaptado dos videos do monitor Lucas Eduardo Bonâncio Skora
        };
    }
}