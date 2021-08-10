#pragma once
#include "gameNode.h"
#include "player.h"
#include "enemy.h"
#include "boss.h"
#include "state.h"
//#include "pixelCollisionClass.h"

class pixelCollisionClass;

//����
class firstStage : public gameNode
{
private:
	bool _isCheck;
	bool _isNextCount;

	//image* _first;
	
	player* _player;
	enemy* _enemy;
	boss* _boss;

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
};

