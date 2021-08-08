#include "pch.h"
#include "bossState.h"
#include "boss.h"
#include "player.h"


HRESULT bossState::init()
{
	return S_OK;
}

void bossState::release()
{
}

void bossState::update()
{
	anim();
	stateChange();
}

void bossState::render()
{
	_boss->stateRender(_bossAnim);
}

void bossState::stateChange()
{
}

void bossState::anim()
{
}


idleState::idleState()
{
	_bossImg = IMAGEMANAGER->findImage("BOSS_idle");
	_bossAnim = KEYANIMANAGER->findAnimation("BOSS_idleL");
}

idleState::~idleState()
{
}

// Idle
HRESULT idleState::init()
{
	bossState::init();

	_bossImg = IMAGEMANAGER->findImage("BOSS_idle");

	return S_OK;
}

void idleState::release()
{
}

void idleState::update()
{
	bossState::update();

	_bossImg = IMAGEMANAGER->findImage("BOSS_idle");

}

void idleState::render()
{
	//if (_bossImg == nullptr) _bossImg = IMAGEMANAGER->findImage("BOSS_idle");
	//if (_bossAnim == nullptr) _bossAnim = KEYANIMANAGER->findAnimation("BOSS_idleL");

	bossState::render();
}

void idleState::stateChange()
{
	// 임시 키 조작으로 이동
	if (getDistance(_boss->getPlayer()->getShadowX(), _boss->getPlayer()->getShadowY(), _boss->getBossShadowX(), _boss->getBossShadowY()) > 50)
	{
		_boss->setMove(true);
		_boss->setState(new walkState);
	}
}

void idleState::anim()
{
	if (_boss->getBossDirection() == DIRECTION::LEFT)
	{
		_bossAnim = KEYANIMANAGER->findAnimation("BOSS_idleL");
		_bossAnim->resume();
	}

	if (_boss->getBossDirection() == DIRECTION::RIGHT)
	{
		_bossAnim = KEYANIMANAGER->findAnimation("BOSS_idleR");
		_bossAnim->resume();
	}
}


walkState::walkState()
{
	_bossImg = IMAGEMANAGER->findImage("BOSS_walk");
	_bossAnim = KEYANIMANAGER->findAnimation("BOSS_walkL");
}

walkState::~walkState()
{
}

// Walk
HRESULT walkState::init()
{
	//bossState::init();

	_bossImg = IMAGEMANAGER->findImage("BOSS_walk");

	return S_OK;
}

void walkState::release()
{
}

void walkState::update()
{
	bossState::update();

	_bossImg = IMAGEMANAGER->findImage("BOSS_walk"); 
	
}

void walkState::render()
{
	//if (_bossImg == nullptr) _bossImg = IMAGEMANAGER->findImage("BOSS_walk");
	//if (_bossAnim == nullptr) _bossAnim = KEYANIMANAGER->findAnimation("BOSS_walkL");

	bossState::render();
}

void walkState::stateChange()
{
	if (getDistance(_boss->getPlayer()->getShadowX(), _boss->getPlayer()->getShadowY(), _boss->getBossShadowX(), _boss->getBossShadowY()) <= 50)
	{
		_boss->setMove(false);
		_boss->setState(new idleState);
	}
}

void walkState::anim()
{
	if (_boss->getBossDirection() == DIRECTION::LEFT)
	{
		_bossAnim = KEYANIMANAGER->findAnimation("BOSS_walkL");
		_bossAnim->resume();
	}

	if (_boss->getBossDirection() == DIRECTION::RIGHT)
	{
		_bossAnim = KEYANIMANAGER->findAnimation("BOSS_walkR");
		_bossAnim->resume();
	}
}


// Attack
HRESULT attackState::init()
{
	return S_OK;
}

void attackState::release()
{
}

void attackState::update()
{
	bossState::update();
}

void attackState::render()
{
	bossState::render();
}


// JumpAttack
HRESULT jumpState::init()
{
	return S_OK;
}

void jumpState::release()
{
}

void jumpState::update()
{
	bossState::update();
}

void jumpState::render()
{
	bossState::render();
}


// Sit
HRESULT sitState::init()
{
	return S_OK;
}

void sitState::release()
{
}

void sitState::update()
{
	bossState::update();
}

void sitState::render()
{
	bossState::render();
}


// Groggy
HRESULT groggyState::init()
{
	return S_OK;
}

void groggyState::release()
{
}

void groggyState::update()
{
	bossState::update();
}

void groggyState::render()
{
	bossState::render();
}


// Lose
HRESULT loseState::init()
{
	return S_OK;
}

void loseState::release()
{
}

void loseState::update()
{
	bossState::update();
}

void loseState::render()
{
	bossState::render();
}