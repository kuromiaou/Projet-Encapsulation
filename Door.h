#pragma once
#include "Entity.h"
#include "Player.h"
class Door :
    public Entity
{
private:
public:
    bool isOpened=false;
    Texture doorTextureOpened, doorTextureClosed;
    Sprite doorSprite;

    Door(Vector2i);
    bool isColliding(Player other);
    void draw(RenderWindow& window) override;
    void update(float) override;
    Vector2i getPos();
};

