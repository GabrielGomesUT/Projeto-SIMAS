
#pragma once
#include "Jogador.hpp"
#include "GerenciadorGrafico.hpp"
#include "GerenciadorEventos.hpp"
#include "GerenciadorEstados.hpp"
#include <stdlib.h>
#include <time.h>

namespace Castelos_e_ruinas{


    class Jogo{
    private:
        Entidades::Personagens::Jogador *pJog1;
        Entidades::Personagens::Jogador *pJog2;
        Gerenciadores::Gerenciador_Grafico *GG;
        Gerenciadores::Gerenciador_Eventos *GE;
        Gerenciadores::Gerenciador_Estados *GEs;

    public:
        Jogo();
        ~Jogo();
        void executar();
    };
}