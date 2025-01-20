#include "Manager.h"

Player* Manager::createPlayer(Vector2i pos) {
	Player* player = new Player(pos, 10.f);
	allPlayers.push_back(player);
	return player;
}
Enemy* Manager::createEnemy(Vector2i pos) {
	Enemy* enemy = new Enemy(pos, 10, { 0,0 });
	allEnemies.push_back(enemy);
	return enemy;
}
PatrollingEnemy* Manager::createPatrollingEnemy(Vector2i pos) {
	PatrollingEnemy* enemy = new PatrollingEnemy(pos, 1, { 1,0 });
	allPatEnemies.push_back(enemy);
	return enemy;
}