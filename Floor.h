#pragma once
#include "Entity.h"
class Floor :
    public Entity
{
private:
    Vector2i pos;
public:
    Texture floorTexture;
    Sprite floorSprite;
    
    Floor(Vector2i);

    void draw(RenderWindow& window) override;
    void update(float) override;
};

