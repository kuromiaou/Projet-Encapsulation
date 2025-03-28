#include "Enemy.h"

Enemy::Enemy(Vector2i _POS, float _SPEED, Vector2f _BEHAVIOUR) : pos(_POS), speed(_SPEED), behaviour(_BEHAVIOUR) {}

void Enemy::draw(RenderWindow& window) { window.draw(rect); }
void Enemy::update(float r) {}
void Enemy::setPos(Vector2i posi) { pos = posi; }
void Enemy::setSpeed(float speedy) { speed = speedy; };
float Enemy::getSpeed() { return speed; }
Vector2i Enemy::getPos() { return Vector2i{ rect.getPosition() }; }
void Enemy::setBehaviour(Vector2f _NEWBEHAVIOUR) { behaviour = _NEWBEHAVIOUR; }
void Enemy::reverseBehaviour() { behaviour = -behaviour; }
void Enemy::randomizeBehviour()  {srand(time(0));// not used 
float x, y;// not used // not used 
x = (rand() % 2 == 0) ? -1 : 1;// not used 
y = (rand() % 2 == 0) ? -1 : 1;// not used 
behaviour = Vector2f{ x, y };// not used 
} // not used 
Vector2f Enemy::getBehaviour() { return behaviour; }
void Enemy::setSpeed(int i) { speed = i; }
void Enemy::increaseSpeed(int i) { speed += i; }
void Enemy::decreaseSpeed(int i) { speed -= i; }
void Enemy::move() { rect.move(getBehaviour() * getSpeed()); tiles++;}
void Enemy::setTiles(int i) { tiles = i; }
int Enemy::getTiles() { return tiles; }
bool Enemy::isColliding(Player other) {
        if (rect.getGlobalBounds().intersects(other.rect.getGlobalBounds())) return true;
        else return false;
}