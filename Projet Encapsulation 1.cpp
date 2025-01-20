#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>

#include "Game.h"
#include "Player.h"


using namespace std;
using namespace sf;

int width = 1280;
int height = 720;

int main()
{
    srand(time(0));
    Game game;
    Manager* manager = Manager::getInstance();
    Player* player = manager->createPlayer(Vector2i {10,10});
    PatrollingEnemy* enemy1 = manager->createPatrollingEnemy(Vector2i{ 20,20 });
    RenderWindow window(VideoMode(width, height, 32), "~Project Escaping~", Style::Titlebar | Style::Close);

    Texture bg;
    bg.loadFromFile("Assets/BG/black.jpg");
    Sprite bgSprite;
    bgSprite.setTexture(bg);

    //window.draw(bgSprite);
    window.setFramerateLimit(60);
    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
        }
        window.clear();
        player->userInput();
        player->draw(window);
        enemy1->draw(window);
        enemy1->move();
        if (enemy1->getTiles() > 100) { enemy1->reverseBehaviour(); enemy1->setTiles(0); }
        cout << endl << enemy1->getTiles() << endl;
        window.display();
    }
    delete manager;
    delete player;
}