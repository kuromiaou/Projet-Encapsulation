#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>

#include "Game.h"
#include "Manager.h"
#include "Level.h"

using namespace std;
using namespace sf;


int main()
{
    srand(time(0)); // if you wish to do some randomization for level selection

    Level* level = new Level;

    level->level0();

    delete level;
    return 727;
}