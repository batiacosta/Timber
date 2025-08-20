#include <iostream>
#include <optional>
#include <print>
#include "SFML/Graphics.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Text.hpp"
#include "SFML/Graphics/Texture.hpp"

int playerScore {0};
char playerInitial {'J'};
bool isAlive {true};

const float PI {3.141f};
const int TREE_HORIZONTAL_POSITION = 810;
const int TREE_VERTICAL_POSITION = 0;


int main(){
    sf::VideoMode vm({1920, 1080});
    sf::RenderWindow window(vm, "Timber", sf::Style::Default);

    const sf::Texture textureBackground("assets/textures/background.png");
    sf::Sprite spriteBackground(textureBackground);
    spriteBackground.setPosition({0,0});

    const sf::Texture textureTree("assets/textures/tree.png");
    sf::Sprite spriteTree(textureTree);
    spriteTree.setPosition({TREE_HORIZONTAL_POSITION, TREE_VERTICAL_POSITION});

    const sf::Texture textureBee("assets/textures/bee.png");
    sf::Sprite spriteBee(textureBee);
    spriteBee.setPosition({0, 800});
    bool isBeeMoving = false;
    float beeSpeed = 0.0f;

    const sf::Texture textureCloud("assets/textures/cloud.png");
    sf::Sprite spriteCloud1(textureCloud);
    spriteCloud1.setPosition({0,0});
    bool isCloud1Moving = false;
    float cloud1Speed = 0.0;
    sf::Sprite spriteCloud2(textureCloud);
    spriteCloud2.setPosition({0,250});
    bool isCloud2Moving = false;
    float cloud2Speed = 0.0;
    sf::Sprite spriteCloud3(textureCloud);
    spriteCloud3.setPosition({0,500});
    bool isCloud3Moving = false;
    float cloud3Speed = 0.0;
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
        window.draw(spriteCloud1);
        window.draw(spriteCloud2);
        window.draw(spriteCloud3);
        window.draw(spriteTree);
        window.draw(spriteBee);
        window.display();
    }
    return 0;
}
