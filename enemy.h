#pragma once
#include "gameNode.h"
#include "enemyState.h"



class player;

class enemy : public gameNode
{

private:
	
	
	player* _player;				//�÷��̾�


	enemyState* _enemyState;		//���ʹ� ������Ʈ

	image*	_enemyShadowImg;		//�� �׸��� �̹���
	RECT	_enemyShadowRc;			//�׸��� ��Ʈ

	float _enemySX, _enemySY;		//�׸��� x,y
	float _enemySpeed, _enemyRes;	//�ӵ�,�ӵ��پ��?

	float _enemyJP;					//�����Ŀ�

	bool _isEJump;					//���� �Ұ�
	bool _isEChase;					//�߰� �Ұ�
	bool _isEAttack;				//���� �Ұ�
	bool _isEHurt;					//�ǰ� �Ұ� 

	image* _enemyImg;				//�� �̹���
	RECT _enemyRc;					//�� ��Ʈ
	
	


	float _enemyX, _enemyY;			//�� x,y��
	float _enemyDistance;			//���� �÷��̾� �Ÿ�



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
	void enemyAttack();										//����
	//void enemyChase();									//�߰�

	void enemyAni();										//�� �ִϸ��̼�
	

	static void callBack(void* obj);
	
	//������ �� ������

	//�� x
	float getEnemyX() { return _enemyX; }
	void setEnemyX(float Ex) { _enemyX = Ex; }

	//�� y
	float getEnemyY() { return _enemyY; }
	void seteEnemyY(float Ey) { _enemyY = Ey; }

	//�� �׸��� x
	float getEnemySX() { return _enemySX; }
	void setEnemySX(float ESx) {_enemySX = ESx; }

	//�� �׸��� y
	float getEnemySY() { return _enemySY; }
	void setEnemySY(float ESy) { _enemySY = ESy; }

	//�� ���ǵ尪
	float getEnemySpeed() { return _enemySpeed; }
	void setEnemySpeed(float ESpeed) { _enemySpeed = ESpeed; }

	//�� ������
	float getEnemyJumpPower() { return _enemyJP; }
	void setEnemyJumpPower(float EJump) { _enemyJP = EJump; }

	//�� ������Ȳ
	float getIsEenmyJump() { return _isEJump; }
	void setIsEnemyJump(float isEJump) { _isEJump = isEJump; }
	//�� ���ݻ�Ȳ
	float getIsEnemyAttack() { return _isEAttack; }
	void setIsEnemyAttack(float isEattack) { _isEAttack = isEattack; }
	//�� �߰ݻ�Ȳ
	float getIsEenmyChase() { return _isEChase; }
	void setIsEnemyChase(float isEchase) { _isEChase = isEchase; }
	//�� �ǰݻ�Ȳ
	float getIsEnemyHurt() { return _isEHurt; }
	void setIsEnemyHurt(float isEhurt) { _isEHurt = isEhurt; }
	
	//���� �÷��̾� �Ÿ���
	float getEnemyDistance() { return _enemyDistance; }

	//�� ��Ʈ
	RECT getEnemyRc() { return _enemyRc; }

	//�� ����
	int getDir() { return (int)_enemyDir; }

	//�� �̹���
	image* getEnemyImg() { return _enemyImg; }
	void setEnemyImg(image* EnemyIMG) { _enemyImg = EnemyIMG; }

	//�߰��� ����� �ٲ�� ������ �ٲ��� ���� �̹����� �ε�� update���� �ٽ� �����̶��ϴ�.
	void setEnemyState(enemyState* EState) { _enemyState = EState; update(); update(); }

	enemyState* getEnemyState() { return _enemyState; }

	//player�� ����
	void setPlayerMemoryLink(player* player) { _player = player; }

};

