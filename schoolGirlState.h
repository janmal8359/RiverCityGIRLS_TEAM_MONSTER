#pragma once
#include "gameNode.h"
class schoolGirlState : public gameNode
{
public:
	schoolGirlState();
	~schoolGirlState();

	virtual HRESULT init() = 0;				//�ʱ�ȭ
	virtual void release() = 0;				//�ʱ�ȭ
	virtual void update() = 0;				//�ʱ�ȭ
};


