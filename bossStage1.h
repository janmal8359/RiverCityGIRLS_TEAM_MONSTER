#pragma once
#include "gameNode.h"
//보스방(등장 전)
class bossStage1 : public gameNode
{
private:
	//오브젝트 용
	float _X, _Y;

public:
	bossStage1();
	~bossStage1();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
};

