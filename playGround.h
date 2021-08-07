#pragma once
#include "gameNode.h"
#include "schoolGirl.h"

#include "player.h"
#include "boss.h"
#include "imageStorage.h"

 
class playGround : public gameNode
{
private:
	//�̹��� �ʱ�ȭ Ŭ����
	imageStorage* _imgStorage;


	player* _player;

	boss* _boss;

public:
	playGround();
	~playGround();

	virtual HRESULT init();			//�ʱ�ȭ �Լ�
	virtual void release();			//�޸� ���� �Խ�
	virtual void update();			//�����ϴ� �Լ�
	virtual void render();			//�׸��� �Լ�

	
};

