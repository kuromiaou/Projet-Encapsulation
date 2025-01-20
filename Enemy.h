#pragma once
#include "Entity.h"
#include "Player.h"
class Enemy :
    public Entity
{
private:
    Vector2i pos;
    Vector2f behaviour;
    float speed;
    int tiles=0;
public:
    RectangleShape rect;
    Enemy(Vector2i _POS, float _SPEED, Vector2f _BEHAVIOUR);
    void update(float deltaTime) override;
    void draw(RenderWindow& window) override;
    void setPos(Vector2i pos);
    void setSpeed(float speed);
    float getSpeed();
    Vector2i getPos();
    void setBehaviour(Vector2f v);
    void reverseBehaviour();
    void randomizeBehviour();
    Vector2f getBehaviour();
    void setTiles(int i);
    int getTiles();
    void move();

    bool isColliding(Player other);
    
};

