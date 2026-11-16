#include "Obstaculo.hpp"

namespace Castelos_e_ruinas{
    namespace Entidades{

        namespace Personagens{
            class jogador;
        }

        namespace Obstaculos{
            class Plataforma:public Obstaculo{
            private:
                int altura;
            public:
                Plataforma(const sf::Vector2f pos, const sf::Vector2f tam);
                ~Plataforma();
                void executar();
                void salvar();
                void atualizar();
                void obstaculizar(Personagens::Jogador* p);
                sf::RectangleShape getSprite() const;
            }; 
        }
    }
}