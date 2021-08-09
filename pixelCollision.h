#pragma once
#include "gameNode.h"
#include "firstStage.h"
#include "secondStage.h"
#include "thirdStage.h"
#include "bossStage1.h"
#include "bossStage2.h"
#include "player.h"

enum STAGETYPE
{
	FISTST,
	SECOND,
	THIRD,
	BOSS
};


class pixelCollision : public gameNode
{
private:
	//image* _firstStage;
	//image* _secondStage;
	//image* _thirdStage;
	//image* _bossStage;

	image* _stage;

	STAGETYPE _stageType;

	player* _player;

	RECT _rc;
	float _x, _y;

	//ÇÈ¼¿ Å½»ö±â
	float _probeLX, _probeTY, _probeRX, _probeBY;

public:
	pixelCollision();
	~pixelCollision();

	virtual HRESULT init();
	virtual HRESULT init(float x, float y, int type);
	virtual void release();
	virtual void update();
	virtual void render();

	void Colloision();

	inline RECT getRect() { return _rc; }
	int getEnemyType() { return _stageType; }
};