#pragma once
#include "gameNode.h"
#include "imageStorage.h"

#include "enemyState.h"


class enemy : public gameNode
{

private:
	
	imageStorage* _IS;				//�̹��� ���丮��

	enemyState* _ES;				//���ʹ� ������Ʈ

	image*	_enemyShadowImg;		//�� �׸��� �̹���
	RECT	_enemyShadowRc;			//�׸��� ��Ʈ

	float _enemySX, _enemySY;		//�׸��� x,y
	float _enemySpeed, _enemyRes;	//�ӵ�,�ӵ��پ��?

	float _enemyJP;					//�����Ŀ�

	bool _isEJump;					//���� �Ұ�


	image* _enemyImg;				//�� �̹���
	RECT _enemyRc;					//�� ��Ʈ

	float _enemyX, _enemyY;			//�� x,y��
	
	int _enemyDir;					//�� ����

public:
	enemy();
	~enemy();

	HRESULT init();					//�ʱ�ȭ
	void release();					//�޸� ����
	void update();					//�����Լ�
	void render();					//�׸��� �Լ�

	void enemyStateRender(animation* motion);				//������Ʈ ����?
	void enemyMove();											//������

	void enemyAni();										//�� �ִϸ��̼�

	static void callBack(void* obj);
	
	//������ �� ������

	//�� x
	float getEnemyX() { return _enemyX; }
	void setEnemyX(float ex) { _enemyX = ex; }

	//�� y
	float getEnemyY() { return _enemyY; }
	void seteEnemyY(float ey) { _enemyY = ey; }

	//�� �׸��� x
	float getEnemySX() { return _enemySX; }
	void setEnemySX(float esx) {_enemySX = esx; }

	//�� �׸��� y
	float getEnemySY() { return _enemySY; }
	void setEnemySY(float esy) { _enemySY = esy; }

	//�� ���ǵ尪
	float getESpeed() { return _enemySpeed; }
	void setESpeed(float ess) { _enemySpeed = ess; }

	//�� ������
	float getEJP() { return _enemyJP; }
	void sestEJP(float ejp) { _enemyJP = ejp; }

	//�� ������Ȳ
	float getIsEJP() { return _isEJump; }
	void setIsEJP(float isejp) { _isEJump = isejp; }

	//�� ��Ʈ
	RECT getEnemyRc() { return _enemyRc; }

	//�� ����
	int getDir() { return _enemyDir; }

	//�� �̹���
	image* getEnmeyImg() { return _enemyImg; }

	//�߰��� ����� �ٲ�� ������ �ٲ��� ���� �̹����� �ε�� update���� �ٽ� �����̶��ϴ�.
	void setEnemyState(enemyState* es) { _ES = es; update(); update(); }

	enemyState* getEnemyState() { return _ES; }

};

