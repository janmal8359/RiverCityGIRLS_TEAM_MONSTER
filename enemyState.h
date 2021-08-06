#pragma once
#include "gameNode.h"
class enemyState : public gameNode
{
public:
	enemyState();
	~enemyState();

	virtual HRESULT init() = 0; //√ ±‚»≠
	virtual void release() = 0;
	virtual void update() = 0;
};

class enemyIdle : public enemyState
{



public:

	enemyIdle();
	~enemyIdle();

	virtual HRESULT init() override;
	virtual void release() override;
	virtual void update()  override;

};

class enemyChase : public enemyState
{



public:


	enemyChase();
	~enemyChase();

	virtual HRESULT init() override;
	virtual void release() override;
	virtual void update() override;

};

class enemyAttack : public enemyState
{

};


class enemyHurt : public enemyState
{

};