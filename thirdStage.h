#pragma once
#include "gameNode.h"
//������
class thirdStage : public gameNode
{
private:
	bool _isCheck;


public:
	thirdStage();
	~thirdStage();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
};

