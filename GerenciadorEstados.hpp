#pragma once
#include <stack>
#include "ID.hpp"

namespace Castelos_e_ruinas{

    namespace Estados{

        class Estado;
    }

    namespace Entidades{
        
        namespace Personagens{

            class Jogador;
        }
    }

    namespace Gerenciadores{

        class Gerenciador_Estados{   // codigo adaptado dos videos do monitor Giovane Limas Salvi
        private:
            std::stack<Estados::Estado*> pilhaEstados;
            static Gerenciador_Estados* pEstado;
            Entidades::Personagens::Jogador* pJog1;
            Gerenciador_Estados(); // Padrao Singleton para garantir unicidade do gerenciador de eventos
        public:
            ~Gerenciador_Estados();
            static Gerenciador_Estados* getGerenciadorEstados();
            void adicionarEstado(const IDs::ID ID);
            void setJogadores(Entidades::Personagens::Jogador* pJ1);
            void removerEstado();
            Estados::Estado* getEstadoAtual();
            void executar(); 
        };
    }
}