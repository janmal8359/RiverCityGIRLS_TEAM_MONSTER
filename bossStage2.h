#pragma once
#include "gameNode.h"
//������(���� ��)
class bossStage2 : public gameNode
{
private:
	//������Ʈ ��
	RECT _rc;
	float _X, _Y;
	float _radius;
	float _angle;
	int _alphaValue;

	bool _isBreak;

public:
	bossStage2();
	~bossStage2();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
};

