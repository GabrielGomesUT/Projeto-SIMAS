#include "Piso.hpp"
#include "Jogador.hpp"
//#include "Personagem.hpp"

namespace Castelos_e_ruinas{

    namespace Entidades{
        
        Piso::Piso(const sf::Vector2f pos, const sf::Vector2f tam):
        Entidade(pos,tam,IDs::ID::piso),ajuda(false){
            sf::Texture* text = carregarText("../assets/piso.png");
            corpo.setTexture(text);
            coolDown = 300;
        }

        Piso::~Piso(){

        }

        void Piso::colisao(Personagens::Personagem* pPer,sf::Vector2f ds){
            if(pPer != NULL){
                float invasaoX = fabs(ds.x);
                float invasaoY = fabs(ds.y);
                if((invasaoX < invasaoY) && (this->getID() != IDs::ID::lama)){ // colisão lateral
                    if(pPer->getPos().x < this->getPos().x){
                        pPer->setPos(sf::Vector2f((pPer->getPos().x - invasaoX),pPer->getPos().y));
                    }
                    else{
                        pPer->setPos(sf::Vector2f((pPer->getPos().x + invasaoX),pPer->getPos().y));
                    }
                }
                else{    //colisao vertical
                    if(pPer->getPos().y < this->getPos().y){  //piso
                        pPer->setPos(sf::Vector2f(pPer->getPos().x,(pPer->getPos().y - invasaoY)));
                        if(pPer->getID() == IDs::ID::jogador){
                            Personagens::Jogador* pJog = dynamic_cast<Personagens::Jogador*>(pPer);
                            pJog->setPodePular(true);
                            ajudar(pJog);
                        }
                    }
                pPer->setVelY(0.0f);
                }
            }
        }

        void Piso::ajudar(Entidades::Personagens::Jogador* pJ){
            if((ajuda) && (pJ->getNumVida() < VIDA_JOGADOR))
                pJ->operator++();
        }

        void Piso::executar(){
            ajuda = false;
            if(coolDown < 0){
                ajuda = true;
                coolDown = 300;
            }
            coolDown--;
        }

        void Piso::salvar(){

        }
    }
}