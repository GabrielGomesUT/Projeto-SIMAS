
#pragma once
#include "Jogador.hpp"
#include "Inimigo.hpp"
#include "Obstaculo.hpp"
#include "Fase.hpp"
#include "GerenciadorGrafico.hpp"
#include "GerenciadorEventos.hpp"
#include "GerenciadorColisoes.hpp"
#include "ListaEntidades.hpp"
#include <stdlib.h>
#include <time.h>

namespace Castelos_e_ruinas{

    namespace Menus{
        class MenuPrincipal;
    }

    class Jogo{
    private:
        Entidades::Personagens::Jogador *pJog1;
        Entidades::Personagens::Jogador *pJog2;
        Gerenciadores::Gerenciador_Grafico *GG;
        Gerenciadores::Gerenciador_Eventos *GE;
        Menus::MenuPrincipal* pMenuPrincipal;
        Fases::Fase* pFase;
        bool pausado;
        bool sair;
    public:
        Jogo(Menus::MenuPrincipal* pMP);
        ~Jogo();
        void criarFase(int nFase);
        void pausar();
        void continuar();
        void voltarMenu();
        void setSair(bool s);
        void executar();
    };
}