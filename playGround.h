#pragma once
#include "gameNode.h"
#include "schoolGirl.h"
#include "player.h"
#include "imageStorage.h"
//�������� �ش�����
#include "bossStage1.h"
#include "bossStage2.h"
#include "firstStage.h"
#include "secondStage.h"
#include "thirdStage.h"

class playGround : public gameNode
{
private:
	//�̹��� �ʱ�ȭ Ŭ����
	imageStorage* _imgStorage;
	firstStage* _stage;
	player* _player;

public:
	playGround();
	~playGround();

	virtual HRESULT init();			//�ʱ�ȭ �Լ�
	virtual void release();			//�޸� ���� �Խ�
	virtual void update();			//�����ϴ� �Լ�
	virtual void render();			//�׸��� �Լ�

	
};

