#pragma once
#include "gameNode.h"
//����
class firstStage : public gameNode
{
private:
	bool _isCheck;

public:
	firstStage();
	~firstStage();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
};

