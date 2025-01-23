#include "Wall.h"
Wall::Wall(Vector2i _POS) { 
	wallTexture.loadFromFile("Assets\\Map\\Wall.png");
	wallSprite.setTexture(wallTexture);
	wallSprite.setPosition(_POS.x, _POS.y);
}

void Wall::update(float) {};
void Wall::draw(RenderWindow& window) { window.draw(wallSprite); }

bool Wall::isColliding(Player other) {
	if (wallSprite.getGlobalBounds().intersects(other.rect.getGlobalBounds())) return true;
	else return false;
}