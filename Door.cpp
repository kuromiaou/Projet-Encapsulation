#include "Door.h"
Door::Door(Vector2i _POS) {
	doorTextureOpened.loadFromFile("Assets\\Map\\Door_Opened.png");
	doorTextureClosed.loadFromFile("Assets\\Map\\Door_Closed.png"); 
	doorSprite.setTexture(doorTextureClosed); 
	doorSprite.setPosition(_POS.x, _POS.y);
}
void Door::update(float) {};
void Door::draw(RenderWindow& window) { window.draw(doorSprite); }
