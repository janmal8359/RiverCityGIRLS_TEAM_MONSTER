#pragma once
#include "gameNode.h"
//������(���� ��)
class bossStage1 : public gameNode
{
private:
	//������Ʈ ��
	float _X, _Y;

public:
	bossStage1();
	~bossStage1();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
};

