#pragma once
#include "Player.h"
#include "Enemy.h"
#include "PatrollingEnemy.h"
#include "ChaserEnemy.h"
#include "Potion.h"
#include "Key.h"
#include "Wall.h"
#include "Floor.h"
#include "Door.h"

class Manager
{
private:
	vector<Entity*> allPlayers;
	vector<Entity*> allEnemies;
	vector<Entity*> allPatEnemies;
	vector<Entity*> allChaEnemies;
	vector<Entity*> allObjects;
	vector<Entity*> allKeys;
	vector<Entity*> allPotions;
	vector<Entity*> allEntities;
	vector<Entity*> allWalls;
	vector<Entity*> allFloors;
	vector<Entity*> allDoors;
public:
	Player* player;
	static Manager* getInstance() {
		static Manager* instance = new Manager();
		return instance;
	}
	~Manager() {}
	Player* createPlayer(Vector2i pos);
	Enemy* createEnemy(Vector2i pos);
	PatrollingEnemy* createPatrollingEnemy(Vector2i pos);
	ChaserEnemy* createChaserEnemy(Vector2i pos);
	Potion* createPotion(Vector2i,Texture&);
	Key* createKey(Vector2i,Texture&);
	//void deleteObject(Objects* other);
	void deletePotion(Potion* other);
	void deleteKey(Key* other);
	//void deleteEntity();
	Wall* createWall(Vector2i);
	Door* createDoor(Vector2i);
	Floor* createFloor(Vector2i);

	vector<Entity*> getallWalls();
	vector<Entity*> getallFloors();
	vector<Entity*> getallDoors();
};

