#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;
using namespace sf;

void continueAnim(Sprite*);



class Entity
{
private:
	Clock animTimer;
public:
	virtual void update(float deltaTime) = 0;
	virtual void draw(RenderWindow & window) = 0;
};

