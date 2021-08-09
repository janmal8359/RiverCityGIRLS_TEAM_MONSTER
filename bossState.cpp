#include "pch.h"
#include "bossState.h"
#include "boss.h"
#include "player.h"


HRESULT bossState::init()
{
	//_direction = (int)_boss->getBossDirection();

	return S_OK;
}

void bossState::release()
{
}

void bossState::update()
{
	_direction = (int)_boss->getBossDirection();

	anim();
	stateChange();
}

void bossState::render()
{
	_boss->stateRender(_bossAnim);

	char str[128];

	sprintf_s(str, "direction : %d", (int)_direction);
	TextOut(getMemDC(), 10, 320, str, strlen(str));
}

void bossState::stateChange()
{
}

void bossState::anim()
{
}


idleState::idleState()
{
	//_bossImg = IMAGEMANAGER->findImage("BOSS_idle");
	//_bossAnim = KEYANIMANAGER->findAnimation("BOSS_idleL");

	if (_direction == (int)DIRECTION::LEFT)
	{
		_bossImg = IMAGEMANAGER->findImage("BOSS_idle");
		_bossAnim = KEYANIMANAGER->findAnimation("BOSS_idleL");
	}

	else if (_direction == (int)DIRECTION::RIGHT)
	{
		_bossImg = IMAGEMANAGER->findImage("BOSS_idle");
		_bossAnim = KEYANIMANAGER->findAnimation("BOSS_idleR");
	}

	//if (_direction == DIRECTION::LEFT)
	//{
	//	_bossAnim = KEYANIMANAGER->findAnimation("BOSS_idleL");
	//}

	//else if (_direction == DIRECTION::RIGHT)
	//{
	//	_bossAnim = KEYANIMANAGER->findAnimation("BOSS_idleR");
	//}
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
	if (_direction == (int)DIRECTION::LEFT)
	{
		_bossAnim = KEYANIMANAGER->findAnimation("BOSS_idleL");
		_bossAnim->resume();
	}

	else if (_direction == (int)DIRECTION::RIGHT)
	{
		_bossAnim = KEYANIMANAGER->findAnimation("BOSS_idleR");
		_bossAnim->resume();
	}
}


walkState::walkState()
{
	//_bossImg = IMAGEMANAGER->findImage("BOSS_walk");
	//_bossAnim = KEYANIMANAGER->findAnimation("BOSS_walkL");
	//_bossAnim = KEYANIMANAGER->findAnimation("BOSS_walkR");
	if (_direction == (int)DIRECTION::LEFT)
	{
		_bossImg = IMAGEMANAGER->findImage("BOSS_walk");
		_bossAnim = KEYANIMANAGER->findAnimation("BOSS_walkL");
	}

	else if (_direction == (int)DIRECTION::RIGHT)
	{
		_bossImg = IMAGEMANAGER->findImage("BOSS_walk");
		_bossAnim = KEYANIMANAGER->findAnimation("BOSS_walkR");
	}
}

walkState::~walkState()
{
}

// Walk
HRESULT walkState::init()
{
	//bossState::init();
	//_direction = (int)_boss->getBossDirection();

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

	//if (getDistance(_boss->getPlayer()->getShadowX(), _boss->getPlayer()->getShadowY(), _boss->getBossShadowX(), _boss->getBossShadowY()) <= 80)
	//{
	//	_boss->setMove(false);
	//	_boss->setState(new attackState);
	//}
}

void walkState::anim()
{
	if (_direction == (int)DIRECTION::LEFT)
	{
		_bossAnim = KEYANIMANAGER->findAnimation("BOSS_walkL");
		_bossAnim->resume();
	}

	if (_direction == (int)DIRECTION::RIGHT)
	{
		_bossAnim = KEYANIMANAGER->findAnimation("BOSS_walkR");
		_bossAnim->resume();
	}
}


// Attack

attackState::attackState()
{
	//if (_direction == (int)DIRECTION::LEFT)
	//{
	//	_bossImg = IMAGEMANAGER->findImage("BOSS_slap");
	//	_bossAnim = KEYANIMANAGER->findAnimation("BOSS_slapL");
	//}
	//
	//else if (_direction == (int)DIRECTION::RIGHT)
	//{
	//	_bossImg = IMAGEMANAGER->findImage("BOSS_slap");
	//	_bossAnim = KEYANIMANAGER->findAnimation("BOSS_slapR");
	//}
}

attackState::~attackState()
{
}

HRESULT attackState::init()
{
	//_direction = (int)_boss->getBossDirection();

	//_bossImg = IMAGEMANAGER->findImage("BOSS_slap");

	return S_OK;
}

void attackState::release()
{
}
void attackState::update()
{
	bossState::update();

	//_bossImg = IMAGEMANAGER->findImage("BOSS_slap");
}

void attackState::render()
{
	bossState::render();
}

void attackState::stateChange()
{
	//if (getDistance(_boss->getPlayer()->getShadowX(), _boss->getPlayer()->getShadowY(), _boss->getBossShadowX(), _boss->getBossShadowY()) > 80)
	//{
	//	_boss->setMove(false);
	//	_boss->setState(new idleState);
	//}
}

void attackState::anim()
{
	//if (_direction == (int)DIRECTION::LEFT)
	//{
	//	_bossAnim = KEYANIMANAGER->findAnimation("BOSS_slapL");
	//	_bossAnim->resume();
	//}
	//
	//if (_direction == (int)DIRECTION::RIGHT)
	//{
	//	_bossAnim = KEYANIMANAGER->findAnimation("BOSS_slapR");
	//	_bossAnim->resume();
	//}
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