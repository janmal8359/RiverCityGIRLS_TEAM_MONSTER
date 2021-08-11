#pragma once
#include "gameNode.h"
#include "enemyState.h"


class player;
class camera;

class enemy : public gameNode
{

private:
		
	player* _player;				//플레이어
	camera* _camera;				//카메라
	
	enemyState* _enemyState;		//에너미 스테이트

	image*	_enemyShadowImg;		//적 그림자 이미지
	RECT	_enemyShadowRc;			//그림자 렉트

	float _enemySX, _enemySY;		//그림자 x,y
	float _enemySpeed, _enemyRes;	//속도,속도줄어듬?

	float _enemyJP;					//점프파워

	bool _isEIdle;					//기본 불값
	bool _isEJump;					//점프 불값
	bool _isEChase;					//추격 불값
	bool _isEAttack;				//공격 불값
	bool _isEHurt;					//피격 불값
	bool _isEWaitAttack;			//어택 대기 불값
	bool _isDie;					//죽음 불값
	bool _isRun;					//달리는 불값

	image* _enemyImg;				//적 이미지
	RECT _enemyRc;					//적 렉트
	
	int _enemyCount;					//어택 동작카운트


	float _enemyX, _enemyY;			//적 x,y값
	float _enemyDistance;			//적이 왼쪽 바라볼때 플레이어 거리
	float _enemyDistanceR;			//적이 오른쪽 바라볼때 플레이어 거리



	int _enemyDir;					//적 방향

	

public:
	enemy();
	~enemy();

	HRESULT init();					//초기화
	void release();					//메모리 해제
	void update();					//연산함수
	void render();					//그리기 함수

	void enemyStateRender(animation* motion);				//스테이트 렌더?
	void enemyMove();										//움직임
	void enemyAttack();										//공격
	//void enemyChase();									//추격

	void enemyAni();										//적 애니메이션
	

	static void callBack(void* obj);
	
	//접근자 및 설정자

	//적 x
	float getEnemyX() { return _enemyX; }
	void setEnemyX(float Ex) { _enemyX = Ex; }

	//적 y
	float getEnemyY() { return _enemyY; }
	void seteEnemyY(float Ey) { _enemyY = Ey; }

	//적 그림자 x
	float getEnemySX() { return _enemySX; }
	void setEnemySX(float ESx) {_enemySX = ESx; }

	//적 그림자 y
	float getEnemySY() { return _enemySY; }
	void setEnemySY(float ESy) { _enemySY = ESy; }

	//적 스피드값
	float getEnemySpeed() { return _enemySpeed; }
	void setEnemySpeed(float ESpeed) { _enemySpeed = ESpeed; }

	//적 점프값
	float getEnemyJumpPower() { return _enemyJP; }
	void setEnemyJumpPower(float EJump) { _enemyJP = EJump; }


	//적 일반상황
	bool getIsEnemyIdle() { return _isEIdle; }
	void setIsEnemyIdle(bool isEIdle) { _isEIdle = isEIdle; }
	//적 점프상황
	bool getIsEenmyJump() { return _isEJump; }
	void setIsEnemyJump(bool isEJump) { _isEJump = isEJump; }
	//적 공격상황
	bool getIsEnemyAttack() { return _isEAttack; }
	void setIsEnemyAttack(bool isEattack) { _isEAttack = isEattack; }
	//적 추격상황
	bool getIsEenmyChase() { return _isEChase; }
	void setIsEnemyChase(bool isEchase) { _isEChase = isEchase; }
	//적 피격상황
	bool getIsEnemyHurt() { return _isEHurt; }
	void setIsEnemyHurt(bool isEhurt) { _isEHurt = isEhurt; }
	//적 어택대기 상황
	bool getIsEnemyWaitAttack() { return _isEWaitAttack; }
	void setIsEnemyWaitAttack(bool isEWaitAttack) { _isEWaitAttack = isEWaitAttack; }
	//적 죽음 상황
	bool getIsEnemyDie() { return _isDie; }
	void setIsEnemyDie(bool isDie) { _isDie = isDie; }
	//적 달리는 상황
	bool getIsEnemyRun() { return _isRun; }
	void setIsEnemyRun(bool isRun) { _isRun = isRun; }
	
	//적과 플레이어 거리값
	float getEnemyDistance() { return _enemyDistance; }			//왼쪽 바라볼때
	float getEnemyDistanceR() { return _enemyDistanceR; }		//오른쪽 바라볼때
	
	int getEnemyCount() { return _enemyCount; }								//에너미 동작 카운트
	void setEnemyCount(int enemyCount) { _enemyCount = enemyCount; }		

	//적 렉트
	RECT getEnemyRc() { return _enemyRc; }

	//적 방향
	int getDir() { return (int)_enemyDir; }

	//적 이미지
	image* getEnemyImg() { return _enemyImg; }
	void setEnemyImg(image* EnemyIMG) { _enemyImg = EnemyIMG; }

	//중간에 모션이 바뀌면 렌더로 바뀌지 않으 이미지가 로드됨 update부터 다시 시작이랍니다.
	void setEnemyState(enemyState* EState) { _enemyState = EState; update(); update(); }

	enemyState* getEnemyState() { return _enemyState; }

	//player와 연동
	void setPlayerMemoryLink(player* player) { _player = player; }

	virtual float getPosY() { return _enemySY; }

	//camera와 연동
	void setCameraMemoryLink(camera* camera) { _camera = camera; }
};

