#pragma once
#include "gameNode.h"
//±³¹«½Ç
class secondStage : public gameNode
{
private:


public:
	secondStage();
	~secondStage();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
};

