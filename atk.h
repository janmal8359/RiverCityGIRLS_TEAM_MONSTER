#pragma once
#include "state.h"

class atk : public state
{
private:

	int _attackIdx;     //�޺�


public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	virtual void stateChange();
	virtual void ani();

	void callBk();	//�ݹ�

	//virtual void hitCheck();

};

