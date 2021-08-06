#pragma once
#include "boss.h"

class bossState
{
public:
	virtual void idle();
	virtual void walk();				// 플레이어 쫓아가기
	virtual void soulderTackle();		// 숄더태클(어택)
	virtual void punch();				// 주먹휘두르기(어택)
	virtual void jumpAttack();			// 점프공격
	virtual void sit();					// 앉아있는 상태
	virtual void groggy();				// 그로기 상태(행동 불가)
	virtual void lose();				// 보스 패배

protected:
	void setBossState(boss* boss, bossState* state) { /*boss->setState(); // 상태 변경*/ }
};

class idleState : public bossState
{
private:
	idleState* instance;

public:
	idleState* getInstance() { if (instance == nullptr) instance = new idleState(); return instance; }

	virtual void idle();
	virtual void walk();
	virtual void soulderTackle();
	virtual void punch();
	virtual void jumpAttack();
	virtual void sit();
	virtual void groggy();
	virtual void lose();
};

class walkState : public bossState
{
private:
	walkState* instance;

public:
	walkState* getInstance() { if (instance == nullptr) instance = new walkState(); return instance; }

	virtual void idle();
	virtual void walk();
	virtual void soulderTackle();
	virtual void punch();
	virtual void jumpAttack();
	virtual void sit();
	virtual void groggy();
	virtual void lose();
};

class attackState : public bossState
{
private:
	attackState* instance;

public:
	attackState* getInstance() { if (instance == nullptr) instance = new attackState(); return instance; }

	virtual void idle();
	virtual void walk();
	virtual void soulderTackle();
	virtual void punch();
	virtual void jumpAttack();
	virtual void sit();
	virtual void groggy();
	virtual void lose();
};

class jumpState : public bossState
{
private:
	jumpState* instance;

public:
	jumpState* getInstance() { if (instance == nullptr) instance = new jumpState(); return instance; }

	virtual void idle();
	virtual void walk();
	virtual void soulderTackle();
	virtual void punch();
	virtual void jumpAttack();
	virtual void sit();
	virtual void groggy();
	virtual void lose();
};

class sitState : public bossState
{
private:
	sitState* instance;

public:
	sitState* getInstance() { if (instance == nullptr) instance = new sitState(); return instance; }

	virtual void idle();
	virtual void walk();
	virtual void soulderTackle();
	virtual void punch();
	virtual void jumpAttack();
	virtual void sit();
	virtual void groggy();
	virtual void lose();
};

class groggyState : public bossState
{
private:
	groggyState* instance;

public:
	groggyState* getInstance() { if (instance == nullptr) instance = new groggyState(); return instance; }

	virtual void idle();
	virtual void walk();
	virtual void soulderTackle();
	virtual void punch();
	virtual void jumpAttack();
	virtual void sit();
	virtual void groggy();
	virtual void lose();
};

class loseState : public bossState
{
private:
	loseState* instance;

public:
	loseState* getInstance() { if (instance == nullptr) instance = new loseState(); return instance; }

	virtual void idle();
	virtual void walk();
	virtual void soulderTackle();
	virtual void punch();
	virtual void jumpAttack();
	virtual void sit();
	virtual void groggy();
	virtual void lose();
};
