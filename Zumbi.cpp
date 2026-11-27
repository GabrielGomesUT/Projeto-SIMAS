#include "Zumbi.hpp"
#include "Jogador.hpp"

namespace Castelos_e_ruinas {
    namespace Entidades {
        namespace Personagens {

            Zumbi::Zumbi(const sf::Vector2f pos, const sf::Vector2f tam):
                Inimigo(pos, tam,IDs::ID::zumbi),faminto(false)
            {
                vida_max = VIDA_ZUMBIE;
                num_vidas = VIDA_ZUMBIE;
                nivel_maldade = NIVEL_MALDADE_ZUMBIE;
                vel = sf::Vector2f(VELOCIDADE_ZUMBIE_X,0.0f);
                coolDown = 60;
                sf::Texture* text = carregarText("../assets/Zombie.png");
                corpo.setTexture(text);
                inicializaBarraVida();
            }

            Zumbi::~Zumbi() {
            }

            void Zumbi::executar() {
                faminto = false;
                int aleatorio = rand() % 1000;
                if(aleatorio < 1)
                    faminto = true;
                if(coolDown > 0)
                    coolDown--;
                mover();
                atualizaBarraVida();
            }

            void Zumbi::danificar(Jogador* pJog) {
                if ((pJog != NULL) && (coolDown == 0)) {
                    if(faminto)
                        nivel_maldade = 7;
                    for (int i = 0; i < nivel_maldade; ++i) {
                        pJog->operator--();
                    }
                    coolDown = 60;
                }
            }

            void Zumbi::salvar() {
                //Implementar junto com o sistema de salvamento
            }

        }
    }
}