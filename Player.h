#pragma once
#include "Entity.h"
class Player :
    public Entity
{
private:
    Vector2i pos;
    float speed;
public:
    RectangleShape rect;   
    Texture texture;
    Sprite sprite;
    void update(float d) override;
    void draw(RenderWindow& window) override;
    Player(Vector2i _POS, float _SPEED);
    void userInput();
    void setPos(Vector2i pos);
    void setSpeed(float speed);
    float getSpeed();
};