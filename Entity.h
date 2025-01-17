#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
using namespace sf;

class Entity
{
private:
		
public:
	virtual void update(float deltaTime) = 0;
	virtual void draw(RenderWindow & window) = 0;
};

