#pragma once
#include "gameNode.h"
#include "pixelCollisionClass.h"

//������(���� ��)
class bossStage2 : public gameNode
{
private:
	//������Ʈ ��
	image _object[6];
	RECT _rc;
	float _X, _Y;
	float _radius;
	float _angle;
	float _speed;
	float _gravity;
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

