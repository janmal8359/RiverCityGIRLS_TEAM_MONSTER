#pragma once
#include "gameNode.h"
#include "imageStorage.h"

#include "enemyState.h"



class enemy : public gameNode
{

private:
	
	//지울거

	RECT exRc;
	POINT ex;

	

	imageStorage* _IS;				//이미지 스토리지

	enemyState* _ES;				//에너미 스테이트

	image*	_enemyShadowImg;		//적 그림자 이미지
	RECT	_enemyShadowRc;			//그림자 렉트

	float _enemySX, _enemySY;		//그림자 x,y
	float _enemySpeed, _enemyRes;	//속도,속도줄어듬?

	float _enemyJP;					//점프파워

	bool _isEJump;					//점프 불값
	bool _isEChase;					//추격 불값
	bool _isEAttack;				//공격 불값


	image* _enemyImg;				//적 이미지
	RECT _enemyRc;					//적 렉트

	float _enemyX, _enemyY;			//적 x,y값
	
	int _enemyDir;					//적 방향

	float _enemyChase;				//적 거리
	
	

public:
	enemy();
	~enemy();

	HRESULT init();					//초기화
	void release();					//메모리 해제
	void update();					//연산함수
	void render();					//그리기 함수

	void enemyStateRender(animation* motion);				//스테이트 렌더?
	void enemyMove();										//움직임
	void enemyChase();										//추격

	void enemyAni();										//적 애니메이션

	static void callBack(void* obj);
	
	//접근자 및 설정자

	//적 x
	float getEnemyX() { return _enemyX; }
	void setEnemyX(float ex) { _enemyX = ex; }

	//적 y
	float getEnemyY() { return _enemyY; }
	void seteEnemyY(float ey) { _enemyY = ey; }

	//적 그림자 x
	float getEnemySX() { return _enemySX; }
	void setEnemySX(float esx) {_enemySX = esx; }

	//적 그림자 y
	float getEnemySY() { return _enemySY; }
	void setEnemySY(float esy) { _enemySY = esy; }

	//적 스피드값
	float getESpeed() { return _enemySpeed; }
	void setESpeed(float ess) { _enemySpeed = ess; }

	//적 점프값
	float getEJP() { return _enemyJP; }
	void sestEJP(float ejp) { _enemyJP = ejp; }

	//적 점프상황
	float getIsEenmyJump() { return _isEJump; }
	void setIsEnemyJump(float isejp) { _isEJump = isejp; }
	//적 공격상황
	float getIsEenmyAttack() { return _isEAttack; }
	void setIsEnemyAttack(float iseat) { _isEAttack = iseat; }
	//적 추격상황
	float getIsEenmyChase() { return _isEChase; }
	void setIsEnemyChase(float isec) { _isEChase = isec; }


	//적 렉트
	RECT getEnemyRc() { return _enemyRc; }

	//적 방향
	int getDir() { return _enemyDir; }

	//적 이미지
	image* getEnmeyImg() { return _enemyImg; }

	//중간에 모션이 바뀌면 렌더로 바뀌지 않으 이미지가 로드됨 update부터 다시 시작이랍니다.
	void setEnemyState(enemyState* es) { _ES = es; update(); update(); }

	enemyState* getEnemyState() { return _ES; }

};

