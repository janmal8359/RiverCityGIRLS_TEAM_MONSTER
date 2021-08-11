#pragma once
#include "gameNode.h"
#include "camera.h"
#include "player.h"
#include "enemy.h"
#include "boss.h"
#include "state.h"

#include "zOrder.h"

class pixelCollisionClass;

//����
class firstStage : public gameNode
{
private:
<<<<<<< HEAD
	typedef vector<gameNode*>				arrRender;
	typedef vector<gameNode*>::iterator		iterRender;


	arrRender _vRender;
	iterRender _viRender;
=======
	bool _isCheck;
	bool _isNextCount;

>>>>>>> parent of 682375e (zorder 일단구현 객체화 확인)
	//image* _first;
	
	camera* _camera;
	player* _player;
	enemy* _enemy;
	boss* _boss;
	zOrder* _zO;

	pixelCollisionClass* _pixel;

	bool _isCheck;

public:
	firstStage();
	~firstStage();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	void setPlayer(player* player) { _player = player; }

	void setpixelCollisionClassMemoryAddressLink(pixelCollisionClass* pixel) { _pixel = pixel; }
};

