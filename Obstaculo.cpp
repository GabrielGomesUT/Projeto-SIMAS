#include "Obstaculo.hpp"

namespace nomeDoJogo{

    namespace Entidades{

        Obstaculo::Obstaculo(const sf::Vector2f pos, const sf::Vector2f tam):Entidade(pos,tam),danoso(false){
            corpo.setFillColor(sf::Color::Yellow);
        }

        Obstaculo::~Obstaculo(){

        }

        void salvarDataBuffer(){

        }

        void Obstaculo::salvar(){

        }

        void Obstaculo::executar(){

        }
        //void obstaculizar(Personagens::Jogador* p);

        sf::RectangleShape Obstaculo::getSprite() const{
            return corpo;
        }
    }

}