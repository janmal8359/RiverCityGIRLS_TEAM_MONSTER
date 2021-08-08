#pragma once
#include "gameNode.h"
#include "player.h"
#include "enemy.h"
#include "boss.h"
#include "state.h"


//����
class firstStage : public gameNode
{
private:
	bool _isCheck;
	bool _isNextCount;

	image* _first;
	
	player* _player;
	enemy* _enemy;
	boss* _boss;

	//�ȼ� Ž����
	float _probeLX, _probeTY, _probeRX, _probeBY;

public:
	firstStage();
	~firstStage();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	void pixelCollision();
};

