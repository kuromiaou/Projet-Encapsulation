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
	vector<Player*> allPlayers;
	vector<Enemy*> allEnemies;
	vector<PatrollingEnemy*> allPatEnemies;
	vector<ChaserEnemy*> allChaEnemies;
	vector<Objects*> allObjects;
	vector<Key*> allKeys;
	vector<Potion*> allPotions;
	vector<Entity*> allEntities;
	vector<Wall*> allWalls;
	vector<Floor*> allFloors;
	vector<Door*> allDoors;                  // utiliser vector<Entity*> et pas vector<Door*> me bloque juste car je n'ai pas accès aux attributs et méthodes de Door dans le reste du manager ou dans le main.
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

	vector<Entity*> getallEntities();
	vector<Wall*> getallWalls();
	vector<Floor*> getallFloors();
	vector<Door*> getallDoors();
	vector<PatrollingEnemy*> getallPatEnemies();
	vector<ChaserEnemy*> getallChaEnemies();
	vector<Key*> getallKeys();
	vector<Potion*> getallPotions();

	void deletePatEnemy(PatrollingEnemy*);
	void deleteChaEnemy(ChaserEnemy*);
	void deleteWall(Wall*);
	void deleteFloor(Floor*);
	void deleteDoor(Door*);
};

