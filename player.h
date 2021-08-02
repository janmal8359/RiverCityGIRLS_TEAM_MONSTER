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


	virtual HRESULT init();			//초기화 함수
	virtual void release();			//메모리 해제 함슈
	virtual void update();			//연산하는 함수
	virtual void render();			//그리기 함수

	void setValue(state* state);

	state* getState() { return _state; }

	void setIdle() { setValue(_idle); }
	void setWalk() { setValue(_walk); }
	void setJump() { setValue(_jump); }
};

