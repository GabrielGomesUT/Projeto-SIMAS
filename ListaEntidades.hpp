#pragma once
#include "Lista.hpp"
#include "Entidade.hpp"
#include "GerenciadorGrafico.hpp"
#include "Jogador.hpp"

namespace Castelos_e_ruinas{

    namespace Listas{

        class ListaEntidades{
        private:
            Lista<Entidades::Entidade> LEs;
        public:
            ListaEntidades();
            ~ListaEntidades();
            void incluirEntidades(Entidades::Entidade* pEnt);
            void removerEntidades(Entidades::Entidade* pE);
            Entidades::Entidade* operator[](int pos);
            int getTam();
            void setJogEnt(Entidades::Personagens::Jogador* pJ);
            void percorrer();
            void desenhar(Gerenciadores::Gerenciador_Grafico* pGG);
        };
    }
}