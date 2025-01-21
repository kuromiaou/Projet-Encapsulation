#pragma once
#include "Player.h"
#include "Enemy.h"
#include "PatrollingEnemy.h"
#include "ChaserEnemy.h"
#include "Potion.h"
#include "Key.h"

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
};

