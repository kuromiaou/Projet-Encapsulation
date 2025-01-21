#pragma once
#include "Entity.h"
class Wall :
    public Entity
{
private:
    //Vector2i pos;
public:
    Texture wallTexture;
    Sprite wallSprite;


    Wall(Vector2i);
    void update(float) override;
    void draw(RenderWindow& window) override;

};

