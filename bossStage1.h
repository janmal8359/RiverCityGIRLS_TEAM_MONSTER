#pragma once
#include "gameNode.h"
//보스방(등장 전)
class bossStage1 : public gameNode
{
private:
	//오브젝트
	float _X, _Y;

	//충돌용
	RECT _rc;
	float _x, _y;
	bool _isCheck;
	bool _isNextCount;
	bool _isStop;

public:
	bossStage1();
	~bossStage1();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
};

