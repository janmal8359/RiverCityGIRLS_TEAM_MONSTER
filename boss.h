#pragma once
#include "gameNode.h"
#include "bossState.h"

class bossState;

enum class STATE
{
	IDLE,
	WALK,
	ATTACK,
	JUMP,
	SIT,
	GROGGY,
	LOSE
};

class boss : public gameNode
{
private:
	bossState* _state;
	STATE* _bState;

	// shadow
	image* _bShadowImg;
	RECT _bShadowRc;

	// boss
	image* _bossImg;
	RECT _bossRc;

	// position
	float _sx, _sy;		// shadowImgPos
	float _bx, _by;		// bossImgPos

	// velocity
	float _speed;

	// direction
	DIRECTION _direction;

public:
	boss() {}
	~boss() {}

	HRESULT init();
	void release();
	void update();
	void render();

	void setState(bossState* state) { _state = state; }
	void stateRender(animation* anim);

	void bossAnim();


	// get
	float getBossShadowX() { return _sx; }
	float getBossShadowY() { return _sy; }
	float getBossX() { return _bx; }
	float getBossY() { return _by; }
	float getBossRectX() { return _bossRc.left; }
	float getBossRectY() { return _bossRc.top; }
	DIRECTION getBossDirection() { return _direction; }


	// set
	void setBossShadowX(float x) { _sx = x; }
	void setBossShadowY(float y) { _sy = y; }
	void setBossX(float x) { _bx = x; }
	void setBossY(float y) { _by = y; }
	void setBossDirection(DIRECTION dir) { _direction = dir; }

};

