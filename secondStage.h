#pragma once
#include "gameNode.h"
//������
class secondStage : public gameNode
{
private:
	bool _isCheck;

public:
	secondStage();
	~secondStage();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
};

