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
	ifstream map0, map1, map2;
	int XXX, YYY;
public:
	void end();
	void createMap(Manager* manager, int n);
	Level();
	Font losing_font;
	Text losing_text;
	Texture red_potionTexture, keyTexture;
	Sprite lose_screen;
	void level0();
	void level1();
	void level2();
	void death(Manager*);
};

