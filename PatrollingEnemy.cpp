#include "PatrollingEnemy.h"



PatrollingEnemy::PatrollingEnemy(Vector2i _POS, float _SPEED, Vector2f _BEHAVIOUR) 
	: Enemy(_POS, _SPEED, _BEHAVIOUR) { rect.setFillColor(Color::Green); rect.setSize({ 15,15 }); rect.setPosition(60, 60);}

void PatrollingEnemy::update(float deltaTime) {
	if (clocky.getElapsedTime().asSeconds() >= 2) {
		Enemy::reverseBehaviour(); // à enlever
		clocky.restart();
	}
	if (uhu == 2) Enemy::randomizeBehviour();
		
	}