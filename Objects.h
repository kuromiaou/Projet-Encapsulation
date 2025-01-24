#pragma once
#include "Entity.h"
#include "Player.h"

class Objects :
    public Entity
{
private:
    Vector2i pos;
public:
    bool isObtained;
    Texture texture;
    Sprite sprite;

    Objects(Vector2i,Texture &texturee);

    virtual void interact(Player& player) = 0;    
    void draw(RenderWindow& window);
    Vector2i getPos();

    void update(float deltaTime) override;
    bool isColliding(Player other);
};