#pragma once
#include "gameNode.h"
#include "enemyState.h"



class enemy : public gameNode
{

private:
	
	//�����

	RECT exRc;
	POINT ex;

	enemyState* _enemyState;				//���ʹ� ������Ʈ

	image*	_enemyShadowImg;		//�� �׸��� �̹���
	RECT	_enemyShadowRc;			//�׸��� ��Ʈ

	float _enemySX, _enemySY;		//�׸��� x,y
	float _enemySpeed, _enemyRes;	//�ӵ�,�ӵ��پ��?

	float _enemyJP;					//�����Ŀ�

	bool _isEJump;					//���� �Ұ�
	bool _isEChase;					//�߰� �Ұ�
	bool _isEAttack;				//���� �Ұ�


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
	void enemyMove();										//������
	void enemyChase();										//�߰�

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
	float getEnemySpeed() { return _enemySpeed; }
	void setEnemySpeed(float ess) { _enemySpeed = ess; }

	//�� ������
	float getEnemyJP() { return _enemyJP; }
	void setEnemyJP(float ejp) { _enemyJP = ejp; }

	//�� ������Ȳ
	float getIsEenmyJump() { return _isEJump; }
	void setIsEnemyJump(float isejp) { _isEJump = isejp; }
	//�� ���ݻ�Ȳ
	float getIsEenmyAttack() { return _isEAttack; }
	void setIsEnemyAttack(float iseat) { _isEAttack = iseat; }
	//�� �߰ݻ�Ȳ
	float getIsEenmyChase() { return _isEChase; }
	void setIsEnemyChase(float isec) { _isEChase = isec; }


	//�� ��Ʈ
	RECT getEnemyRc() { return _enemyRc; }

	//�� ����
	int getDir() { return _enemyDir; }

	//�� �̹���
	image* getEnmeyImg() { return _enemyImg; }

	//�߰��� ����� �ٲ�� ������ �ٲ��� ���� �̹����� �ε�� update���� �ٽ� �����̶��ϴ�.
	void setEnemyState(enemyState* es) { _enemyState = es; update(); update(); }

	enemyState* getEnemyState() { return _enemyState; }

};

