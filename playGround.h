#pragma once
#include "gameNode.h"
#include "schoolGirl.h"
#include "player.h"
#include "imageStorage.h"
//스테이지 해더파일(다이랙트)
//#include "bossStage1.h"
//#include "bossStage2.h"
//#include "firstStage.h"
//#include "secondStage.h"
//#include "thirdStage.h"
//스테이지 해더파일(씬 매니저)
//#include "stageManager.h"

class playGround : public gameNode
{
private:
	//이미지 초기화 클래스
	imageStorage* _imgStorage;

	//firstStage* _stage1;
	//secondStage* _stage2;
	//thirdStage* _stage3;
	//bossStage1* _stage4;
	//bossStage2* _stage5;

	player* _player;

public:
	playGround();
	~playGround();

	virtual HRESULT init();			//초기화 함수
	virtual void release();			//메모리 해제 함슈
	virtual void update();			//연산하는 함수
	virtual void render();			//그리기 함수

	
};

