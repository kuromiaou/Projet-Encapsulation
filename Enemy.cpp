#include "Enemy.h"

Enemy::Enemy(Vector2i _POS, float _SPEED, Vector2f _BEHAVIOUR) : pos(_POS), speed(_SPEED), behaviour(_BEHAVIOUR) {}

void Enemy::draw(RenderWindow& window) { window.draw(rect); }
void Enemy::update(float r) {}
void Enemy::setPos(Vector2i posi) { pos = posi; }
void Enemy::setSpeed(float speedy) { speed = speedy; };
float Enemy::getSpeed() { return speed; }
void Enemy::setBehaviour(Vector2i f) { behaviour = f; }
void Enemy::reverseBehaviour() { behaviour = -behaviour; }
void Enemy::randomizeBehviour() { srand(time(0)); int x, y; switch (rand() % 1) { case 0: x = -1; break; case 1: x = 1; break; }; srand(time(0) + 13); switch (rand() % 1) { case 0: y = -1; break; case 1: y = 1; break; }; behaviour = Vector2i{ x , y }; }
Vector2f Enemy::getBehaviour() { return behaviour; }