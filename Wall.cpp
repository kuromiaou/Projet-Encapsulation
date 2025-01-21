#include "Wall.h"
Wall::Wall(Vector2i _POS) { 
	wallTexture.loadFromFile("Assets\\Map\\Wall.png");
	wallSprite.setTexture(wallTexture);
	wallSprite.setPosition(_POS.x, _POS.y); }

void Wall::update(float) {};
void Wall::draw(RenderWindow& window) { window.draw(wallSprite); }
