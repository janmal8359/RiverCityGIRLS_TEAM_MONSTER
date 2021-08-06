#pragma once
#include "gameNode.h"
#include "schoolGirl.h"
#include "player.h"
#include "imageStorage.h"
//스테이지 해더파일
#include "bossStage1.h"
#include "bossStage2.h"
#include "firstStage.h"
#include "secondStage.h"
#include "thirdStage.h"

class playGround : public gameNode
{
private:
	//이미지 초기화 클래스
	imageStorage* _imgStorage;
	firstStage* _stage;
	player* _player;

public:
	playGround();
	~playGround();

	virtual HRESULT init();			//초기화 함수
	virtual void release();			//메모리 해제 함슈
	virtual void update();			//연산하는 함수
	virtual void render();			//그리기 함수

	
};

