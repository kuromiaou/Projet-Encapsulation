#pragma once
#include "Enemy.h"
class PatrollingEnemy :
    public Enemy
{
private:
    Clock clocky;
    int uhu;
public:
    void update(float deltaTime) override;
    PatrollingEnemy(Vector2i _POS, float _SPEED, Vector2f _BEHAVIOUR);
};

