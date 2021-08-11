#pragma once
#include <vector>
#include <map>
#include <algorithm>

#include "gameNode.h"
#include "player.h"
#include "enemy.h"
#include "boss.h"


class zOrder : public gameNode
{

private:
	map<float, int>	_mobj;
	map<float, int>::iterator _miobj;


	//multimap<float, int>			_mobj;
	//multimap<float, int>::iterator  _miobj;

	int mapIdx;

	player* _player;

	enemy* _enemy;

	boss* _boss;



public:
	zOrder();
	~zOrder();

	HRESULT init();
	void release();
	void update();
	void render();


	void ZOrder();
	void draw();


	void setPlayer(player* player) { _player = player; }
	void setBoss(boss* boss) { _boss = boss; }
	void setEnemy(enemy* enemy) { _enemy = enemy; }
};

