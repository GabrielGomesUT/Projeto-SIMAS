#include "Cavaleiro.hpp"
#include "Jogador.hpp"

namespace Castelos_e_ruinas {
    namespace Entidades {
        namespace Personagens {

            Cavaleiro::Cavaleiro(const sf::Vector2f pos, const sf::Vector2f tam):
                Inimigo(pos,tam,IDs::ID::cavaleiro),raio()
            {
                sf::Texture* text = carregarText("../assets/cavaleiro.png");
                if(text != NULL)
                    corpo.setTexture(text);
                vida_max = VIDA_CAVALEIRO;
                num_vidas = VIDA_CAVALEIRO;
                nivel_maldade = NIVEL_MALDADE_CAVALEIRO;
                vel = sf::Vector2f(VELOCIDADE_CAVALEIRO_X,0.0f);
                coolDown = 60;
                inicializaBarraVida();
            }
            
            Cavaleiro::~Cavaleiro() {
            }

            //Usa a movimentação criada na classe Inimigo
            void Cavaleiro::executar() {
                if(coolDown > 0)
                    coolDown--; 
                mover();
                atualizaBarraVida();
            }

            void Cavaleiro::danificar(Jogador* pJog) {
                if((pJog != NULL) && (coolDown == 0)) {
                    for(int i = 0; i < nivel_maldade; ++i) {
                        pJog->operator--();
                    }
                    coolDown = 60;
                }
            }

            void Cavaleiro::salvar() {

            }
        }
    }
}