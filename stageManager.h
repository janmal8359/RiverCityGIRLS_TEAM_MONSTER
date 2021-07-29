#pragma once
#include "gameNode.h"

class stageManager : public gameNode
{
private:

public:
	stageManager();
	~stageManager();

	virtual HRESULT init();			
	virtual void release();			
	virtual void update();			
	virtual void render();			

};

