#pragma once
#include "gameNode.h"

#include "idle.h"
#include "walk.h"
#include "jump.h"

#pragma warning(disable:4996)

class player : public gameNode
{
private:
	state* _state;

	idle* _idle;
	walk* _walk;
	jump* _jump;

public:


	virtual HRESULT init();			//�ʱ�ȭ �Լ�
	virtual void release();			//�޸� ���� �Խ�
	virtual void update();			//�����ϴ� �Լ�
	virtual void render();			//�׸��� �Լ�

	void setValue(state* state);

	state* getState() { return _state; }

	void setIdle() { setValue(_idle); }
	void setWalk() { setValue(_walk); }
	void setJump() { setValue(_jump); }
};

