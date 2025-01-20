#include "ChaserEnemy.h"

ChaserEnemy::ChaserEnemy(Vector2i _POS, float _SPEED, Vector2f _BEHAVIOUR)
	: Enemy(_POS, _SPEED, _BEHAVIOUR) {
	rect.setFillColor(Color::Magenta); rect.setSize({ 15,15 }); rect.setPosition(60, 60);
}

void ChaserEnemy::chasePlayer(Player& player) {
		playerX = player.getPos().x; playerY = player.getPos().y;

		if (getPos().x < playerX) setBehaviour(Vector2f{ 1,0 });
		else setBehaviour(Vector2f{ -1,0 });

		if (getPos().y < playerY) setBehaviour(Vector2f{ 0,1 });
		else setBehaviour(Vector2f{ 0,-1 });
	
}

void ChaserEnemy::update(float deltaTime) {
	cout << "ChaserEnemy";
}