#pragma once
#include "Menu.hpp"
#include <fstream>
#include "Fase.hpp"

namespace Castelos_e_ruinas{

    namespace Botoes{

        class Texto;
    }

    namespace Menus{

        class MenuFim:public Menu{
        private:
            std::ofstream arquivoEntrada;
            Botoes::Texto textoDigite;
            Botoes::Texto nomeExibido;
            Botoes::Texto pontuacao;
            void criarBotoes();
            void criarFundo();
        public:
            MenuFim(Fases::Fase* pF);
            ~MenuFim();
            void salvarColocacao(); // codigo adaptado dos videos do monitor Giovane Limas Salvi
            void digitar(char caracter);
            void selecionar();
            void executar();
        };
    }
}