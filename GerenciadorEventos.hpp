#pragma once
#include "GerenciadorGrafico.hpp"

namespace Castelos_e_ruinas{

    namespace Entidades{

        namespace Personagens{

            class Jogador;
        }
    }
    namespace Gerenciadores{

        class Gerenciador_Eventos{
        protected:
            Gerenciador_Grafico* pGrafico;
            static Gerenciador_Eventos* pEvento;
            Entidades::Personagens::Jogador* pJogador;
            Gerenciador_Eventos(); // Padrao Singleton para garantir unicidade do gerenciador de eventos
        public:
            ~Gerenciador_Eventos();
            static Gerenciador_Eventos* getGerenciadorEventos();
            void setJogador( Entidades::Personagens::Jogador* pJ);
            void verificaTeclaPressionada(sf::Keyboard::Key tecla);
            void verificaTeclaSolta(sf::Keyboard::Key tecla);
            void executar();    // codigo adaptado dos videos do monitor Lucas Eduardo Bonâncio Skora
        };
    }
}