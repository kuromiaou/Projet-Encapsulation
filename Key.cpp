#include "Key.h"


Key::Key(Vector2i _POS,Texture _TEXTURE) : Objects(_POS,_TEXTURE) {}

void Key::interact(Player& player) { if (isObtained) { player.increaseSpeed(2); cout << "You have obtained a key.\n You can now open the door to the next level." << endl; } }