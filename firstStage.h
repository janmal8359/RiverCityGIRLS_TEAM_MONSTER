#pragma once
#include "gameNode.h"
#include "camera.h"
#include "player.h"
#include "enemy.h"
#include "boss.h"
#include "state.h"
//#include "pixelCollisionClass.h"

#include "zOrder.h"

class pixelCollisionClass;

//����
class firstStage : public gameNode
{
private:
	bool _isCheck;
	bool _isNextCount;

	typedef vector<gameNode*>				arrRender;
	typedef vector<gameNode*>::iterator		iterRender;


	arrRender _vRender;
	iterRender _viRender;
	//image* _first;
	
	camera* _camera;
	player* _player;
	enemy* _enemy;
	boss* _boss;
	zOrder* _zO;

	pixelCollisionClass* _pixel;

	//�ȼ� Ž����
	//float _probeLX, _probeTY, _probeRX, _probeBY;

public:
	firstStage();
	~firstStage();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	//void pixelCollision();

	void setPlayer(player* player) { _player = player; }

	void setpixelCollisionClassMemoryAddressLink(pixelCollisionClass* pixel) { _pixel = pixel; }

	void selectionSort();

	void swap(gameNode** a, gameNode** b);
};

