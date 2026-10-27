#pragma once
#include "Jogador.hpp"
#include "GerenciadorGrafico.hpp"

namespace nomeDoJogo{
    class Jogo{
    private:
        Entidades::Personagens::Jogador *pJog1;
        Gerenciadores::Gerenciador_Grafico *GG;
    public:
        Jogo();
        ~Jogo();
        void executar();
    };
}