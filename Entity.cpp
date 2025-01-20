#include "Entity.h"

void continueAnim(Sprite* sprite){
    const Texture* texture = sprite->getTexture();
    if (sprite->getTextureRect().left >= texture->getSize().x - sprite->getTextureRect().width) {

    }
}
