#include "Zumbi.hpp"
#include "Jogador.hpp"

#define VIDA_ZUMBIE 5
#define NIVEL_MALDADE_ZUMBIE 1
#define VELOCIDADE_ZUMBIE_X 40.0f

namespace Castelos_e_ruinas {
    namespace Entidades {
        namespace Personagens {

            Zumbi::Zumbi(const sf::Vector2f pos, const sf::Vector2f tam, Jogador* pJog) :
                Inimigo(pos, tam)
            {
                if (pJog != NULL) {
                    setJogador(pJog);
                }
                num_vidas = VIDA_ZUMBIE;
                nivel_maldade = NIVEL_MALDADE_ZUMBIE;
                vel.x = VELOCIDADE_ZUMBIE_X;

                //Ajuste de cor para diferenciar do Cavaleiro
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