#include "Manager.h"

Player* Manager::createPlayer(Vector2i pos) {
	Player* player = new Player(pos, 10.f);
	allPlayers.push_back(player);
	allEntities.push_back(player);
	return player;
}
Enemy* Manager::createEnemy(Vector2i pos) {
	Enemy* enemy = new Enemy(pos, 10, { 0,0 });
	allEnemies.push_back(enemy);
	allEntities.push_back(enemy);
	return enemy;
}
PatrollingEnemy* Manager::createPatrollingEnemy(Vector2i pos) {
	PatrollingEnemy* enemy = new PatrollingEnemy(pos, 1, { 1,0 });
	allPatEnemies.push_back(enemy);
	allEntities.push_back(enemy);
	cout << "PatrollingEnemy created successfully.";
	return enemy;
}
ChaserEnemy* Manager::createChaserEnemy(Vector2i pos) {
	ChaserEnemy* enemy = new ChaserEnemy(pos, 1, { 0,1 });
	allChaEnemies.push_back(enemy);
	allEntities.push_back(enemy);
	cout << "ChaserEnemy created successfully.";
	return enemy;
}
Potion* Manager::createPotion(Vector2i pos, Texture& _texture) {
	Potion* obj = new Potion(pos, _texture);
	allPotions.push_back(obj);
	allEntities.push_back(obj);
	cout << "Potion created successfully.";
	return obj;
	
}
Key* Manager::createKey(Vector2i pos, Texture& _texture) {
	Key* obj = new Key(pos, _texture);
	allKeys.push_back(obj);
	allEntities.push_back(obj);
	cout << "Key created successfully.";
	return obj;
	}

void Manager::deletePotion(Potion* potion) {
	auto it = find(allPotions.begin(), allPotions.end(), potion);
	cout << "pot deleted\n";
	if (it != allPotions.end()) {
		delete* it;
		allPotions.erase(it);
	}
}
void Manager::deleteKey(Key* key) {
	auto it = find(allKeys.begin(), allKeys.end(), key);
	cout << "pot deleted\n";
	if (it != allKeys.end()) {
		delete* it;
		allKeys.erase(it);
		allEntities.erase(it);
		allObjects.erase(it);
	}
}