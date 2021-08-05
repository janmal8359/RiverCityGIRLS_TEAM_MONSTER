#pragma once
#include "gameNode.h"
#include "bossStage1.h"
#include "bossStage2.h"
#include "firstStage.h"
#include "secondStage.h"
#include "thirdStage.h"

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

