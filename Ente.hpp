#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "ID.hpp"
#include <math.h>
using namespace std;

namespace Castelos_e_ruinas{

    namespace Gerenciadores{
        class Gerenciador_Grafico;
    }

    class Ente{
    protected:  
        IDs::ID id;
        static Gerenciadores::Gerenciador_Grafico* pGG;
    public:
        Ente(IDs::ID ID);
        virtual ~Ente();
        //virtual void executar();
        void desenhar();
        static void setGG(Gerenciadores::Gerenciador_Grafico* pG);
        IDs::ID getID();
        virtual sf::RectangleShape getSprite() const = 0;
    };
}