#pragma once
#include "state.h"
class stomp : public state
{
private:

public:


	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	virtual void stateChange();
	virtual void ani();

	void callBk();
};


