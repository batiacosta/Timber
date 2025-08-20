#include <iostream>
#include <optional>
#include <print>
#include "SFML/Graphics.hpp"



int main(){
    sf::VideoMode vm({1920, 1080});
    sf::RenderWindow window(vm, "Timber", sf::Style::Default);

    const sf::Texture textureBackground("assets/textures/background.png");
    sf::Sprite spriteBackground(textureBackground);
    spriteBackground.setPosition({0,0});

    while(window.isOpen()){
        while (const std::optional<sf::Event> event = window.pollEvent()) {
            // Close window then exit
            if(event->is<sf::Event::Closed>()){
                window.close();
            }
        }

        // Handle the players input
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)){
            window.close();
        }

        // Update the scene
        window.clear();
        // Draw the scene
        window.draw(spriteBackground);
        window.display();
    }
    return 0;
}
