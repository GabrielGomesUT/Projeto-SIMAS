#pragma once
#include "Ente.hpp"
#include <list>
#include <string>
#include "Botao.hpp"
#include "Texto.hpp"
#define TAM_TITULO_X 500.0f
#define TAM_TITULO_Y 300.0f

namespace Castelos_e_ruinas{

    namespace Menus{
        class Menu:public Ente{
        protected:
            list<Botoes::Botao*> listaBotao;
            list<Botoes::Botao*>::iterator it;
            const int tamBotao;
            sf::RectangleShape titulo;
        public:
            Menu(const sf::Vector2f pos, const sf::Vector2f tam,IDs::ID ID);
            virtual ~Menu();
            void adicionaBotao(Botoes::Botao* bot);
            void inicializaIterador();
            void selecionaPCima();
            void selecionaPBaixo();
            void desenharBotoes();
            virtual void selecionar() = 0;
            virtual void executar() = 0;
        };
    }
}