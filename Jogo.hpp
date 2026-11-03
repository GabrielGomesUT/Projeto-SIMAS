#pragma once
#include "Jogador.hpp"
#include "Inimigo.hpp"
#include "Obstaculo.hpp"
#include "GerenciadorGrafico.hpp"
#include "GerenciadorEventos.hpp"
#include <vector>
#include <time.h>

namespace Castelos_e_ruinas{
    class Jogo{
    private:
        Entidades::Personagens::Jogador *pJog1;
        Gerenciadores::Gerenciador_Grafico *GG;
        Gerenciadores::Gerenciador_Eventos *GE;
        vector<Entidades::Personagens::Personagem*> vetPersonagens;
        vector<Entidades::Entidade*> vetObstaculos;
    public:
        Jogo();
        ~Jogo();
        void executar();
    };
}