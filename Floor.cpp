#include "Floor.h"
Floor::Floor(Vector2i _POS) {
	floorTexture.loadFromFile("Assets\\Map\\Floor.png"); 
	floorSprite.setTexture(floorTexture);
	floorSprite.setPosition(_POS.x, _POS.y);
}

void Floor::update(float f) {};
void Floor::draw(RenderWindow& window) { window.draw(floorSprite); }

