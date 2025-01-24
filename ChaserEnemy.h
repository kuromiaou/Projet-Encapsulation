#pragma once
#include "Enemy.h"
#include "Player.h"

class ChaserEnemy :
    public Enemy
{
private:
public:
    Vector2f newBehaviour = { 0,0 };
    void update(float deltaTime) override;
    ChaserEnemy(Vector2i _POS, float _SPEED, Vector2f _BEHAVIOUR);
    void chasePlayer(Player& player);    
};