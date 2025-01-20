#pragma once
#include "Enemy.h"
#include "Player.h"

class ChaserEnemy :
    public Enemy
{
private:
    int playerX, playerY;
public:
    ;
    void update(float deltaTime) override;
    ChaserEnemy(Vector2i _POS, float _SPEED, Vector2f _BEHAVIOUR);
    void chasePlayer(Player& player);
};