#pragma once
#include "gameNode.h"
#include "imageStorage.h"
//#include "sfxStorage.h"
#include "schoolGirl.h"
#include "player.h"
#include "boss.h"
#include "enemy.h"
#include "gameManager.h"

#include "bossStage1.h"
#include "bossStage2.h"
#include "firstStage.h"
#include "secondStage.h"
#include "thirdStage.h"
#include "stageManager.h"

 
class playGround : public gameNode
{
private:
	imageStorage* _imageStorage;
	//sfxStorage* _sfxStorage;

	gameManager* _gameManager;

	player* _player;
	enemy* _enemy;

	boss* _boss;

public:
	playGround();
	~playGround();

	virtual HRESULT init();			//�ʱ�ȭ �Լ�
	virtual void release();			//�޸� ���� �Խ�
	virtual void update();			//�����ϴ� �Լ�
	virtual void render();			//�׸��� �Լ�
};

