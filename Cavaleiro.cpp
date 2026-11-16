#include "Cavaleiro.hpp"
#include "Jogador.hpp"
//Esses próximos defines ainda temos de ajustar os valores
#define VIDA_CAVALEIRO 3
#define NIVEL_MALDADE_CAVALEIRO 1 

namespace Castelos_e_ruinas {
    namespace Entidades {
        namespace Personagens {

            //Repassa pos e tam para Inimigo (que já carrega a textura e chama Inicializa())
            Cavaleiro::Cavaleiro(const sf::Vector2f pos, const sf::Vector2f tam, Jogador* pJog) :
                Inimigo(pos, tam, pJog)
            {
                num_vidas = VIDA_CAVALEIRO;
                nivel_maldade = NIVEL_MALDADE_CAVALEIRO;
                /*Aparentemente não precisamos de um setJogador() aqui, pois o ponteiro do jogador já é passado para o construtor de Inimigo, que é chamado na lista de inicialização.
                if(pJog != NULL) {
                    setJogador(pJog);
                }
                */
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