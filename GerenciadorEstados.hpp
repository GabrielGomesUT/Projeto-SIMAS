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
            Entidades::Personagens::Jogador* pJog2;
            IDs::ID Fase;
            bool solo;
            bool transicao;
            Gerenciador_Estados(); // Padrao Singleton para garantir unicidade do gerenciador de eventos
        public:
            ~Gerenciador_Estados();
            static Gerenciador_Estados* getGerenciadorEstados();
            void adicionarEstado(const IDs::ID ID);
            void setSolo(bool Solo);
            void setNFase(IDs::ID NFase);
            void setTransicao(bool Transicao);
            IDs::ID getNFase();
            void setJogadores(Entidades::Personagens::Jogador* pJ1,Entidades::Personagens::Jogador* pJ2);
            void removerEstado();
            void trocarEstado(IDs::ID ID);
            Estados::Estado* getEstadoAtual();
            void executar(); 
        };
    }
}