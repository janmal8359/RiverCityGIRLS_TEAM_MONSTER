#pragma once
#include "state.h"

class atk : public state
{
private:

	int _attackIdx;     //ÄÞº¸
	int _timer;



public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	virtual void stateChange();
	virtual void ani();
};

