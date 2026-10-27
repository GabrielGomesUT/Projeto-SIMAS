#pragma once
#include <SFML/Graphics.hpp>

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