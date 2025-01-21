#include "ChaserEnemy.h"

ChaserEnemy::ChaserEnemy(Vector2i _POS, float _SPEED, Vector2f _BEHAVIOUR)
	: Enemy(_POS, _SPEED, _BEHAVIOUR) {
	rect.setFillColor(Color::Magenta); rect.setSize({ 15,15 }); rect.setPosition(_POS.x, _POS.y);
}

void ChaserEnemy::chasePlayer(Player* player) {
		playerX = player->getPos().x; playerY = player->getPos().y;

        Vector2f newBehaviour(1, 0);

        if (getPos().x < playerX)
            newBehaviour.x = 1;
            //rect.move(getSpeed(), 0);
        else if (getPos().x > playerX)
            newBehaviour.x = -1;
            //rect.move(-getSpeed(), 0);

        if (getPos().y < playerY)
            newBehaviour.y = 1;
            //rect.move(0, getSpeed());

        else if (getPos().y > playerY)
            newBehaviour.y = -1;
            //rect.move(0, -getSpeed());
        setBehaviour(newBehaviour);
}

void ChaserEnemy::update(float deltaTime) {
	cout << "ChaserEnemy";
}