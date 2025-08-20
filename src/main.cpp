#include <iostream>
#include <optional>
#include <print>
#include "SFML/Graphics.hpp"
#include "SFML/Window/WindowEnums.hpp"


int main(){
    sf::VideoMode vm({1920, 1080});
    sf::RenderWindow window(vm, "Timber", sf::Style::Default);
    while(window.isOpen()){
        std::print("the window just opened\n");
        while (const std::optional<sf::Event> event = window.pollEvent()) {
            // Close window then exit
            if(event->is<sf::Event::Closed>()){
                window.close();
            }
        }
        window.clear();
        window.display();
    }
    return 0;
}
