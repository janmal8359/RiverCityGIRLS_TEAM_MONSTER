#pragma once
#include "state.h"


class idle : public state
{
private:



public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();


	//움직여서 키받는 함수
	virtual void move();
	virtual void aniChange();
};

