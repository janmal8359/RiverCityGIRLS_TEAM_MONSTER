#pragma once
#include "gameNode.h"
#include "enemyState.h"


class player;
class camera;

class enemy : public gameNode
{

private:
		
	player* _player;				//�÷��̾�
	camera* _camera;				//ī�޶�
	
	enemyState* _enemyState;		//���ʹ� ������Ʈ

	image*	_enemyShadowImg;		//�� �׸��� �̹���
	RECT	_enemyShadowRc;			//�׸��� ��Ʈ

	float _enemySX, _enemySY;		//�׸��� x,y
	float _enemySpeed, _enemyRes;	//�ӵ�,�ӵ��پ��?

	float _enemyJP;					//�����Ŀ�

	bool _isEIdle;					//�⺻ �Ұ�
	bool _isEJump;					//���� �Ұ�
	bool _isEChase;					//�߰� �Ұ�
	bool _isEAttack;				//���� �Ұ�
	bool _isEHurt;					//�ǰ� �Ұ�
	bool _isEWaitAttack;			//���� ��� �Ұ�
	bool _isDie;					//���� �Ұ�
	bool _isRun;					//�޸��� �Ұ�

	image* _enemyImg;				//�� �̹���
	RECT _enemyRc;					//�� ��Ʈ
	
	int _enemyCount;					//���� ����ī��Ʈ


	float _enemyX, _enemyY;			//�� x,y��
	float _enemyDistance;			//���� ���� �ٶ󺼶� �÷��̾� �Ÿ�
	float _enemyDistanceR;			//���� ������ �ٶ󺼶� �÷��̾� �Ÿ�



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


	//�� �Ϲݻ�Ȳ
	bool getIsEnemyIdle() { return _isEIdle; }
	void setIsEnemyIdle(bool isEIdle) { _isEIdle = isEIdle; }
	//�� ������Ȳ
	bool getIsEenmyJump() { return _isEJump; }
	void setIsEnemyJump(bool isEJump) { _isEJump = isEJump; }
	//�� ���ݻ�Ȳ
	bool getIsEnemyAttack() { return _isEAttack; }
	void setIsEnemyAttack(bool isEattack) { _isEAttack = isEattack; }
	//�� �߰ݻ�Ȳ
	bool getIsEenmyChase() { return _isEChase; }
	void setIsEnemyChase(bool isEchase) { _isEChase = isEchase; }
	//�� �ǰݻ�Ȳ
	bool getIsEnemyHurt() { return _isEHurt; }
	void setIsEnemyHurt(bool isEhurt) { _isEHurt = isEhurt; }
	//�� ���ô�� ��Ȳ
	bool getIsEnemyWaitAttack() { return _isEWaitAttack; }
	void setIsEnemyWaitAttack(bool isEWaitAttack) { _isEWaitAttack = isEWaitAttack; }
	//�� ���� ��Ȳ
	bool getIsEnemyDie() { return _isDie; }
	void setIsEnemyDie(bool isDie) { _isDie = isDie; }
	//�� �޸��� ��Ȳ
	bool getIsEnemyRun() { return _isRun; }
	void setIsEnemyRun(bool isRun) { _isRun = isRun; }
	
	//���� �÷��̾� �Ÿ���
	float getEnemyDistance() { return _enemyDistance; }			//���� �ٶ󺼶�
	float getEnemyDistanceR() { return _enemyDistanceR; }		//������ �ٶ󺼶�
	
	int getEnemyCount() { return _enemyCount; }								//���ʹ� ���� ī��Ʈ
	void setEnemyCount(int enemyCount) { _enemyCount = enemyCount; }		

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

	virtual float getPosY() { return _enemySY; }

	//camera�� ����
	void setCameraMemoryLink(camera* camera) { _camera = camera; }
};

