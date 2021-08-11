#pragma once
#include <vector>
#include <map>
#include <algorithm>

#include "gameNode.h"
#include "player.h"
#include "enemy.h"
#include "boss.h"
#include "camera.h"


class zOrder : public gameNode
{

private:

	vector<gameNode*>				_vRender;
	vector<gameNode*>::iterator		_viRender;


	player* _player;

	enemy* _enemy;

	boss* _boss;

	camera* _camera;









public:
	zOrder();
	~zOrder();

	HRESULT init();
	void release();
	void update();
	void render();

	void selectionSort();
	void swap(gameNode** a, gameNode** b);




	void setPlayer(player* player)	 { _player = player; }
	void setBoss(boss* boss)		 { _boss = boss; }
	void setEnemy(enemy* enemy)		 { _enemy = enemy; }
	void setCamera(camera* camera)	 { _camera = camera; }
	
};

