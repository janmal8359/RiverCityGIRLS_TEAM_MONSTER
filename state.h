#pragma once
#include "gameNode.h"
#include "animation.h"

#define JUMPPOWER 4.0f;
#define GRAVITY 0.3f;

class player;					//전방선언

enum dir
{
	LEFT,
	RIGHT
};

class state : public gameNode
{
protected:

	animation* _playerAniL;
	animation* _playerAniR;

	image* _playerImg;
	image* _shadowImg;

	RECT   _playerRc;
	RECT   _shadowRc;

	float  _pX, _pY;
	float  _sX, _sY;

	bool   _isJump;
	
	int	   _playerHp;

	int    _dir;




	float _speed;

	player* _player;

public:

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();



	virtual void setPlayer(player* player) { _player = player; }

	//접근자 // 설정자
	
	//플레이어 X,Y값을 Get Set 
	virtual float getPlayerX() { return _pX; }
	virtual void setPlayerX(float px) { _pX = px; }

	virtual float getPlayerY() { return _pY; }
	virtual void setPlayerY(float py) { _pY = py; }


	//플레이어 렉트
	virtual RECT getPlayerRc() { return _playerRc; }
	
	//플레이어 HP Get Set
	virtual int getPlayerHp() { return _playerHp; }
	virtual void setPlayerHp(int hp) { _playerHp = hp; }


	//그림자  X,Y 값을 Get Set
	virtual float getShadowX() { return _sX; }
	virtual void setShadowX(float sx) { _sX = sx; }

	virtual float getShadowY() { return _sY; }
	virtual void setShadowY(float sy) { _sY = sy; }

	//그림자 렉트
	virtual RECT getShadowRc() { return _shadowRc; }
	virtual void setPlayerRc(RECT rc) { _playerRc = rc; }

	//속도 Get Set
	virtual float getSpeed() { return _speed; }
	virtual void setSpeed(float speed) { _speed = speed; }

	//방향을 Get Set
	virtual int getDir() { return _dir; }
	virtual void setDir(int dir) { _dir = dir; }

	

};

