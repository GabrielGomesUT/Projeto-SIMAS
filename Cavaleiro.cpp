#include "Cavaleiro.hpp"
#include "Jogador.hpp"

namespace Castelos_e_ruinas {
    namespace Entidades {
        namespace Personagens {

            Cavaleiro::Cavaleiro(const sf::Vector2f pos, const sf::Vector2f tam):
                Inimigo(pos,tam,IDs::ID::cavaleiro),raio(0.0f)
            {
                sf::Texture* text = carregarText("../assets/cavaleiro.png");
                if(text != NULL)
                    corpo.setTexture(text);
                num_vidas = VIDA_CAVALEIRO;
                nivel_maldade = NIVEL_MALDADE_CAVALEIRO;
                vel = sf::Vector2f(VELOCIDADE_CAVALEIRO_X,0.0f);
            }
            
            Cavaleiro::~Cavaleiro() {
            }

            //Usa a movimentação criada na classe Inimigo
            void Cavaleiro::executar() {
                mover();
            }

            //É chamado por Jogador::colisao() quando houver contato
            void Cavaleiro::danificar(Jogador* pJog) {
                if(pJog != NULL) {
                    for(int i = 0; i < nivel_maldade; ++i) {
                            pJog->operator--();
                    }
                }
            }

            void Cavaleiro::salvar() {

            }
        }
    }
}