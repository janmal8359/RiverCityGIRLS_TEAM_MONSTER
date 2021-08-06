#pragma once
#include "gameNode.h"
//±³½Ç
class firstStage : public gameNode
{
private:
	bool _isCheck;
	bool _isNextCount;

public:
	firstStage();
	~firstStage();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
};

