#pragma once
#include "Entity.h"
class Enemy :
    public Entity
{
private:
    Vector2i pos;
    Vector2f behaviour;
    float speed;
public:
    RectangleShape rect;
    Enemy(Vector2i _POS, float _SPEED, Vector2f _BEHAVIOUR);
    void update(float deltaTime) override;
    void draw(RenderWindow& window) override;
    void setPos(Vector2i pos);
    void setSpeed(float speed);
    float getSpeed();
    void setBehaviour(Vector2f v);
    void reverseBehaviour();
    void randomizeBehviour();
    Vector2f getBehaviour();
    
};

