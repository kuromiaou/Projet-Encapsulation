#include "Potion.h"

Potion::Potion(Vector2i _POS, Texture& _TEXTURE) : Objects(_POS, _TEXTURE) { sprite.setScale(2, 2); }

void Potion::interact(Player& player) { if (isColliding(player)) if(!isObtained){ player.increaseSpeed(/*Nothing means 1*/); isObtained = true; cout << "You have obtained a potion."; } }