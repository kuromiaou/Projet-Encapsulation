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

Texture red_potionTexture;
void createMap(Manager* manager) {
    ifstream file("Assets\\Map\\map.txt"); 
    if (!file) {
        cerr << "Unable to open file";
    }
    char ch;
    int i=0, x=0, y=0;
    while (file.get(ch)) {
        switch (ch) {
        case 'W' :
            manager->createWall(Vector2i{ x,y });
            x += 64;
            i++;
            break;
        case 'D' :
            manager->createDoor(Vector2i{ x,y });
            x += 48;
            i++;
            break;
        case 'F':
            manager->createFloor(Vector2i{ x,y });
            x += 48;
            i++;
            break;
        }
        
    }
    cout << endl;


    file.close();
}

int main()
{
    red_potionTexture.loadFromFile("Assets/Entity/Objects/Potion/red_potion.png");
    srand(time(0));
    Game game;
    Manager* manager = Manager::getInstance();

    createMap(manager);

    Player* player = manager->createPlayer(Vector2i {200,200});
    PatrollingEnemy* enemy1 = manager->createPatrollingEnemy(Vector2i{ 20,20 });
    ChaserEnemy* enemy2 = manager->createChaserEnemy(Vector2i{ 500,500 });
    Potion* potion1 = manager->createPotion(Vector2i {500,500},red_potionTexture);
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

        for (int i=0; i<manager->getallWalls().size();i++)
            

        player->userInput();
        player->draw(window);

        enemy2->draw(window);
        enemy2->chasePlayer(*player);
        enemy2->move();

        enemy1->draw(window);
        enemy1->move();
        //if (potion1 != nullptr) cout << "uzu";
        
        cout <<endl <<"eee" << enemy2->getBehaviour().x << enemy2->getBehaviour().y<<endl;
        if (enemy1->getTiles() > 100) { enemy1->reverseBehaviour(); enemy1->setTiles(0); }
        //cout << endl << enemy1->getTiles() << endl;
        cout << player->getSpeed();
        if (enemy2->isColliding(*player)) { /*window.close();*/ }
        if (potion1->isColliding(*player)) { 
            potion1->interact(*player); 
            cout << "OOOO";
            manager->deletePotion(potion1);
            //delete potion1;
        }
        else if (!potion1->isObtained){
            potion1->draw(window);
        }

        window.display();
    }
    delete manager;
    delete player;
    delete enemy1;
    delete enemy2;
    delete potion1;

    return 727;
}