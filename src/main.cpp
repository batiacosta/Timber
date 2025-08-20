#include <iostream>
#include "SFML/Graphics.hpp"
#include "SFML/Window/Event.hpp"

int main(){

    sf::RenderWindow window(sf::VideoMode({800, 600}), "Timber");
    window.setFramerateLimit(60);

    sf::CircleShape circle(50.0f);
    circle.setFillColor(sf::Color::Green);
    circle.setPosition({375.0f, 275.0f});
    std::cout << "Hello world!\n";
    while (window.isOpen()){
        while (const std::optional event = window.pollEvent()){
            if(event->is<sf::Event::Closed>()) {
                window.close();
            }
        }

        window.clear(sf::Color::Black);
        window.draw(circle);
        window.display();
    }
    return 0;
}
