#pragma once
#include "gameNode.h"
#include "enemy.h"
#include "boss.h"
#include "schoolGirl.h"
#include <vector>


class enemyManager : public gameNode
{
private:
	typedef vector<enemy*>					vGirl;
	typedef vector<enemy*>::iterator		viGirl;



	enemy* _enemy;

	vGirl _vGirl;
	viGirl _viGirl;

	

public:
	
	enemyManager();
	~enemyManager();

	virtual HRESULT init();			//�ʱ�ȭ �Լ�
	virtual void release();			//�޸� ���� �Խ�
	virtual void update();			//�����ϴ� �Լ�
	virtual void render();			//�׸��� �Լ�


	void setSchoolGirl();

	void removeSchoolGirl(int arrNum);

	vGirl getVGirl() { return _vGirl; }
	viGirl getVIGirl() { return _viGirl; }

};