#pragma once
#include "gameNode.h"
//∆Ì¿«¡°
class thirdStage : public gameNode
{
private:
	bool _isCheck;
	bool _isNextCount;

public:
	thirdStage();
	~thirdStage();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
};

