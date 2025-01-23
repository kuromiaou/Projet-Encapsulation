#include "Level.h"
int width = 1280;
int height = 700;
ifstream map0, map1, map2;
void createMap(Manager* manager, int n) {
    map0.open("Assets\\Map\\level0.txt");
    map1.open("Assets\\Map\\level1.txt");
    map2.open("Assets\\Map\\level2.txt");
    char ch;
    int i = 0, x = 0, y = 0;
    switch (n) {
    case 0:
        if (!map0) {
            cerr << "Unable to open file";
        }

        while (map0.get(ch)) {
            switch (ch) {
            case 'W':
                manager->createWall(Vector2i{ x,y });
                x += 32;
                i++;
                break;
            case 'D':
                manager->createDoor(Vector2i{ x,y });
                x += 48;
                i++;
                break;
            case 'F':
                manager->createFloor(Vector2i{ x,y });
                x += 32;
                i++;
                break;
            }
            if (i == 41) {
                y += 32; x = 0; i = 0;
            }

        }
        cout << endl;
        map0.close();
        break;
    case 1:
        if (!map1) {
            cerr << "Unable to open file";
        }

        while (map1.get(ch)) {
            switch (ch) {
            case 'W':
                manager->createWall(Vector2i{ x,y });
                x += 32;
                i++;
                break;
            case 'D':
                manager->createDoor(Vector2i{ x,y });
                x += 48;
                i++;
                break;
            case 'F':
                manager->createFloor(Vector2i{ x,y });
                x += 32;
                i++;
                break;
            }
            if (i == 41) {
                y += 32; x = 0; i = 0;
            }

        }
        cout << endl;
        map1.close();
        break;
    case 2:
        if (!map2) {
            cerr << "Unable to open file";
        }

        while (map2.get(ch)) {
            switch (ch) {
            case 'W':
                manager->createWall(Vector2i{ x,y });
                x += 32;
                i++;
                break;
            case 'D':
                manager->createDoor(Vector2i{ x,y });
                x += 48;
                i++;
                break;
            case 'F':
                manager->createFloor(Vector2i{ x,y });
                x += 32;
                i++;
                break;
            }
            if (i == 41) {
                y += 32; x = 0; i = 0;
            }

        }
        cout << endl;
        map2.close();
        break;
    }
}



RenderWindow window(VideoMode(width, height, 32), "~Project Escaping~", Style::Titlebar | Style::Close);

void Level::level0() {
    srand(time(0));

    Manager* manager = Manager::getInstance();

    red_potionTexture.loadFromFile("Assets/Entity/Objects/Potion/red_potion.png");
    keyTexture.loadFromFile("Assets\\Entity\\Objects\\Key\\Key.png");

    createMap(manager, 0);

    Player* player = manager->createPlayer(Vector2i{ width / 2,height / 2 });
    ChaserEnemy* e2 = manager->createChaserEnemy(Vector2i{ 1000,500 });
    ChaserEnemy* e3 = manager->createChaserEnemy(Vector2i{ 0,500 });
    ChaserEnemy* e4 = manager->createChaserEnemy(Vector2i{ 1000,0 });
    Potion* potion1 = manager->createPotion(Vector2i{ 700,150 }, red_potionTexture);
    Potion* potion2 = manager->createPotion(Vector2i{ 700,250 }, red_potionTexture);
    Potion* potion3 = manager->createPotion(Vector2i{ 700,300 }, red_potionTexture);
    Key* key1 = manager->createKey(Vector2i{ -10,-10 }, keyTexture);

    window.setFramerateLimit(60);


    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
        }
        window.clear();

        for (auto& walls : manager->getallWalls()) {
            walls->draw(window);
        }
        for (auto& doors : manager->getallDoors()) {
            doors->draw(window);
        }
        for (auto& floors : manager->getallFloors()) {
            floors->draw(window);
        }

        player->userInput();
        player->draw(window);

        e2->draw(window);
        e2->chasePlayer(*player);
        e2->move();
        e3->draw(window);
        e3->chasePlayer(*player);
        e3->move();
        e4->draw(window);
        e4->chasePlayer(*player);
        e4->move();



        //cout << endl << "eee" << e2->getBehaviour().x << " " << e2->getBehaviour().y << endl;
        cout << player->getSpeed();
        if (e2->isColliding(*player)) { /*window.close();*/ }
        for (auto& potionX : manager->getallPotions()) {
            if (potionX->isColliding(*player)) {
                potionX->interact(*player);
                cout << "OOOO";
                manager->deletePotion(potionX);
            }
            else if (!potionX->isObtained) {
                potionX->draw(window);
            }
        }
        if (key1->isColliding(*player)) {
            key1->interact(*player);
            player->canLvlUp = true;
            cout << "Door Opened.";
            manager->deleteKey(key1);
        }
        else if (!key1->isObtained and player->state==3) {
            key1->sprite.setPosition(200, 200);
            key1->draw(window);
        }

        for (auto& doors : manager->getallDoors()) {
            if (doors->isColliding(*player)) {
                if (player->canLvlUp and Keyboard::isKeyPressed(Keyboard::E) and !doors->isOpened) {
                    doors->doorSprite.setTexture(doors->doorTextureOpened);
                    player->canLvlUp = false;
                    doors->isOpened = true;
                }
                if (doors->isOpened) {
                    XXX = player->getPos().x;
                    YYY = player->getPos().y;
                    level1();
                }
            }
        }



        window.display();
    }
    delete player;
    delete e2, e3, e4;
    delete potion1;
    delete key1;
    delete manager;

}

void Level::level1() {
    srand(time(0));

    Manager* manager = Manager::getInstance();

    red_potionTexture.loadFromFile("Assets/Entity/Objects/Potion/red_potion.png");
    keyTexture.loadFromFile("Assets\\Entity\\Objects\\Key\\Key.png");

    for (auto& walls : manager->getallWalls()) {
        manager->deleteWall(walls);
    }
    for (auto& doors : manager->getallDoors()) {
        manager->deleteDoor(doors);
    }
    for (auto& floors : manager->getallFloors()) {
        manager->deleteFloor(floors);
    }

    createMap(manager, 1);


    Player* player = manager->createPlayer({ XXX,YYY });
    PatrollingEnemy* pe1 = manager->createPatrollingEnemy(Vector2i{ 20,20 });

    cout << "\nWelcome to level 1 Player.\nPlease continue to explore this dungeon if you wish to get out.\n";


    while (window.isOpen()) {
        window.clear();

        for (auto& walls : manager->getallWalls()) {
            walls->draw(window);
        }
        for (auto& doors : manager->getallDoors()) {
            doors->draw(window);
        }
        for (auto& floors : manager->getallFloors()) {
            floors->draw(window);
        }


        player->userInput();
        player->draw(window);


        if (pe1->getTiles() > 100) { pe1->reverseBehaviour(); pe1->setTiles(0); }
        //cout << endl << pe1->getTiles() << endl;
        pe1->draw(window);
        pe1->move();
        window.display();
    }
    delete pe1;
    delete player;
    delete manager;
}