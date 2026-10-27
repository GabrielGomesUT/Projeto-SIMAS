#pragma once
#include "Jogador.hpp"
#include "Inimigo.hpp"
#include "GerenciadorGrafico.hpp"
#include <vector>
#include <time.h>

namespace nomeDoJogo{
    class Jogo{
    private:
        Entidades::Personagens::Jogador *pJog1;
        Gerenciadores::Gerenciador_Grafico *GG;
        vector<Entidades::Personagens::Personagem*> vetPersonagens;
    public:
        Jogo();
        ~Jogo();
        void executar();
    };
}