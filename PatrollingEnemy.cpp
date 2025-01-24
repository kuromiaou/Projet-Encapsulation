#include "PatrollingEnemy.h"



PatrollingEnemy::PatrollingEnemy(Vector2i _POS, float _SPEED, Vector2f _BEHAVIOUR) 
	: Enemy(_POS, _SPEED, _BEHAVIOUR) { rect.setFillColor(Color::Green); rect.setSize({ 15,15 }); rect.setPosition(_POS.x,_POS.y);}

void PatrollingEnemy::update(float deltaTime) {}