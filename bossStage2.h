#pragma once
#include "gameNode.h"
//보스방(등장 후)
class bossStage2 : public gameNode
{
private:
	//오브젝트 용
	image _object;
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

