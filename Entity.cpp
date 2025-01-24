#include "Entity.h"

void continueAnimation(shared_ptr<Sprite> sprite) {
    const Texture* texture = sprite->getTexture();
    if (sprite->getTextureRect().left >= texture->getSize().x - sprite->getTextureRect().width) {
        sprite->setTextureRect(IntRect(0, 0, sprite->getTextureRect().width, sprite->getTextureRect().height));
    }
    else {
        IntRect rect = sprite->getTextureRect();
        rect.left += sprite->getTextureRect().width;
        sprite->setTextureRect(rect);
    }
}
