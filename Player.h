#pragma once
#include "Entity.h"

class Player :
    public Entity
{
private:
    Vector2i pos;
    float speed;
    
public:
    bool moveDATA = false;
    enum facing {
        _UP = 0,
        _LEFT = 1,
        _DOWN = 2,
        _RIGHT = 3,
    };
    facing facing;
    int state = 0;
    bool canLvlUp = false;
    RectangleShape rect;
    Texture texture;
    Sprite sprite;
    void update(float d) override;
    void draw(RenderWindow& window) override;
    Player(Vector2i _POS, float _SPEED);
    void userInput();
    void setPos(Vector2i pos);
    void increaseSpeed(int i = 1);
    void decreaseSpeed(int i = 1);
    void setSpeed(float speed);
    float getSpeed();
    Vector2i getPos();
};