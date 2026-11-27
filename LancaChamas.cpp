#include "LancaChamas.hpp"
#include "Jogador.hpp"

namespace Castelos_e_ruinas {
    namespace Entidades {
        namespace Obstaculos {

            LancaChamas::LancaChamas(const sf::Vector2f pos, const sf::Vector2f tam):
                Obstaculo(pos, tam, IDs::ID::lancaChamas),
                desaceleracao(DESACELERACAO_CHAMAS),
                tempoDano(TEMPO_DANO_CHAMAS)
            {
                sf::Texture* text = carregarText("../assets/lancaChamas.png");
                //text->setRepeated(true);
                corpo.setTexture(text);
                //corpo.setTextureRect(sf::IntRect(0, 0, static_cast<int>(tam.x), text->getSize().y));
                danoso = true;
            }

            LancaChamas::~LancaChamas() {
            }

            void LancaChamas::executar() {
                gravidade();
                antigravidade();
            }

            void LancaChamas::salvar() {
            }

            void LancaChamas::obstaculizar(Personagens::Jogador* p) {
                if (p != NULL) {
                    //Aplica dano apenas enquanto permanecer sobre o fogo (com um intervalo)
                    if (relogioDano.getElapsedTime().asSeconds() >= tempoDano) {
                        p->operator--();
                        relogioDano.restart();
                    }

                    //Aplica lentidão enquanto estiver encima
                    p->desaceleracao(desaceleracao);
                }
            }

        }
    }
}