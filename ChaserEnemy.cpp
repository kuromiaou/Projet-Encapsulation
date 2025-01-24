#include "ChaserEnemy.h"

ChaserEnemy::ChaserEnemy(Vector2i _POS, float _SPEED, Vector2f _BEHAVIOUR)
	: Enemy(_POS, _SPEED, _BEHAVIOUR) {
	rect.setFillColor(Color::Magenta); rect.setSize({ 15,15 }); rect.setPosition(_POS.x, _POS.y);
}
//void ChaserEnemy::chasePlayer(Player& player) {
//		playerX = player.getPos().x; playerY = player.getPos().y;
//
//
//        if (getPos().x < playerX)
//            newBehaviour.x = 1;
//        else if (getPos().x > playerX)
//            newBehaviour.x = -1;
//
//        if (getPos().y < playerY)
//            newBehaviour.y = 1;
//
//        else if (getPos().y > playerY)
//            newBehaviour.y = -1;
//        cout << newBehaviour.x << endl;
//        setBehaviour(newBehaviour);
//}                                                // FIRST VERSION IS BAD
void ChaserEnemy::chasePlayer(Player& player) {
    float playerX = player.getPos().x;
    float playerY = player.getPos().y;
    float currentX = getPos().x;
    float currentY = getPos().y;

    float deltaX = playerX - currentX;
    float deltaY = playerY - currentY;

    float distance = sqrt(deltaX * deltaX + deltaY * deltaY);

    if (distance != 0) {
        deltaX /= distance;
        deltaY /= distance;
    }

    float speed = 2.25f; 

    newBehaviour.x = deltaX * speed;
    newBehaviour.y = deltaY * speed;
    //cout << "zuuzuzuz" << currentX << " " << currentY << "ezfzefzef\n";
    setBehaviour(newBehaviour);
}

void ChaserEnemy::update(float deltaTime) {
	cout << "ChaserEnemy";
}