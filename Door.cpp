#include "Door.h"
Door::Door(Vector2i _POS) {
	doorTextureOpened.loadFromFile("Assets\\Map\\Door_Opened.png");
	doorTextureClosed.loadFromFile("Assets\\Map\\Door_Closed.png"); 
	doorSprite.setTexture(doorTextureClosed);	
	doorSprite.setPosition(_POS.x, _POS.y);
}
void Door::update(float) {};
void Door::draw(RenderWindow& window) { window.draw(doorSprite); }
Vector2i Door::getPos() { return Vector2i {doorSprite.getPosition() }; }
bool Door::isColliding(Player other) {
	if (doorSprite.getGlobalBounds().intersects(other.rect.getGlobalBounds())) return true;
	else return false; }
