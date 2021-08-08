#pragma once
#include "gameNode.h"
#include "firstStage.h"
#include "secondStage.h"
#include "thirdStage.h"
#include "bossStage1.h"
#include "bossStage2.h"
#include "player.h"

class pixelCollision : public gameNode
{
private:
	image* _firstStage;
	image* _secondStage;
	image* _thirdStage;
	image* _bossStage;

	player* _player;

	//ÇÈ¼¿ Å½»ö±â
	float _probeLX, _probeTY, _probeRX, _probeBY;

public:
	pixelCollision();
	~pixelCollision();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	void Colloision();
};