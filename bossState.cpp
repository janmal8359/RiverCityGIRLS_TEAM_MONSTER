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
	_direction = (int)_boss->getBossDirection();

	animOver();
	anim();
	stateChange();
}

void bossState::render()
{
	_direction = (int)_boss->getBossDirection();

	if (_direction == (int)DIRECTION::LEFT) _boss->stateRender(_bossAnimL);
	else if (_direction == (int)DIRECTION::RIGHT) _boss->stateRender(_bossAnimR);

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

void bossState::animOver()
{
}

idleState::idleState()
{
	_bossImg = IMAGEMANAGER->findImage("BOSS_idle");
	_bossAnimL = KEYANIMANAGER->findAnimation("BOSS_idleL");
	_bossAnimR = KEYANIMANAGER->findAnimation("BOSS_idleR");
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

	//_bAttackPattern = 1;
}

void idleState::render()
{
	bossState::render();
}

void idleState::stateChange()
{
	if (TIMEMANAGER->getWorldTime() >= _boss->getTime() + 2)
	{
		_bAttackPattern = RND->getInt(3);
		
		// 임시 키 조작으로 이동
		//if (getDistance(_boss->getPlayer()->getShadowX(), _boss->getPlayer()->getShadowY(), _boss->getBossShadowX(), _boss->getBossShadowY()) > 150)
		//{
			if (_bAttackPattern == 0)
			{
				_boss->setMove(true);
				_boss->setIdle(false);
				_boss->setTime(TIMEMANAGER->getWorldTime());
				_bossAnimL->stop();
				_bossAnimR->stop();
				_boss->setState(new walkState);
			}
			else if (_bAttackPattern == 1)
			{
				_boss->setMove(false);
				_boss->setIsJump(false);
				_boss->setIdle(false);
				_bossAnimL->stop();
				_bossAnimR->stop();
				_boss->setState(new jumpState);
			}
			else if (_bAttackPattern == 2)
			{
				_boss->setMove(true);
				_boss->setDash(false);
				_boss->setIdle(false);
				_bossAnimL->stop();
				_bossAnimR->stop();
				_boss->setState(new dashState);
			}
		//}
		//else if (getDistance(_boss->getPlayer()->getShadowX(), _boss->getPlayer()->getShadowY(), _boss->getBossShadowX(), _boss->getBossShadowY()) <= 150)
		//{
		//	_boss->setMove(false);
		//	_boss->setIsAttack(true);
		//	_bossAnimL->stop();
		//	_bossAnimR->stop();
		//	_boss->setState(new attackState);
		//}
	}
}

void idleState::anim()
{
	if (_direction == (int)DIRECTION::LEFT)
	{
		_bossAnimL->resume();
	}

	else if (_direction == (int)DIRECTION::RIGHT)
	{
		_bossAnimR->resume();
	}
	
	_isStart = true;
}

walkState::walkState()
{
	_bossImg = IMAGEMANAGER->findImage("BOSS_walk");
	_bossAnimL = KEYANIMANAGER->findAnimation("BOSS_walkL");
	_bossAnimR = KEYANIMANAGER->findAnimation("BOSS_walkR");
}

walkState::~walkState()
{
}

// Walk
HRESULT walkState::init()
{
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
	bossState::render();
}

void walkState::stateChange()
{
	//if (getDistance(_boss->getPlayer()->getShadowX(), _boss->getPlayer()->getShadowY(), _boss->getBossShadowX(), _boss->getBossShadowY()) <= 50)
	//{
	//	_boss->setMove(false);
	//	_boss->setState(new idleState);
	//}

	if (getDistance(_boss->getPlayer()->getShadowX(), _boss->getPlayer()->getShadowY(), _boss->getBossShadowX(), _boss->getBossShadowY()) <= 150)
	{
		_boss->setMove(false);
		_boss->setIsAttack(true);
		_bossAnimL->stop();
		_bossAnimR->stop();
		_boss->setState(new attackState);
	}
	else if (TIMEMANAGER->getWorldTime() >= _boss->getTime() + 4)
	{
		_boss->setMove(false);
		_boss->setIdle(true);
		_boss->setTime(TIMEMANAGER->getWorldTime());
		_bossAnimL->stop();
		_bossAnimR->stop();
		_boss->setState(new idleState);
	}
}

void walkState::anim()
{
	if (_direction == (int)DIRECTION::LEFT)
	{
		_bossAnimL->resume();
	}

	if (_direction == (int)DIRECTION::RIGHT)
	{
		_bossAnimR->resume();
	}

	_isStart = true;
}


// Attack

attackState::attackState()
{
	_bossImg = IMAGEMANAGER->findImage("BOSS_slap");
	_bossAnimL = KEYANIMANAGER->findAnimation("BOSS_slapL");
	_bossAnimR = KEYANIMANAGER->findAnimation("BOSS_slapR");
}

attackState::~attackState()
{
}

HRESULT attackState::init()
{
	_bossImg = IMAGEMANAGER->findImage("BOSS_slap");

	return S_OK;
}

void attackState::release()
{
}

void attackState::update()
{
	bossState::update();

	_bossImg = IMAGEMANAGER->findImage("BOSS_slap");

	//animOver();
}

void attackState::render()
{
	bossState::render();
}

void attackState::stateChange()
{
	if (getDistance(_boss->getPlayer()->getShadowX(), _boss->getPlayer()->getShadowY(), _boss->getBossShadowX(), _boss->getBossShadowY()) > 150 &&
		_boss->getIsAttack() == false)
	{
		_boss->setMove(false);
		_boss->setIsAttack(false);
		_boss->setIdle(true);
		_bossAnimL->stop();
		_bossAnimR->stop();
		_boss->setState(new idleState);
	}
}

void attackState::anim()
{
	if (_direction == (int)DIRECTION::LEFT)
	{
		if (!_bossAnimL->isPlay())
		{
			_bossAnimL->start();
		}
		if (_bossAnimL->isPlay())
		{
			_bossAnimL->resume();
		}
	}

	if (_direction == (int)DIRECTION::RIGHT)
	{
		if (!_bossAnimR->isPlay())
		{
			_bossAnimR->start();
		}
		if (_bossAnimR->isPlay())
		{
			_bossAnimR->resume();
		}
	}

	_isStart = true;
}

void attackState::animOver()
{
	if (!_bossAnimL->isPlay() && !_bossAnimR->isPlay() && _isStart)
	{
		_isStart = false;
		_bossAnimL->stop();
		_bossAnimR->stop();
		_boss->setTime(TIMEMANAGER->getWorldTime());
		_boss->setIsAttack(false);
		_boss->setMove(false);
		_boss->setIdle(true);
		_boss->setState(new idleState);
	}
}


// JumpAttack
jumpState::jumpState()
{
	_bossImg = IMAGEMANAGER->findImage("BOSS_meteor_J");
	_bossAnimL = KEYANIMANAGER->findAnimation("BOSS_jumpL");
	_bossAnimR = KEYANIMANAGER->findAnimation("BOSS_jumpR");
}

jumpState::~jumpState()
{
}

HRESULT jumpState::init()
{
	if (!_boss->getIsDrop())
	{
		_bossImg = IMAGEMANAGER->findImage("BOSS_meteor_J");
		_bossAnimL = KEYANIMANAGER->findAnimation("BOSS_jumpL");
		_bossAnimR = KEYANIMANAGER->findAnimation("BOSS_jumpR");
	}
	else if (_boss->getIsDrop())
	{
		_bossImg = IMAGEMANAGER->findImage("BOSS_meteor");
		_bossAnimL = KEYANIMANAGER->findAnimation("BOSS_dropL");
		_bossAnimR = KEYANIMANAGER->findAnimation("BOSS_dropR");
	}

	return S_OK;
}

void jumpState::release()
{
}

void jumpState::update()
{
	bossState::update();

	if (!_boss->getIsDrop())
	{
		_bossImg = IMAGEMANAGER->findImage("BOSS_meteor_J");
		_bossAnimL = KEYANIMANAGER->findAnimation("BOSS_jumpL");
		_bossAnimR = KEYANIMANAGER->findAnimation("BOSS_jumpR");
	}
	else if (_boss->getIsDrop())
	{
		_bossImg = IMAGEMANAGER->findImage("BOSS_meteor");
		_bossAnimL = KEYANIMANAGER->findAnimation("BOSS_dropL");
		_bossAnimR = KEYANIMANAGER->findAnimation("BOSS_dropR");
	}

	//animOver();
}

void jumpState::render()
{
	bossState::render();
}

void jumpState::stateChange()
{
}

void jumpState::anim()
{
	if (!_boss->getIsDrop())
	{
		if (_direction == (int)DIRECTION::LEFT)
		{
			if (!_bossAnimL->isPlay())
			{
				_bossAnimL->stop();
				_bossAnimL->start();
			}
			if (_bossAnimL->isPlay())
			{
				if (_bossAnimL->getFramePos().x == 0) _bossAnimL->pause();
				else _bossAnimL->resume();
			}
		}

		if (_direction == (int)DIRECTION::RIGHT)
		{
			if (!_bossAnimR->isPlay())
			{
				_bossAnimR->stop();
				_bossAnimR->start();
			}
			if (_bossAnimR->isPlay())
			{
				if (_bossAnimR->getFramePos().x == 0) _bossAnimR->pause();
				else _bossAnimR->resume();
			}
		}

		if (!_boss->getIsJump() && (_bossAnimL->getFramePos().x <= 1 || _bossAnimR->getFramePos().x <= 1) &&
			(!_boss->getMove() || !_boss->getFloat()) && !_boss->getIdle())
		{
			_boss->setIsJump(true);
			//_isStart = true;
		}

		if (_boss->getMove() && TIMEMANAGER->getWorldTime() >= _boss->getTime() + 3) _isStart = true;
		else if (_boss->getIsJump() && _boss->getJumpPower() >= 800 && !_boss->getMove() && !_boss->getFloat()) _isStart = true;
	}

	if (_boss->getIsDrop())
	{
		if (_direction == (int)DIRECTION::LEFT)
		{
			if (!_bossAnimL->isPlay())
			{
				_bossAnimL->start();
			}
			if (_bossAnimL->isPlay())
			{
				_bossAnimL->resume();
			}
		}

		if (_direction == (int)DIRECTION::RIGHT)
		{
			if (!_bossAnimR->isPlay())
			{
				_bossAnimR->start();
			}
			if (_bossAnimR->isPlay())
			{
				_bossAnimR->resume();
			}
		}

		if (_boss->getJumpPower() <= 0)
		{
			_bossAnimL->stop();
			_bossAnimR->stop();
			_isStart = true;
		}
	}
}

void jumpState::animOver()
{
	// 공중에 떠있을 때
	if (!_bossAnimL->isPlay() && !_bossAnimR->isPlay() && _isStart && _boss->getIsJump())
	{
		_isStart = false;
		_bossAnimL->stop();
		_bossAnimR->stop();
		_boss->setTime(TIMEMANAGER->getWorldTime());
		_boss->setIsAttack(false);
		_boss->setIsJump(false);
		_boss->setMove(true);
		_boss->setFloat(true);
		_boss->setState(new jumpState);
	}
	// 떨어질 때
	else if (!_bossAnimL->isPlay() && !_bossAnimR->isPlay() && _isStart && _boss->getMove())
	{
		_isStart = false;
		_bossAnimL->stop();
		_bossAnimR->stop();
		_boss->setIsAttack(false);
		_boss->setIsJump(false);
		_boss->setMove(false);
		_boss->setIsDrop(true);
		_boss->setFloat(false);
		_boss->setState(new jumpState);
	}
	// 떨어지고 평상시로 돌아갈 때
	else if (!_bossAnimL->isPlay() && !_bossAnimR->isPlay() && _isStart && _boss->getIsDrop())
	{
		_isStart = false;
		_bossAnimL->stop();
		_bossAnimR->stop();
		_boss->setTime(TIMEMANAGER->getWorldTime());
		_boss->setIsAttack(false);
		_boss->setIsJump(false);
		_boss->setMove(false);
		_boss->setIsDrop(false);
		_boss->setFloat(false);
		_boss->setIdle(true);
		_boss->setState(new idleState);
	}
}

// dash
dashState::dashState()
{
		_bossImg = IMAGEMANAGER->findImage("BOSS_dash");
		_bossAnimL = KEYANIMANAGER->findAnimation("BOSS_dashStartL");
		_bossAnimR = KEYANIMANAGER->findAnimation("BOSS_dashStartR");
}

dashState::~dashState()
{

}

HRESULT dashState::init()
{
	if (!_boss->getDash())
	{
		_bossImg = IMAGEMANAGER->findImage("BOSS_dash");
		_bossAnimL = KEYANIMANAGER->findAnimation("BOSS_dashStartL");
		_bossAnimR = KEYANIMANAGER->findAnimation("BOSS_dashStartR");
	}
	else if (_boss->getDash())
	{
		_bossImg = IMAGEMANAGER->findImage("BOSS_dash");
		_bossAnimL = KEYANIMANAGER->findAnimation("BOSS_dashL");
		_bossAnimR = KEYANIMANAGER->findAnimation("BOSS_dashR");
	}

	return S_OK;
}

void dashState::release()
{
}

void dashState::update()
{
	bossState::update();

	if (!_boss->getDash())
	{
		_bossImg = IMAGEMANAGER->findImage("BOSS_dash");
		_bossAnimL = KEYANIMANAGER->findAnimation("BOSS_dashStartL");
		_bossAnimR = KEYANIMANAGER->findAnimation("BOSS_dashStartR");
	}
	else if (_boss->getDash())
	{
		_bossImg = IMAGEMANAGER->findImage("BOSS_dash");
		_bossAnimL = KEYANIMANAGER->findAnimation("BOSS_dashL");
		_bossAnimR = KEYANIMANAGER->findAnimation("BOSS_dashR");
	}
}

void dashState::render()
{
	bossState::render();
}

void dashState::stateChange()
{
	if (getDistance(_boss->getPlayer()->getShadowX(), _boss->getPlayer()->getShadowY(), _boss->getBossShadowX(), _boss->getBossShadowY()) <= 50 ||
		TIMEMANAGER->getWorldTime() >= _boss->getTime() + 5)
	{
		_boss->setMove(false);
		_boss->setDash(false);
		_boss->setTime(TIMEMANAGER->getWorldTime());
		_bossAnimL->stop();
		_bossAnimR->stop();
		_boss->setState(new idleState);
	}
}

void dashState::anim()
{
	if (_direction == (int)DIRECTION::LEFT)
	{
		if (!_bossAnimL->isPlay())
		{
			_bossAnimL->start();
		}
		if (_bossAnimL->isPlay())
		{
			_bossAnimL->resume();
		}
	}

	if (_direction == (int)DIRECTION::RIGHT)
	{
		if (!_bossAnimR->isPlay())
		{
			_bossAnimR->start();
		}
		if (_bossAnimR->isPlay())
		{
			_bossAnimR->resume();
		}
	}

	_isStart = true;
}

void dashState::animOver()
{
	if (!_bossAnimL->isPlay() && !_bossAnimR->isPlay() && _isStart)
	{
		_isStart = false;
		_bossAnimL->stop();
		_bossAnimR->stop();
		_boss->setTime(TIMEMANAGER->getWorldTime());
		_boss->setMove(true);
		_boss->setDash(true);
		_boss->setState(new dashState);
	}
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