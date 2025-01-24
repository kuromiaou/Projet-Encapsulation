#include "Manager.h"

Player* Manager::createPlayer(Vector2i pos) {
	Player* player = new Player(pos, 3);
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
	}
}

Wall* Manager::createWall(Vector2i pos) {
	Wall* obj = new Wall(pos);
	allWalls.push_back(obj);
	allEntities.push_back(obj);
	cout << "Wall created successfully.";	
	return obj;
}
Door* Manager::createDoor(Vector2i pos) {
	Door* obj = new Door(pos);
	allDoors.push_back(obj);
	allEntities.push_back(obj);
	cout << "Door created successfully.";
	return obj;
}
Floor* Manager::createFloor(Vector2i pos) {
	Floor* obj = new Floor(pos);
	allFloors.push_back(obj);
	allEntities.push_back(obj);
	cout << "Floor created successfully.";
	return obj;
}
vector<Entity*> Manager::getallEntities() {	return allEntities;}

vector<Wall*> Manager::getallWalls() { return allWalls; }
vector<Floor*> Manager::getallFloors() { return allFloors; };
vector<Door*> Manager::getallDoors() { return allDoors; };  
vector<PatrollingEnemy*> Manager::getallPatEnemies() { return allPatEnemies; };  
vector<ChaserEnemy*> Manager::getallChaEnemies() { return allChaEnemies; };  
vector<Key*> Manager::getallKeys() { return allKeys; };  
vector<Potion*> Manager::getallPotions() { return allPotions; };  

void Manager::deletePatEnemy(PatrollingEnemy* obj){
	auto it = find(allPatEnemies.begin(), allPatEnemies.end(), obj);
	cout << "pot deleted\n";
	if (it != allPatEnemies.end()) {
		delete* it;
		allPatEnemies.erase(it);
	}
}
void Manager::deleteChaEnemy(ChaserEnemy* obj){
	auto it = find(allChaEnemies.begin(), allChaEnemies.end(), obj);
	cout << "pot deleted\n";
	if (it != allChaEnemies.end()) {
		delete* it;
		allChaEnemies.erase(it);
	}
}
void Manager::deleteWall(Wall* obj){
	auto it = find(allWalls.begin(), allWalls.end(), obj);
	cout << "pot deleted\n";
	if (it != allWalls.end()) {
		delete* it;
		allWalls.erase(it);
	}
}
void Manager::deleteFloor(Floor* obj){
	auto it = find(allFloors.begin(), allFloors.end(), obj);
	cout << "pot deleted\n";
	if (it != allFloors.end()) {
		delete* it;
		allFloors.erase(it);
	}
}
void Manager::deleteDoor(Door* obj){
	auto it = find(allDoors.begin(), allDoors.end(), obj);
	cout << "pot deleted\n";
	if (it != allDoors.end()) {
		delete* it;
		allDoors.erase(it);
	}
}