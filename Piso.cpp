#include "Piso.hpp"
#include "Jogador.hpp"

namespace Castelos_e_ruinas{
    namespace Entidades{
        namespace Obstaculos{
            Piso::Piso(const sf::Vector2f pos, const sf::Vector2f tam):Obstaculo(pos,tam,IDs::ID::piso),tempo_acumulado(0.0f){
                sf::Texture* text = carregarText("../assets/piso.png");
                text->setRepeated(true);    //permite a repeticao da textura
                corpo.setTexture(text);
                corpo.setTextureRect(sf::IntRect(0, 0, 400, text->getSize().y));    //recorta a imagem a ajusta para caber no corpo
                danoso = false;
            }
            Piso::~Piso(){

            }
            void Piso::executar(){

            }
            void Piso::salvar(){

            }

            void Piso::obstaculizar(Personagens::Jogador* p){
                dt = relogio.getElapsedTime().asSeconds();
                tempo_acumulado += dt;
                if(tempo_acumulado >= 5.0f){
                    p->operator++();
                    tempo_acumulado = 0.0;
                }
            }
        }
    }
}