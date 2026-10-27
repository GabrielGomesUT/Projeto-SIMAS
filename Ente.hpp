#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;

namespace nomeDoJogo{

    namespace Gerenciadores{
        class Gerenciador_Grafico;
    }

    class Ente{
    protected:  
        int id;
        static Gerenciadores::Gerenciador_Grafico* pGG;
        static int cont;
    public:
        Ente();
        virtual ~Ente();
        //virtual void executar();
        void desenhar();
        static void setGG(Gerenciadores::Gerenciador_Grafico* pG);
        int getID();
        virtual sf::RectangleShape getSprite() const = 0;
    };
}