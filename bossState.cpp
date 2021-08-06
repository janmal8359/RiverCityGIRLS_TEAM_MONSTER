#include "pch.h"
#include "bossState.h"
#include "boss.h"


HRESULT bossState::init()
{
	return S_OK;
}

void bossState::release()
{
}

void bossState::update()
{
	stateChange();
	anim();


	KEYANIMANAGER->update();
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


// Idle
HRESULT idleState::init()
{
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
	bossState::render();
	//_bossImg->frameRender(getMemDC(), _boss->getBossRectX(), _boss->getBossRectY());

}

void idleState::stateChange()
{
	// 임시 키 조작으로 이동
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


// Walk
HRESULT walkState::init()
{
	return S_OK;
}

void walkState::release()
{
}

void walkState::update()
{
}

void walkState::render()
{
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
}

void attackState::render()
{
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
}

void jumpState::render()
{
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
}

void sitState::render()
{
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
}

void groggyState::render()
{
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
}

void loseState::render()
{
}