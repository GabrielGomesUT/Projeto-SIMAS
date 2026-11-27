#include "Menu.hpp"
#include "GerenciadorGrafico.hpp"

namespace Castelos_e_ruinas{

    namespace Menus{

        Menu::Menu(const sf::Vector2f pos, const sf::Vector2f tam,IDs::ID ID):
        Ente(pos,tam,ID),titulo(sf::RectangleShape(sf::Vector2f(TAM_TITULO_X,TAM_TITULO_Y))){
            titulo.setPosition(sf::Vector2f(LARGURA_TELA/2.0f - TAM_TITULO_X/2.0f, 100.0f));
        }

        Menu::~Menu(){
            if(!listaBotao.empty()){
                Botoes::Botao* aux;
                for(it = listaBotao.begin();it != listaBotao.end();it++){
                    if(*it){
                        aux = *it;
                        delete aux;
                        aux = NULL;
                    }
                }
            }
        }

        void Menu::adicionaBotao(Botoes::Botao* bot){
            try{
                listaBotao.push_back(bot);
            }
            catch(const std::exception& e){
                cerr<<"Nao foi possivel adicionar botao"<<endl;
            }
        }

        void Menu::inicializaIterador(){
            if(!listaBotao.empty()){
                it = listaBotao.begin();
                (*it)->setSelecionado(true);
            }
        }

        void Menu::selecionaPCima(){
            (*it)->setSelecionado(false);
            if(it == listaBotao.begin())
                it = listaBotao.end();
            it--;
            (*it)->setSelecionado(true);            
        }

        void Menu::selecionaPBaixo(){
            if (!listaBotao.empty()){
                (*it)->setSelecionado(false);
                it++;
                if (it == listaBotao.end()) {
                    it = listaBotao.begin();
                }
                (*it)->setSelecionado(true);
            }
        }

        void Menu::desenharBotoes(){
            std::list<Botoes::Botao*>::iterator aux;
            for(aux = listaBotao.begin();aux != listaBotao.end();aux++){
                if(*aux){
                    Botoes::Botao* bot = *aux;
                    bot->executar();
                }
            }   
        }
    }
}