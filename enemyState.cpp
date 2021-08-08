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


}

void enemyState::render()
{
	_enemy->enemyStateRender(_enemyAni);
}

#pragma endregion
//////////////////////////////////////////////  기   본  ///////////////////////////////////////////////////////////
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
	if (_enemy->getEnemyDistance() < 500)
	{
		_enemy->setEnemyState(new enemyChase);
	}
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
//////////////////////////////////////////////  추   격  ///////////////////////////////////////////////////////////
#pragma region 추격 상태

enemyChase::enemyChase()
{
}

enemyChase::~enemyChase()
{
}

HRESULT enemyChase::init()
{
	
	//_enemyImg = IMAGEMANAGER->findImage("SCHOOLGIRL_run");
	_enemyImg = IMAGEMANAGER->findImage("SCHOOLGIRL_walk");
	return S_OK;
}

void enemyChase::release()
{
}

void enemyChase::update()
{
	enemyState::update();
	
	//_enemyImg = IMAGEMANAGER->findImage("SCHOOLGIRL_run");
	_enemyImg = IMAGEMANAGER->findImage("SCHOOLGIRL_walk");

}

void enemyChase::render()
{
	enemyState::render();
}

void enemyChase::enemyStateChange()
{
	if (_enemy->getEnemyDistance() >= 500)
	{
		_enemy->setEnemyState(new enemyIdle);
	}
	
}

void enemyChase::enemyAni()
{
	if (_enemy->getEnemyDistance() < 500)
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
	//else if (_enemy->getEnemyDistance() <= 200)
	//{
	//	if (_enemyDir == ENEMY_LEFT)
	//	{
	//		_enemyAni = KEYANIMANAGER->findAnimation("SCHOOLGIRL_runL");
	//		_enemyAni->resume();
	//	}
	//	if (_enemyDir == ENEMY_RIGHT)
	//	{
	//		_enemyAni = KEYANIMANAGER->findAnimation("SCHOOLGIRL_runR");
	//		_enemyAni->resume();
	//	}
	//}
}

#pragma endregion
//////////////////////////////////////////////	공   격  ////////////////////////////////////////////////////////////
#pragma region 공격 상태


enemyAttack::enemyAttack()
{
}

enemyAttack::~enemyAttack()
{
}

HRESULT enemyAttack::init()
{
	return S_OK;
}

void enemyAttack::release()
{
}

void enemyAttack::update()
{
}

void enemyAttack::render()
{
}

void enemyAttack::enemyStateChange()
{
}

void enemyAttack::enemyAni()
{
}

#pragma endregion
//////////////////////////////////////////////	피   격  ////////////////////////////////////////////////////////////
#pragma region 피격 상태

enemyHurt::enemyHurt()
{
}

enemyHurt::~enemyHurt()
{
}

HRESULT enemyHurt::init()
{
	return S_OK;
}

void enemyHurt::release()
{
}

void enemyHurt::update()
{
}

void enemyHurt::render()
{
}

void enemyHurt::enemyStateChange()
{
}

void enemyHurt::enemyAni()
{
}
#pragma endregion