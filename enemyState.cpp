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
	if (_enemy->getEnemyDistance() <= 400)			//플레이어과의 거리가 작아질시 추격상태이미지로
	{
		_enemy->setEnemyState(new enemyChase);
	}
	if (_enemy->getIsEenmyJump())
	{
		_enemy->setEnemyState(new enemyJump);
		_enemy->setEnemyJumpPower(20.0f);
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

	if (_enemy->getEnemyDistance() > 400)			//플레이어과의 거리가 커질시 기본상태이미지로
	{
		_enemy->setEnemyState(new enemyIdle);
	}

	if (_enemy->getEnemyDistance() < 85)			//플레이어와의 거리가 80보다 작아질시
	{
		_enemy->setEnemyState(new enemyAttack);
		
	}

	
	
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
	enemyState::update();
	
	
	callBk();
	
	_enemyImg = IMAGEMANAGER->findImage("SCHOOLGIRL_comboAttack2");

	

	
	//if(!_enemy->getIsEenmyAttack())
	//{
	//	
	//	switch (_EattackIdx)
	//	{
	//	case 0:
	//		_enemyImg = IMAGEMANAGER->findImage("SCHOOLGIRL_comboAttack1");
	//		break;
	//
	//	case 1:
	//		_enemyImg = IMAGEMANAGER->findImage("SCHOOLGIRL_comboAttack2");
	//		break;
	//
	//	case 2:
	//		_enemyImg = IMAGEMANAGER->findImage("SCHOOLGIRL_comboAttack3");
	//		break;
	//	}
	//
	//}

	//callBk();
}

void enemyAttack::render()
{
	enemyState::render();
}

void enemyAttack::enemyStateChange()
{
	if (_enemy->getEnemyDistance() >= 85)
	{
		_enemyAni->stop();
		_enemy->setEnemyState(new enemyChase);
	}



}

void enemyAttack::enemyAni()
{

	if(_enemy->getIsEenmyAttack())
	{
		if (_enemyDir == ENEMY_LEFT)
		{
			_enemyAni = KEYANIMANAGER->findAnimation("SCHOOLGIRL_comboAttack2L");
			_enemyAni->resume();
		}
		if (_enemyDir == ENEMY_RIGHT)
		{
			_enemyAni = KEYANIMANAGER->findAnimation("SCHOOLGIRL_comboAttack2R");
			_enemyAni->resume();
		}
	}
	//_enemyAni->resume();
	//if (_enemyDir == ENEMY_LEFT)
	//{
	//	switch (_EattackIdx)
	//	{
	//	case 0:
	//		_enemyAni = KEYANIMANAGER->findAnimation("SCHOOLGIRL_comboAttack1L");
	//		break;
	//
	//	case 1:
	//		_enemyAni = KEYANIMANAGER->findAnimation("SCHOOLGIRL_comboAttack2L");
	//		break;
	//
	//	case 2:
	//		_enemyAni = KEYANIMANAGER->findAnimation("SCHOOLGIRL_comboAttack3L");
	//		break;
	//
	//	default:
	//		_enemyAni = KEYANIMANAGER->findAnimation("SCHOOLGIRL_comboAttack1L");
	//		break;
	//	}
	//}
	//if (_enemyDir == ENEMY_RIGHT)
	//{
	//	switch (_EattackIdx)
	//	{
	//	case 0:
	//		_enemyAni = KEYANIMANAGER->findAnimation("SCHOOLGIRL_comboAttack1R");
	//		break;
	//
	//	case 1:
	//		_enemyAni = KEYANIMANAGER->findAnimation("SCHOOLGIRL_comboAttack2R");
	//		break;
	//
	//	case 2:
	//		_enemyAni = KEYANIMANAGER->findAnimation("SCHOOLGIRL_comboAttack3R");
	//		break;
	//
	//	default:
	//		_enemyAni = KEYANIMANAGER->findAnimation("SCHOOLGIRL_comboAttack1L");
	//		break;
	//	}
	//}
	

}
void enemyAttack::callBk()				
{
	if (!_enemyAni->isPlay())		// 어택이 끊길시 chase로 바뀜
	{
		if (_enemy->getIsEenmyAttack())
		{
			_enemyAni->stop();
			_enemy->setEnemyState(new enemyIdle);
			_enemy->update();
		}
	}
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
//////////////////////////////////////////////	점   프  ////////////////////////////////////////////////////////////
#pragma region 점프 상태
enemyJump::enemyJump()
{
}

enemyJump::~enemyJump()
{
}

HRESULT enemyJump::init()
{
	return S_OK;
}

void enemyJump::release()
{
}

void enemyJump::update()
{

	enemyState::update();
	_enemyImg = IMAGEMANAGER->findImage("SCHOOLGIRL_jump");
}

void enemyJump::render()
{
	enemyState::render();
}

void enemyJump::enemyStateChange()
{
	if (_enemy->getEnemyDistance() < 400)
	{
		_enemy->setEnemyState(new enemyChase);
	}
}

void enemyJump::enemyAni()
{
	_enemy->setEnemySpeed(3.0f);

	if (_enemyDir == ENEMY_LEFT)
	{
		_enemyAni = KEYANIMANAGER->findAnimation("SCHOOLGIRL_jumpL");
		_enemyAni->resume();
	}
	if (_enemyDir == ENEMY_RIGHT)
	{
		_enemyAni = KEYANIMANAGER->findAnimation("SCHOOLGIRL_jumpR");
		_enemyAni->resume();
	}
}

#pragma endregion
//////////////////////////////////////////////	죽   음  ////////////////////////////////////////////////////////////
#pragma region 죽음 상태

enemyDie::enemyDie()
{
}

enemyDie::~enemyDie()
{
}

HRESULT enemyDie::init()
{
	return S_OK;
}

void enemyDie::release()
{
}

void enemyDie::update()
{
}

void enemyDie::render()
{
}

void enemyDie::enemyStateChange()
{
}

void enemyDie::enemyAni()
{
}


#pragma endregion
//////////////////////////////////////////////	누   움  ////////////////////////////////////////////////////////////
#pragma region 쓰러졌다 일어남

enemybackdown::enemybackdown()
{
}

enemybackdown::~enemybackdown()
{
}

HRESULT enemybackdown::init()
{
	return S_OK;
}

void enemybackdown::release()
{
}

void enemybackdown::update()
{
}

void enemybackdown::render()
{
}

void enemybackdown::enemyStateChange()
{
}

void enemybackdown::enemyAni()
{
}
#pragma endregion
//////////////////////////////////////////////	잡   힘  ////////////////////////////////////////////////////////////
#pragma region 붙잡힘
enemyheld::enemyheld()
{
}

enemyheld::~enemyheld()
{
}

HRESULT enemyheld::init()
{
	return S_OK;
}

void enemyheld::release()
{
}

void enemyheld::update()
{
}

void enemyheld::render()
{
}

void enemyheld::enemyStateChange()
{
}

void enemyheld::enemyAni()
{
}

#pragma endregion