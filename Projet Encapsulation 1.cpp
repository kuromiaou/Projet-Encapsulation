#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>

#include "Game.h"
#include "Manager.h"
#include "Level.h"
#include "startScreen.h"

using namespace std;
using namespace sf;


int main()
{
    srand(time(0)); // if you wish to do some randomization for level selection
    Image icon; icon.loadFromFile("Assets/Icon/jinx.jpg");
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    startScreen* sc = new startScreen;

    sc->show();
    delete sc;
    return 727;
}