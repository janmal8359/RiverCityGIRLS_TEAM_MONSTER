#pragma once
#include "gameNode.h"
#include "bossState.h"

class bossState;
class player;

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
	// class
	bossState* _state;
	STATE* _bState;

	player* _player;

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
	float _jumpPower;
	float _gravity;

	// direction
	int _direction;

	// time
	float _time;

	// bool
	bool _isIdle;
	bool _isMove;
	bool _isAttack;
	bool _isJump;
	bool _isDrop;
	bool _isFloat;
	bool _isDash;

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

	void move();
	void jump();


	// get
	float getBossShadowX() { return _sx; }
	float getBossShadowY() { return _sy; }
	float getBossX() { return _bx; }
	float getBossY() { return _by; }
	float getBossRectX() { return _bossRc.left; }
	float getBossRectY() { return _bossRc.top; }

	int getBossDirection() { return _direction; }

	player* getPlayer() { return _player; }
	bossState* getState() { return _state; }

	bool getMove() { return _isMove; }
	bool getIsAttack() { return _isAttack; }
	bool getIsJump() { return _isJump; }
	bool getIsDrop() { return _isDrop; }
	bool getFloat() { return _isFloat; }
	bool getDash() { return _isDash; }
	bool getIdle() { return _isIdle; }

	float getTime() { return _time; }
	float getJumpPower() { return _jumpPower; }


	// set
	void setBossShadowX(float x) { _sx = x; }
	void setBossShadowY(float y) { _sy = y; }
	void setBossX(float x) { _bx = x; }
	void setBossY(float y) { _by = y; }

	void setBossDirection(int dir) { _direction = dir; }

	void setMove(bool move) { _isMove = move; }
	void setIsAttack(bool attack) { _isAttack = attack; }
	void setIsJump(bool jump) { _isJump = jump; }
	void setIsDrop(bool drop) { _isDrop = drop; }
	void setFloat(bool isFloat) { _isFloat = isFloat; }
	void setDash(bool dash) { _isDash = dash; }
	void setIdle(bool idle) { _isIdle = idle; }

	void setTime(float time) { _time = time; }
	void setJumpPower(float jumpPower) { _jumpPower = jumpPower; }


	// Memory
	void setPlayerMemoryAddressLink(player* player) { _player = player; }

};

