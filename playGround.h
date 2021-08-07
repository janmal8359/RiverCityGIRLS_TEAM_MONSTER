#pragma once
#include "gameNode.h"
#include "imageStorage.h"
#include "schoolGirl.h"
#include "player.h"
#include "boss.h"
#include "enemy.h"

//#include "bossStage1.h"
//#include "bossStage2.h"
//#include "firstStage.h"
//#include "secondStage.h"
//#include "thirdStage.h"
//#include "stageManager.h"

 
class playGround : public gameNode
{
private:
	imageStorage* _imageStorage;

	//firstStage* _stage1;
	//secondStage* _stage2;
	//thirdStage* _stage3;
	//bossStage1* _stage4;
	//bossStage2* _stage5;

	player* _player;
	enemy* _enemy;

	boss* _boss;

	float _probeLX, _probeTY, _probeRX, _probeBY;

public:
	playGround();
	~playGround();

	virtual HRESULT init();			//초기화 함수
	virtual void release();			//메모리 해제 함슈
	virtual void update();			//연산하는 함수
	virtual void render();			//그리기 함수

	//void testCollision();
};

