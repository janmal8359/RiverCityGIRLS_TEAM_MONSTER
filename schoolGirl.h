#pragma once
#include "gameNode.h"

enum class schoolGirl_Statement		//스쿨걸스테이트먼트 클래스
{
	IDLE,
	WALK,
	RUN,
	JUMP,
	ATTACK,
};

class schoolGirl : public gameNode
{
private:

	schoolGirl_Statement _SGStatement;

	
	RECT _rc;
	image* _img;
public:
	
	schoolGirl();
	~schoolGirl();
	
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
};

