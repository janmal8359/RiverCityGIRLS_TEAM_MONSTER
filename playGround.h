#pragma once
#include "gameNode.h"
#include "imageStorage.h"
#include "schoolGirl.h"



class playGround : public gameNode
{
private:
	imageStorage* _is;

public:
	playGround();
	~playGround();

	virtual HRESULT init();			//�ʱ�ȭ �Լ�
	virtual void release();			//�޸� ���� �Խ�
	virtual void update();			//�����ϴ� �Լ�
	virtual void render();			//�׸��� �Լ�

	
};

