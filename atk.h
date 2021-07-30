#pragma once
#include "state.h"

class atk : public state
{
private:



public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
};

