#include "pch.h"
#include "enemyState.h"
#include "enemy.h"


#pragma region 초기

enemyState::enemyState()
{
}

enemyState::~enemyState()
{
}

HRESULT enemyState::init()
{
	return S_OK;
}

void enemyState::release()
{
}

void enemyState::update()
{
	_enemyDir = _enemy->getDir();

	enemyStateChange();
	enemyAni();

	KEYANIMANAGER->update();


}

void enemyState::render()
{
	_enemy->enemyStateRender(_enemyAni);
}

#pragma endregion

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma region 기본 상태

enemyIdle::enemyIdle()
{
}

enemyIdle::~enemyIdle()
{
}

HRESULT enemyIdle::init()
{
	enemyState::init();

	_enemyImg = IMAGEMANAGER->findImage("SCHOOLGIRL_idle");
	
	return S_OK;
}

void enemyIdle::release()
{
}

void enemyIdle::update()
{
	enemyState::update();
	_enemyImg = IMAGEMANAGER->findImage("SCHOOLGIRL_idle");
}

void enemyIdle::render()
{
	enemyState::render();
}

void enemyIdle::enemyStateChange()
{
	if (_enemy->getESpeed() > 0) _enemy->setEnemyState(new enemyChase);
}

void enemyIdle::enemyAni()
{
	if (_enemyDir == ENEMY_LEFT)
	{
		_enemyAni = KEYANIMANAGER->findAnimation("SCHOOLGIRL_idleL");
		_enemyAni->resume();
	}
	if (_enemyDir == ENEMY_RIGHT)
	{
		_enemyAni = KEYANIMANAGER->findAnimation("SCHOOLGIRL_idleR");
		_enemyAni->resume();
	}
}

#pragma endregion
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma region 추격 상태

enemyChase::enemyChase()
{
}

enemyChase::~enemyChase()
{
}

HRESULT enemyChase::init()
{
	_enemyImg = IMAGEMANAGER->findImage("SCHOOLGIRL_walk");

	return S_OK;
}

void enemyChase::release()
{
}

void enemyChase::update()
{
	enemyState::update();
	_enemyImg = IMAGEMANAGER->findImage("SCHOOLGIRL_walk");

	if (KEYMANAGER->isOnceKeyDown(VK_RETURN))
	{
		_enemy->setESpeed(0);
	}
}

void enemyChase::render()
{
	enemyState::render();
}

void enemyChase::enemyStateChange()
{
	if (_enemy->getESpeed() == 0) _enemy->setEnemyState(new enemyIdle);
}

void enemyChase::enemyAni()
{
	if (_enemyDir == ENEMY_LEFT)
	{
		_enemyAni = KEYANIMANAGER->findAnimation("SCHOOLGIRL_walkL");
		_enemyAni->resume();
	}
	if (_enemyDir == ENEMY_RIGHT)
	{
		_enemyAni = KEYANIMANAGER->findAnimation("SCHOOLGIRL_walkR");
		_enemyAni->resume();
	}
}

#pragma endregion