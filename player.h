#pragma once
#include "gameNode.h"
#include "imageStorage.h"

#include "wait.h"

#include "idle.h"
#include "walk.h"
#include "run.h"
#include "jump.h"

#include "hit.h"
#include "guard.h"
#include "down.h"
#include "stand.h"
#include "stun.h"
#include "die.h"

#include "atk.h"
#include "sAtk.h"
#include "sAtkDown.h"

#include "grab.h"
#include "stomp.h"
#include "jumpAtk.h"
#include "dashAttack.h"
#include "dashSAttack.h"

#define GRAVITY 1.0f  // 중력값

#pragma warning(disable:4996)

class bossState;

class player : public gameNode
{
private:
	state* _state;
	bossState* _bState;

	imageStorage* _imageStorage;

	image* _shadowImg;		//그림자 이미지
	RECT   _shadowRc;       //그림자 직사각형
	
	float _sX, _sY;			//그림자 x,y
	float _speed;			//이동 속도
	float _jumpPower;		//점프 파워

	bool  _isJump;          //점프하고 있는지
	bool  _isAttacking;     //공격하고 있는지

	bool  _isHitToEnemy;   //내 공격이 상대에게 들어갔는지.
	
	image* _playerImg;		//플레이어의 이미지
	RECT  _playerRc;        //플레이어의 직사각형

	float _pX, _pY;			//실제 플레이어의 x,y 값


	

	int _dir;				//빙향

	


public:
	player();
	~player();

    HRESULT init();			//초기화 함수
    void release();			//메모리 해제 함슈
    void update();			//연산하는 함수
    void render();			//그리기 함수

	void stateRender(animation* motion);
	void move();

	
	void playerAni();		//플레이어 애니메이션 모음
	
	static void callBack(void* obj);

	// 접근자 및 설정자 
	
	//플레이어 X 
	float getPlayerX() { return _pX; }
	void setPlayerX(float px) { _pX = px; }

	//플레이어 Y
	float getPlayerY() { return _pY; }
	void setPlayerY(float py) { _pY = py; }

	//그림자 X
	float getShadowX() { return _sX; }
	void setShadowX(float sx) { _sX = sx; }

	//그림자 Y
	float getShadowY() { return _sY; }
	void setShadowY(float sy) { _sY = sy; }

	//이동속도
	float getSpeed() { return _speed; }
	void setSpeed(float speed) { _speed = speed; }
	
	//점프값 설정
	float getJumpPower() { return _jumpPower; }
	void setJumpPower(float jumppower) { _jumpPower = jumppower; }

	//플레이어의 점프상황을 설정 접근자
	bool getIsJump() { return _isJump; }
	void setIsJump(bool isJump) { _isJump = isJump; }

	bool getIsAttacking() { return _isAttacking; }
	void setIsAttacking(bool isAttack) { _isAttacking = isAttack; }

	//플레이어 직사각형 설정
	RECT getPlayerRc() { return _playerRc; }
	RECT getShadowRc() { return _shadowRc; }

	//플레이어의 방향을 가져온다 
	int getDir() { return _dir; }

	//플레이어의 이미지를 가져온다
	image* getPlayerImg() { return _playerImg; }
	image* getShadowImg() { return _shadowImg; }


	//중간에 모션이 바뀌면 렌더로 바뀌지 않은 이미지가 로드됨으로 update부터 다시 시작
	void setState(state* state) { _state = state; update(); update(); }

	state* getState() { return _state; }






};

