#pragma once
#include "gameNode.h"
#include "enemyState.h"

#include "camera.h"

class player;


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
	float _enemyGravity;			//�߷°�

	bool _isEIdle;					//�⺻ �Ұ�
	bool _isEJump;					//���� �Ұ�
	bool _isEChase;					//�߰� �Ұ�
	bool _isEAttack;				//���� �Ұ�
	bool _isEHurt;					//�ǰ� �Ұ�
	bool _isEWaitAttack;			//���� ��� �Ұ�
	bool _isDie;					//���� �Ұ�
	bool _isRun;					//�޸��� �Ұ�
	bool _isRunAttack;				//�뽬 ���� �Ұ�
	bool _isCompleteDeath;			//������ ����


	image* _enemyImg;				//�� �̹���
	RECT _enemyRc;					//�� ��Ʈ
	
	int _enemyCount;				//���� ����ī��Ʈ
	int _hitCount;
	int _dieCount;					//�׾����� ���󰡴°� ���ߴ� ī��Ʈ
	float _dieSpeed;				//�׾����� ���ǵ�
	
	int _completeDeath;				//������ ����


	
	int _enemyHp;					//���ʹ� ü��
	


	float _enemyX, _enemyY;			//�� x,y��
	float _enemyDistance;			//���� ���� �ٶ󺼶� �÷��̾� �Ÿ�
	float _enemyDistanceR;			//���� ������ �ٶ󺼶� �÷��̾� �Ÿ�



	int _enemyDir;					//�� ����

	

public:
	enemy();
	~enemy();

	HRESULT init();					//�ʱ�ȭ
	HRESULT init(POINT pt);
	void release();					//�޸� ����
	void update();					//�����Լ�
	virtual void render() override;					//�׸��� �Լ�

	void enemyStateRender(animation* motion);				//������Ʈ ����?
	void enemyMove();										//������
	void enemyHp();											//Hp �Լ�

	void playerHit();										//�÷��̾� ������ �Լ�

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
	//�� ������ ����
	bool getIsEnemyCompleteDeath() { return _isCompleteDeath; }
	void setIsEnemyCompleteDeath(bool CompleteDeath) { _isCompleteDeath = CompleteDeath; }

	bool getIsEnemyRunAttack() { return _isRunAttack; }
	void setIsEnemyRunAttack(bool isRunAttack) { _isRunAttack = isRunAttack; }
	
	//���� �÷��̾� �Ÿ���
	float getEnemyDistance() { return _enemyDistance; }			//���� �ٶ󺼶�
	float getEnemyDistanceR() { return _enemyDistanceR; }		//������ �ٶ󺼶�
	
	int getEnemyCount() { return _enemyCount; }								//���ʹ� ���� ī��Ʈ
	void setEnemyCount(int enemyCount) { _enemyCount = enemyCount; }		

	int getHitCount() { return _hitCount; }
	void setHitCount(int hitCount) { _hitCount = hitCount; }

	int getDieCount() { return _dieCount; }
	void setDieCount(int dieCount) { _dieCount = dieCount; }

	int getEnemyHp() { return _enemyHp; }
	void setEnemeyHp(int enemyHp) { _enemyHp = enemyHp; }

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

