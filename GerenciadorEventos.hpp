#pragma once
#include "GerenciadorGrafico.hpp"
#include "GerenciadorEstados.hpp"

namespace Castelos_e_ruinas{

    namespace Gerenciadores{

        class Gerenciador_Eventos{   // codigo adaptado dos videos do monitor Giovane Limas Salvi
        protected:
            Gerenciador_Grafico* pGrafico;
            Gerenciador_Estados* pEstado;
            static Gerenciador_Eventos* pEvento;

            Gerenciador_Eventos(); // Padrao Singleton para garantir unicidade do gerenciador de eventos
        public:
            ~Gerenciador_Eventos();
            static Gerenciador_Eventos* getGerenciadorEventos();
            void verificaTeclaPressionada(sf::Keyboard::Key tecla);
            void verificaTeclaSolta(sf::Keyboard::Key tecla);
            void executar(); 
        };
    }
}