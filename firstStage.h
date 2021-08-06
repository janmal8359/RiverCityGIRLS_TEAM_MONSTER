#pragma once
#include "gameNode.h"
#include "player.h"

//±³½Ç
class firstStage : public gameNode
{
private:
	bool _isCheck;
	bool _isNextCount;

	image* _first;

	player* _pl;
	
	//ÇÈ¼¿ Å½»ö±â
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

