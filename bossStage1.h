#pragma once
#include "gameNode.h"
//������(���� ��)
class bossStage1 : public gameNode
{
private:
	//������Ʈ
	float _X, _Y;

	//�浹��
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

