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


	//�������� Ű�޴� �Լ�
	virtual void move();
	virtual void aniChange();
};

