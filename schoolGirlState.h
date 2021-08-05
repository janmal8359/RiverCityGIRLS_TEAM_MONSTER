#pragma once
#include "gameNode.h"
class schoolGirlState : public gameNode
{
public:
	schoolGirlState();
	~schoolGirlState();

	virtual HRESULT init() = 0;				//초기화
	virtual void release() = 0;				//초기화
	virtual void update() = 0;				//초기화
};


