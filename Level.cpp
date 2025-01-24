#include "Level.h"
int width = 1280;
int height = 700;

void Level::end() {
    window.close();
    while (true) {
        RenderWindow videoWindow(VideoMode(1920, 1080), "Easter Egg");
        while (videoWindow.isOpen()) {
            Event event;
            while (videoWindow.pollEvent(event)) {
                if (event.type == Event::Closed)
                    videoWindow.close();
            }

            videoWindow.clear();
            videoWindow.draw(lose_screen);
            videoWindow.draw(losing_text);
            videoWindow.display();
            if (Keyboard::isKeyPressed(Keyboard::Tab)) {
                videoWindow.close();
                RenderWindow window(VideoMode(width, height, 32), "~Project Escaping~", Style::Titlebar | Style::Close);
                level0();
            }

        }
        
    }
}
Level::Level() {
    map0.open("Assets\\Map\\level0.txt");
    map1.open("Assets\\Map\\level1.txt");
    map2.open("Assets\\Map\\level2.txt");
    red_potionTexture.loadFromFile("Assets/Entity/Objects/Potion/red_potion.png");
    keyTexture.loadFromFile("Assets\\Entity\\Objects\\Key\\Key.png");
    losing_font.loadFromFile("Assets/Font/pixel.ttf");
    losing_text.setFont(losing_font);
    losing_text.setFillColor(Color::White);
    losing_text.setString("L.L.L\n   Press tab to restart. \n(Please don't do that it will crash ^^')");
    losing_text.setPosition(1920 / 2, 1080 / 2);
}



void Level::createMap(Manager* manager, int n) {
    
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

    

    createMap(manager, 0);

    Player* player = manager->createPlayer(Vector2i{ width / 2,height / 2 });
    ChaserEnemy* e1 = manager->createChaserEnemy(Vector2i{ 100,100 });
    ChaserEnemy* e2 = manager->createChaserEnemy(Vector2i{ 1000,100 });
    ChaserEnemy* e3 = manager->createChaserEnemy(Vector2i{ 100,600 });
    ChaserEnemy* e4 = manager->createChaserEnemy(Vector2i{ 1000,600 });
    ChaserEnemy* e5 = manager->createChaserEnemy(Vector2i{ 1000,0 });
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

        e1->draw(window);
        e1->chasePlayer(*player);
        e1->move();
        e2->draw(window);
        e2->chasePlayer(*player);
        e2->move();
        e3->draw(window);
        e3->chasePlayer(*player);
        e3->move();
        e4->draw(window);
        e4->chasePlayer(*player);
        e4->move();
        e5->draw(window);
        e5->chasePlayer(*player);
        e5->move();



        //cout << endl << "eee" << e2->getBehaviour().x << " " << e2->getBehaviour().y << endl;
        cout << player->getSpeed();
        for(auto& eX : manager->getallChaEnemies())
        if (eX->isColliding(*player)) {
            
            end();            

        }
        for (auto& potionX : manager->getallPotions()) {
            if (potionX->isColliding(*player)) {
                potionX->interact(*player);
                cout << "OOOO";
                manager->deletePotion(potionX);
            }
            else if (!potionX->isObtained) {
                /*if (timer.getElapsedTime().asSeconds() > .25f) {
                    continueAnim(&potionX->sprite);
                }
                timer.restart();*/
                potionX->draw(window);
            }
        }
        if (key1->isColliding(*player)) {
            key1->interact(*player);
            player->canLvlUp = true;
            cout << "Door Opened.";
            manager->deleteKey(key1);
            for (auto& eX : manager->getallChaEnemies())
                eX->setSpeed(eX->getSpeed()*1.25f);
        }
        else if (!key1->isObtained and player->state==3) {
            key1->sprite.setPosition(200, 200);
            key1->draw(window);
        }
        /*for (auto& walls : manager->getallWalls()) {      //NO WALLS COLLISION
            if (walls->isColliding(*player)) {
                switch (player->facing) {
                case 0:
                    player->rect.setPosition({ (float)player->getPos().x,(float)player->getPos().y + 10 });
                    break;
                case 1:
                    player->rect.setPosition({ (float)player->getPos().x+10,(float)player->getPos().y });
                    break;
                case 2:
                    player->rect.setPosition({ (float)player->getPos().x,(float)player->getPos().y - 10 });
                    break;
                case 3:
                    player->rect.setPosition({ (float)player->getPos().x - 10,(float)player->getPos().y });
                    break;

                }
            }
        }*/
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

    /*for (auto& walls : manager->getallWalls()) {
        manager->deleteWall(walls);
    }
    for (auto& doors : manager->getallDoors()) {
        manager->deleteDoor(doors);
    }
    for (auto& floors : manager->getallFloors()) {
        manager->deleteFloor(floors);
    }*/

    createMap(manager, 0);


    Player* player = manager->createPlayer({ XXX,YYY });
    PatrollingEnemy* pe1 = manager->createPatrollingEnemy(Vector2i{ 100,100 });
    PatrollingEnemy* pe2 = manager->createPatrollingEnemy(Vector2i{ 100,200 });
    PatrollingEnemy* pe3 = manager->createPatrollingEnemy(Vector2i{ 100,300 });
    PatrollingEnemy* pe4 = manager->createPatrollingEnemy(Vector2i{ 100,400 });
    PatrollingEnemy* pe5 = manager->createPatrollingEnemy(Vector2i{ 100,500 });
    PatrollingEnemy* pe6 = manager->createPatrollingEnemy(Vector2i{ 100,600 });
    Potion* potion1 = manager->createPotion(Vector2i{ 400,150 }, red_potionTexture);
    Potion* potion2 = manager->createPotion(Vector2i{ 700,150 }, red_potionTexture);
    Potion* potion3 = manager->createPotion(Vector2i{ 550,200 }, red_potionTexture);
    Key* key1 = manager->createKey(Vector2i{ -10,-10 }, keyTexture);
    Key* key2 = manager->createKey(Vector2i{ -10,-10 }, keyTexture);
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
        
        /*for (auto& walls : manager->getallWalls()) {
            if (walls->isColliding(*player)) {
                switch (player->facing) {
                case 0:
                    player->rect.setPosition({ (float)player->getPos().x,(float)player->getPos().y + 5 });
                    break;
                case 1:
                    player->rect.setPosition({ (float)player->getPos().x + 10,(float)player->getPos().y });
                    break;
                case 2:
                    player->rect.setPosition({ (float)player->getPos().x,(float)player->getPos().y - 5 });
                    break;
                case 3:
                    player->rect.setPosition({ (float)player->getPos().x - 5,(float)player->getPos().y });
                    break;

                }
            }
        }*/
        player->userInput();
        player->draw(window);

        for(auto& peX : manager->getallPatEnemies())
        if (peX->getTiles() > 100) { peX->reverseBehaviour(); peX->setTiles(0); }
        //cout << endl << pe1->getTiles() << endl;
        pe1->draw(window);
        pe1->move(); 
        pe2->draw(window);
        pe2->move(); 
        pe3->draw(window);
        pe3->move(); 
        pe4->draw(window);
        pe4->move(); 
        pe5->draw(window);
        pe5->move();
        pe6->draw(window);
        pe6->move();
        
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
        for (auto& keyX : manager->getallKeys()) {
            if (keyX->isColliding(*player)) {
                keyX->interact(*player);
                player->canLvlUp = true;
                cout << "Door Opened.";
                manager->deleteKey(keyX);
                for (auto& eX : manager->getallChaEnemies())
                    eX->setSpeed(eX->getSpeed() * 1.25f);
            }
            else if (!keyX->isObtained and player->state == 3) {
                keyX->sprite.setPosition(1000, 200);
                keyX->draw(window);
            }

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
    delete pe1;
    delete pe2;
    delete pe3;
    delete pe4;
    delete pe5;
    delete pe6;
    delete potion1;
    delete potion2;
    delete potion3;
    delete key1;
    delete key2;
    delete player;
    delete manager;
}

