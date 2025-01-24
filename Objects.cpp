#include "Objects.h"

Objects::Objects(Vector2i _POS,Texture& _TEXTURE) : pos(_POS), texture(_TEXTURE) { sprite.setTexture(texture); sprite.setTextureRect(IntRect(0,0, texture.getSize().y, texture.getSize().y)); sprite.setPosition(_POS.x, _POS.y); }

void Objects::draw(RenderWindow& window) { window.draw(sprite); }

Vector2i Objects::getPos() { return pos; }

void Objects::update(float deltaTime) {};

bool Objects::isColliding(Player other) {
    if (sprite.getGlobalBounds().intersects(other.rect.getGlobalBounds())) return true;
    else return false;
}