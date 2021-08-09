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

	image* _enemyImg;
	int _enemyDir;

	animation* _enemyAni;

	enemy* _enemy;
	RECT _enemyRc;


public:
	enemyState();
	~enemyState();

	virtual HRESULT init() = 0; //초기화
	virtual void release() = 0;
	virtual void update() = 0;
	virtual void render() = 0;

	virtual void enemyStateChange() {};
	virtual void enemyAni() {};

	virtual void setEnemy(enemy* enemy) { _enemy = enemy; }

	//접근자 설정자
	
	//적 애니
	virtual animation* getEnemeyAni() { return _enemyAni; }
	//적 이미지
	virtual image* getEnemyImg() { return _enemyImg; }
};

class enemyIdle : public enemyState		//기본
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

class enemyChase : public enemyState	//추적
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

class enemyAttack : public enemyState	//공격
{

private:

	int _EattackIdx;		//적 콤보

public:

	enemyAttack();
	~enemyAttack();

	virtual HRESULT init() override;
	virtual void release() override;
	virtual void update() override;
	virtual void render() override;

	virtual void enemyStateChange();
	virtual void enemyAni();

	void callBk(); //콜백
};


class enemyHurt : public enemyState		//피격
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
};

class enemyJump : public enemyState		//점프
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

class enemyDie : public enemyState		//죽음
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

class enemybackdown : public enemyState		//넘어짐
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

class enemyheld : public enemyState		//잡힘
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