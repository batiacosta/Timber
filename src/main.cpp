#include <cstdlib>
#include <iostream>
#include <optional>
#include <print>
#include "SFML/Graphics.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Text.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "SFML/System/Clock.hpp"
#include "SFML/System/Time.hpp"

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

    int number = (std::rand() % 100);

    sf::Clock clock;
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
        sf::Time dt = clock.restart();

        if(!isBeeMoving){
            srand((int)time(0));
            beeSpeed = (std::rand() % 200) + 200;

            srand((int)time(0) * 10);
            float height = (std::rand() % 500) + 500;
            spriteBee.setPosition({2000, height});
            isBeeMoving = true;
        }else{
            spriteBee.setPosition({
                spriteBee.getPosition().x - (beeSpeed * dt.asSeconds()),
                spriteBee.getPosition().y
            });
            if(spriteBee.getPosition().x < -100) isBeeMoving = false;
        }

        if(!isCloud1Moving){
            srand((int)time(0) * 10);
            cloud1Speed = (std::rand() % 200);
            float height = (std::rand() % 150);
            spriteCloud1.setPosition({-200, height});
            isCloud1Moving = true;
        }else{
            spriteCloud1.setPosition({
                spriteCloud1.getPosition().x + (cloud1Speed * dt.asSeconds()),
                spriteCloud1.getPosition().y
            });
            if(spriteCloud1.getPosition().x > 2000) isCloud1Moving = false;
        }

        window.clear();

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
