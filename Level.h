#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>

#include "Game.h"
#include "Manager.h"
using namespace std;
using namespace sf;
extern int width;
extern int height;
extern RenderWindow window;
class Level
{
private:
	int XXX, YYY;
public:
	Texture red_potionTexture, keyTexture;
	void level0();
	void level1();
	void level2();
};

