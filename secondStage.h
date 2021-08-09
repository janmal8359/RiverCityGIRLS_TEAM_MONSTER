#pragma once
#include "gameNode.h"
#include "pixelCollision.h"

//������
class secondStage : public gameNode
{
private:
	bool _isCheck;
	bool _isNextCount;

public:
	secondStage();
	~secondStage();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
};

