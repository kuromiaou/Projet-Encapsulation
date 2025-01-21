#pragma once
#include "Entity.h"
class Door :
    public Entity
{
private:

public:
    Texture doorTextureOpened, doorTextureClosed;
    Sprite doorSprite;

    Door(Vector2i);

    void draw(RenderWindow& window) override;
    void update(float) override;
};

