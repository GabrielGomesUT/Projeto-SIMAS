#include <SFML/Graphics.hpp>

int main() {
    // Cria a janela do jogo
    sf::RenderWindow window(sf::VideoMode(400, 400), "O SFML Funciona!");
    
    // Cria um círculo verde
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    shape.setPosition(100.f, 100.f);

    // O Loop principal do jogo que mantém a janela aberta
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape); // Desenha o círculo
        window.display();
    }

    return 0;
}