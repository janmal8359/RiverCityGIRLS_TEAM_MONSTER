#pragma once
#include "gameNode.h"
#include "player.h"
#include "enemy.h"
#include "boss.h"
#include "state.h"
//#include "pixelCollisionClass.h"

class pixelCollisionClass;

//±³½Ç
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

	//ÇÈ¼¿ Å½»ö±â
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

