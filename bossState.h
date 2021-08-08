#pragma once
#include "gameNode.h"

class boss;

enum class DIRECTION
{
	LEFT,
	RIGHT
};

class bossState : public gameNode
{
protected:
	image* _bossImg;
	DIRECTION _direction;

	boss* _boss;
	RECT _bossRc;

	animation* _bossAnim;

public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	virtual void stateChange();
	virtual void anim();

	image* getImg() { return _bossImg; }
	void setBoss(boss* boss) { _boss = boss; }

	animation* getBossAnim() { return _bossAnim; }

protected:
	void setBossState(boss* boss, bossState* state) { /*boss->setState(state); // 상태 변경*/ }
};

class idleState : public bossState
{
private:
	//idleState* instance;

public:
	//idleState* getInstance() { if (instance == nullptr) instance = new idleState(); return instance; }
	idleState();
	~idleState();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	virtual void stateChange();
	virtual void anim();
};

class walkState : public bossState
{
private:
	//walkState* instance;

public:
	//walkState* getInstance() { if (instance == nullptr) instance = new walkState(); return instance; }
	walkState();
	~walkState();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	virtual void stateChange();
	virtual void anim();
};

class attackState : public bossState
{
private:
	attackState* instance;

public:
	attackState* getInstance() { if (instance == nullptr) instance = new attackState(); return instance; }

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
};

class jumpState : public bossState
{
private:
	jumpState* instance;

public:
	jumpState* getInstance() { if (instance == nullptr) instance = new jumpState(); return instance; }

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
};

class sitState : public bossState
{
private:
	sitState* instance;

public:
	sitState* getInstance() { if (instance == nullptr) instance = new sitState(); return instance; }

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
};

class groggyState : public bossState
{
private:
	groggyState* instance;

public:
	groggyState* getInstance() { if (instance == nullptr) instance = new groggyState(); return instance; }

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
};

class loseState : public bossState
{
private:
	loseState* instance;

public:
	loseState* getInstance() { if (instance == nullptr) instance = new loseState(); return instance; }

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
};
