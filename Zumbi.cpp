#include "Zumbi.hpp"
#include "Jogador.hpp"

namespace Castelos_e_ruinas {
    namespace Entidades {
        namespace Personagens {

            Zumbi::Zumbi(const sf::Vector2f pos, const sf::Vector2f tam):
                Inimigo(pos, tam,IDs::ID::zumbi)
            {
                num_vidas = VIDA_ZUMBIE;
                nivel_maldade = NIVEL_MALDADE_ZUMBIE;
                vel = sf::Vector2f(VELOCIDADE_ZUMBIE_X,0.0f);
                corpo.setFillColor(sf::Color::Blue);
            }

            Zumbi::~Zumbi() {
            }

            void Zumbi::executar() {
                //Reaproveita mover de Inimigo
                mover();
            }

            void Zumbi::danificar(Jogador* pJog) {
                if (pJog != NULL) {
                    for (int i = 0; i < nivel_maldade; ++i) {
                        pJog->operator--();
                    }
                }
            }

            void Zumbi::salvar() {
                //Implementar junto com o sistema de salvamento
            }

        }
    }
}