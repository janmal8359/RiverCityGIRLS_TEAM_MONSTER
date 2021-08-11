#pragma once
#include "gameNode.h"
#include "animation.h"


class enemy;

enum enemyDir
{
	ENEMY_LEFT,
	ENEMY_RIGHT
};

class enemyState : public gameNode
{
protected:

	int _EattackIdx;		//�� ���ݽ� ī��Ʈ
	int	_EhultIdx;			//�� �ǰݽ� ī��Ʈ
	image* _enemyImg;
	int _enemyDir;


	int _EHurtcount;			//�ǰ� ī��Ʈ
	animation* _enemyAni;

	enemy* _enemy;
	RECT _enemyRc;


public:
	enemyState();
	~enemyState();

	virtual HRESULT init(); //�ʱ�ȭ
	virtual void release();
	virtual void update();
	virtual void render();

	virtual void enemyStateChange() {};
	virtual void enemyAni() {};

	virtual void callBk();

	virtual void setEnemy(enemy* enemy) { _enemy = enemy; }

	int getEattackIdx() { return _EattackIdx; }			//����ī��Ʈ
	void setEattackIdx(int EattackIdx) { _EattackIdx = EattackIdx; }

	int getEhultIdx() { return _EhultIdx; }				//�ǰ�ī��Ʈ

	int getEhurtcount() { return _EHurtcount; }			//�ǰ� �ð� ī��Ʈ

	//������ ������
	
	//�� �ִ�
	virtual animation* getEnemeyAni() { return _enemyAni; }
	
	//�� �̹���
	virtual image* getEnemyImg() { return _enemyImg; }
};

class enemyIdle : public enemyState		//�⺻
{

public:

	enemyIdle();
	~enemyIdle();

	virtual HRESULT init() override;
	virtual void release() override;
	virtual void update()  override;
	virtual void render()  override;

	virtual void enemyStateChange();
	virtual void enemyAni();
};

class enemyChase : public enemyState	//����
{

public:

	enemyChase();
	~enemyChase();

	virtual HRESULT init() override;
	virtual void release() override;
	virtual void update() override;
	virtual void render() override;

	virtual void enemyStateChange();
	virtual void enemyAni();

};

class enemyAttack : public enemyState	//����
{

private:

	

public:

	enemyAttack();
	~enemyAttack();

	virtual HRESULT init() override;
	virtual void release() override;
	virtual void update() override;
	virtual void render() override;

	virtual void enemyStateChange();
	virtual void enemyAni();

	virtual void callBk(); //�ݹ�
};


class enemyHurt : public enemyState		//�ǰ�
{

public:

	enemyHurt();
	~enemyHurt();

	virtual HRESULT init() override;
	virtual void release() override;
	virtual void update() override;
	virtual void render() override;

	virtual void enemyStateChange();
	virtual void enemyAni();

	virtual void callBk();
};

class enemyJump : public enemyState		//����
{

public:

	enemyJump();
	~enemyJump();

	virtual HRESULT init() override;
	virtual void release() override;
	virtual void update() override;
	virtual void render() override;

	virtual void enemyStateChange();
	virtual void enemyAni();
};

class enemyDie : public enemyState		//����
{

public:

	enemyDie();
	~enemyDie();

	virtual HRESULT init() override;
	virtual void release() override;
	virtual void update() override;
	virtual void render() override;

	virtual void enemyStateChange();
	virtual void enemyAni();
};

class enemybackdown : public enemyState		//�Ѿ���
{

public:

	enemybackdown();
	~enemybackdown();

	virtual HRESULT init() override;
	virtual void release() override;
	virtual void update() override;
	virtual void render() override;

	virtual void enemyStateChange();
	virtual void enemyAni();
};

class enemyheld : public enemyState		//����
{

public:

	enemyheld();
	~enemyheld();

	virtual HRESULT init() override;
	virtual void release() override;
	virtual void update() override;
	virtual void render() override;

	virtual void enemyStateChange();
	virtual void enemyAni();
};

class enemyWaitAttack : public enemyState //���ݸ�� ���
{

public:
	enemyWaitAttack();
	~enemyWaitAttack();

	virtual HRESULT init() override;
	virtual void release() override;
	virtual void update() override;
	virtual void render() override;

	virtual void enemyStateChange();
	virtual void enemyAni();

};