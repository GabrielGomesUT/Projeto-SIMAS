#pragma once
#include "Menu.hpp"
#include <vector>
#include <fstream>
#include <string>

namespace Castelos_e_ruinas{

    namespace Botoes{

        class Texto;
    }

    namespace Menus{

        class MenuColocacao : public Menu{
        private:
            std::vector<Botoes::Texto*> rank;
            std::ifstream arquivo;
            void criarBotoes();
            void criarFundo();
            void criarColocacao();  // codigo adaptado dos videos do monitor Giovane Limas Salvi
            void criarTexto(std::string String);
            void desenharColocacao();
        public:
            MenuColocacao();
            ~MenuColocacao();
            void selecionar();
            void executar();
        };
    }
}