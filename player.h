#pragma once
#include "gameNode.h"
#include "camera.h"
#include "imageStorage.h"


#include "wait.h"

#include "idle.h"
#include "walk.h"
#include "run.h"
#include "jump.h"

#include "hit.h"
#include "guard.h"
#include "down.h"
#include "stand.h"
#include "stun.h"
#include "die.h"

#include "atk.h"
#include "sAtk.h"
#include "sAtkDown.h"

#include "grab.h"
#include "stomp.h"
#include "jumpAtk.h"
#include "dashAttack.h"
#include "dashSAttack.h"

#define GRAVITY 1.0f  // �߷°�

#pragma warning(disable:4996)

class boss;



class player : public gameNode
{
private:
	camera* _camera;

	state* _state;
	boss* _boss;

	image* _shadowImg;		//�׸��� �̹���
	RECT   _shadowRc;       //�׸��� ���簢��
	
	float _sX, _sY;			//�׸��� x,y
	float _speed;			//�̵� �ӵ�
	float _jumpPower;		//���� �Ŀ�

	//�Ұ���
	bool  _isJump;          //�����ϰ� �ִ���
	
	bool  _isAttacking;     //�����ϰ� �ִ���

	bool  _isHitToEnemy;	//�� ������ ��뿡�� ������.

	bool _isGetHit;			//������ �¾�����
	bool _isGuarding;		//���� ����ϰ�������
	
	//�÷��̾� ����
	image* _playerImg;		//�÷��̾��� �̹���
	RECT  _playerRc;        //�÷��̾��� ���簢��

	float _pX, _pY;			//���� �÷��̾��� x,y ��


	int _hp;				//�÷��̾� ü��

	int _dir;				//����

	//�������� ī�޶� ������

	
	


public:
	player();
	~player();

    HRESULT init();			//�ʱ�ȭ �Լ�
    void release();			//�޸� ���� �Խ�
    void update();			//�����ϴ� �Լ�
    void render();			//�׸��� �Լ�

	void stateRender(animation* motion);
	void move();

	
	void playerAni();		//�÷��̾� �ִϸ��̼� ����
	
	void playerSound();

	void attack();

	static void callBack(void* obj);

	// ������ �� ������ 
	
	//�÷��̾� X 
	float getPlayerX() { return _pX; }
	void setPlayerX(float px) { _pX = px; }

	//�÷��̾� Y
	float getPlayerY() { return _pY; }
	void setPlayerY(float py) { _pY = py; }

	//�׸��� X
	float getShadowX() { return _sX; }
	void setShadowX(float sx) { _sX = sx; }

	//�׸��� Y
	float getShadowY() { return _sY; }
	void setShadowY(float sy) { _sY = sy; }

	//�̵��ӵ�
	float getSpeed() { return _speed; }
	void setSpeed(float speed) { _speed = speed; }
	
	//������ ����
	float getJumpPower() { return _jumpPower; }
	void setJumpPower(float jumppower) { _jumpPower = jumppower; }

	//�÷��̾��� ��Ȳ�� ���� ������
	bool getIsJump() { return _isJump; }
	void setIsJump(bool isJump) { _isJump = isJump; }

	bool getIsAttacking() { return _isAttacking; }
	void setIsAttacking(bool isAttack) { _isAttacking = isAttack; }

	bool getIsHitToEnemy() { return _isHitToEnemy; }
	void setIsHitToEnemy(bool isHitToEnemy) { _isHitToEnemy = isHitToEnemy; }

	bool getIsGuarding() { return _isGuarding; }
	void setIsGuarding(bool isGuard) { _isGuarding = isGuard; }

	bool getIsGetHit() { return _isGetHit; }
	void setIsGetHit(bool isGetHit) { _isGetHit = isGetHit; }

	//�÷��̾� ü�� 
	int getPlayerHp() { return _hp; }
	void setPlayerHp(int playerHp) { _hp = playerHp; }

	//�÷��̾� ���簢�� ����
	RECT getPlayerRc() { return _playerRc; }
	RECT getShadowRc() { return _shadowRc; }

	//�÷��̾��� ������ �����´� 
	int getDir() { return _dir; }

	//�÷��̾��� �̹����� �����´�
	image* getPlayerImg() { return _playerImg; }
	image* getShadowImg() { return _shadowImg; }


	//�߰��� ����� �ٲ�� ������ �ٲ��� ���� �̹����� �ε������ update���� �ٽ� ����
	void setState(state* state) { _state = state; update(); update(); }

	void setCamera(camera* camera) { _camera = camera; }

	state* getState() { return _state; }







	// width, height
	float getWidth() { return _shadowRc.right - _shadowRc.left; }
	float getHeight() { return _shadowRc.bottom - _shadowRc.top; }


	// bossMemory
	void setBossMemoryAddressLink(boss* boss) { _boss = boss; }


};

