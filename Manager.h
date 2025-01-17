#pragma once
#include "Player.h"
#include "Enemy.h"
#include "PatrollingEnemy.h"
#include "ChaserEnemy.h"

class Manager
{
private:
	vector<Entity*> allPlayers;
	vector<Entity*> allEnemies;
	vector<Entity*> allPatEnemies;
	vector<Entity*> allChaEnemies;
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
};

