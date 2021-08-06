#pragma once
#include "boss.h"

class bossState
{
public:
	virtual HRESULT init() = 0;
	virtual void release() = 0;
	virtual void update() = 0;
	virtual void render() = 0;

protected:
	void setBossState(boss* boss, bossState* state) { /*boss->setState(state); // 상태 변경*/ }
};

class idleState : public bossState
{
private:
	idleState* instance;

public:
	idleState* getInstance() { if (instance == nullptr) instance = new idleState(); return instance; }

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
};

class walkState : public bossState
{
private:
	walkState* instance;

public:
	walkState* getInstance() { if (instance == nullptr) instance = new walkState(); return instance; }

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
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
