#include "Player.h"
#include "Level.h"

Player::Player(Vector2i _POS, float _SPEED) : pos(_POS), speed(_SPEED) { setPos(_POS); rect.setFillColor(Color::Red);
rect.setSize({ 10,10 }); rect.setPosition(_POS.x,_POS.y); };
void Player::update(float d) {};

void Player::draw(RenderWindow& window) {
	window.draw(rect);
	//cout << rect.getPosition().x << " " << rect.getPosition().y<<endl;
}
void Player::userInput() {
	if (Keyboard::isKeyPressed(Keyboard::delocalize(Keyboard::Z))) { rect.move(0, -1 * speed); cout << "Up!"; if (rect.getPosition().y <= 0) rect.setPosition(rect.getPosition().x, 0);
	}
	if (Keyboard::isKeyPressed(Keyboard::delocalize(Keyboard::Q))) { rect.move(-1 * speed, 0); cout << "Left!"; if (rect.getPosition().x <= 0) rect.setPosition(0, rect.getPosition().y);
	}
	if (Keyboard::isKeyPressed(Keyboard::delocalize(Keyboard::S))) { rect.move(0, 1 * speed); cout << "Down!"; if (rect.getPosition().y >= 700 - rect.getGlobalBounds().width) rect.setPosition(rect.getPosition().x, 700 - rect.getGlobalBounds().width);
	}
	if (Keyboard::isKeyPressed(Keyboard::delocalize(Keyboard::D))) { rect.move(1 * speed, 0); cout << "Right!"; if (rect.getPosition().x >= 1280 - rect.getGlobalBounds().height) rect.setPosition(1280 - rect.getGlobalBounds().height, rect.getPosition().y);
	}
	if (Keyboard::isKeyPressed(Keyboard::delocalize(Keyboard::Escape))) { window.close(); }
	pos = { (int)rect.getPosition().x, (int)rect.getPosition().y };
}
void Player::setPos(Vector2i pos) { sprite.setPosition(pos.x, pos.y); }
void Player::setSpeed(float s) { speed = s; }
void Player::increaseSpeed(int i) { speed += i; }
void Player::decreaseSpeed(int i) { speed -= i; }
float Player::getSpeed() { return speed; }
Vector2i Player::getPos() { return Vector2i{ rect.getPosition()/*having pos insteand of Vector2i... doesn't change anything here because of l.20*/}; }