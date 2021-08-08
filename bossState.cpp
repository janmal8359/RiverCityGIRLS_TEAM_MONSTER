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
	stateChange();
	anim();
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
	if (_player != nullptr)
	{
		if (getDistance(_player->getShadowX(), _player->getShadowY(), _boss->getBossShadowX(), _boss->getBossShadowY()) > 10)
		{
			_boss->setState(new walkState);
		}
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
	float sx = _boss->getBossShadowX();
	float sy = _boss->getBossShadowY();

	sx -= cosf(getAngle(_player->getShadowX(), _player->getShadowY(), _boss->getBossShadowX(), _boss->getBossShadowY()) * 2);
	sy -= -sinf(getAngle(_player->getShadowX(), _player->getShadowY(), _boss->getBossShadowX(), _boss->getBossShadowY()) * 2);

	_boss->setBossShadowX(sx);
	_boss->setBossShadowY(sy);
}

void walkState::render()
{
}

void walkState::stateChange()
{
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