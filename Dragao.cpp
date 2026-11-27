#include "Dragao.hpp"
//#include "Projetil.hpp" //Falta fazermos
#include "Jogador.hpp"
#include <cmath>



//To pensando em usar "força" como uma resistencia do dragão, que o cavaleiro da menos dano dele

namespace Castelos_e_ruinas {
    namespace Entidades {
        namespace Personagens {

            Dragao::Dragao(const sf::Vector2f pos, const sf::Vector2f tam, Jogador* pJog) :
                Inimigo(pos, tam,IDs::ID::dragao),
                //pProjetil(NULL),
                tempo_disparo(0.0f)
            {
                sf::Texture* text = carregarText("../assets/dragao.png");
                corpo.setTexture(text);
                vida_max = VIDA_DRAGAO;
                num_vidas = VIDA_DRAGAO;
                nivel_maldade = NIVEL_MALDADE_DRAGAO;
                vel.x = VELOCIDADE_DRAGAO_X;
                vel.y = 0.0f;
                coolDown = 60;

                if (pJog != NULL) {
                    setJogador(pJog);
                }
                inicializaBarraVida();
            }

            Dragao::~Dragao() {
                //pProjetil = NULL;
            }

            /*void Dragao::setProjetil(Projetil* pProj) {
              if (pProj != NULL) {
                    pProjetil = pProj;
                }
            }*/

            //Mover prório do dragão, pois ele voa
            void Dragao::mover() {
                if (jogador != NULL) {

                    sf::Vector2f posJogador = jogador->getSprite().getPosition();
                    sf::Vector2f posDragao = corpo.getPosition();

                    //Acompanha o jogador no eixo X ou se move aleatorio
                    if (std::fabs(posJogador.x - posDragao.x) <= RAIO_PERSEGUICAO_X * 2.0f) {
                        persegueJogador(posJogador, posDragao);
                    } else {
                        moverAleatorio();
                    }

                    if (podeAndar) {
                        atualizaPosicao();
                    }

                    //Não tem a chamada da gravidade(), assim o Dragão permanece voando na altura inicial
                }
            }

            void Dragao::executar() {
                mover();
                if(coolDown > 0)
                    coolDown--;
                tempo_disparo += dt;
                if (tempo_disparo >= INTERVALO_DISPARO) {
                    //atirar();
                    tempo_disparo = 0.0f;
                }
                atualizaBarraVida();
            }

            /*void Dragao::atirar() {
                //Garanti que tem projetil para atirar, que o jogador existe e que o projetil não está ativo (ainda não foi lançado)
                if (pProjetil != NULL && jogador != NULL && !pProjetil->getAtivo()) {
                    sf::Vector2f posBoca(
                        corpo.getPosition().x + corpo.getSize().x / 2.0f,
                        corpo.getPosition().y + corpo.getSize().y
                    );

                    pProjetil->lancar(posBoca, jogador);
                }
            }*/

            void Dragao::danificar(Jogador* pJog) {
                 if ((pJog != NULL) && (coolDown == 0)) {
                    for (int i = 0; i < nivel_maldade; ++i) {
                        pJog->operator--();
                    }
                    coolDown = 60;
                }
            }

            void Dragao::salvar() {
            }

        }
    }
}