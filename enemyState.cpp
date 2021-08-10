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
	_enemyImg = IMAGEMANAGER->findImage("SCHOOLGIRL_idle");

	return S_OK;
}

void enemyState::release()
{
}

void enemyState::update()
{
	_enemyDir = _enemy->getDir(); 

	callBk();
	enemyAni();
	
	enemyStateChange();

	
}

void enemyState::render()
{
	_enemy->enemyStateRender(_enemyAni);
}

void enemyState::callBk()
{
}

#pragma endregion
//////////////////////////////////////////////  기   본  ///////////////////////////////////////////////////////////
#pragma region 기본 상태

enemyIdle::enemyIdle()
{
	_enemyImg = IMAGEMANAGER->findImage("SCHOOLGIRL_idle");
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
	_enemy->setIsEnemyAttack(false);

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
	if (_enemyDir == (int)ENEMY_LEFT)
	{
		_enemyAni = KEYANIMANAGER->findAnimation("SCHOOLGIRL_idleL");
		_enemyAni->resume();
	}
	if (_enemyDir == (int)ENEMY_RIGHT)
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
	_enemyImg = IMAGEMANAGER->findImage("SCHOOLGIRL_walk");
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
	
	_enemy->setIsEnemyAttack(false);

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
		_enemy->setIsEnemyAttack(false);
		_enemy->setEnemyState(new enemyIdle);
	}
	//RND->getFromIntTo(0,600)
	if (_enemy->getEnemyDistance() < 85)			//플레이어와의 거리가 80보다 작아질시
	{
		_enemy->setEnemySpeed(0.f);
		_enemy->setIsEnemyAttack(true);
		_enemy->setEnemyState(new enemyAttack);
		
	}

	
	
}

void enemyChase::enemyAni()
{
	
	if (_enemyDir == (int)ENEMY_LEFT)
	{
		_enemyAni = KEYANIMANAGER->findAnimation("SCHOOLGIRL_walkL");
		_enemyAni->resume();
	}
	if (_enemyDir == (int)ENEMY_RIGHT)
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
	_EattackIdx = 2;

	if (_EattackIdx == 0)
	{
		_enemyImg = IMAGEMANAGER->findImage("SCHOOLGIRL_comboAttack1");
		
		if (_enemyDir == (int)ENEMY_RIGHT)
		{
			_enemyAni = KEYANIMANAGER->findAnimation("SCHOOLGIRL_comboAttack1R");
		}
		if (_enemyDir == (int)ENEMY_LEFT)
		{
			_enemyAni = KEYANIMANAGER->findAnimation("SCHOOLGIRL_comboAttack1L");
		}
	}
	else if (_EattackIdx == 1)
	{
		_enemyImg = IMAGEMANAGER->findImage("SCHOOLGIRL_comboAttack2");
		if (_enemyDir == (int)ENEMY_RIGHT)
		{
			_enemyAni = KEYANIMANAGER->findAnimation("SCHOOLGIRL_comboAttack2R");
		}
		if (_enemyDir == (int)ENEMY_LEFT)
		{
			_enemyAni = KEYANIMANAGER->findAnimation("SCHOOLGIRL_comboAttack2L");
		}
	}
	else if (_EattackIdx == 2)
	{
		_enemyImg = IMAGEMANAGER->findImage("SCHOOLGIRL_comboAttack3");
		if (_enemyDir == (int)ENEMY_RIGHT)
		{
			_enemyAni = KEYANIMANAGER->findAnimation("SCHOOLGIRL_comboAttack2R");
		}
		if (_enemyDir == (int)ENEMY_LEFT)
		{
			_enemyAni = KEYANIMANAGER->findAnimation("SCHOOLGIRL_comboAttack2L");
		}
	}
}

enemyAttack::~enemyAttack()
{
}

HRESULT enemyAttack::init()
{
	if (_EattackIdx == 0)
	{
		_enemyImg = IMAGEMANAGER->findImage("SCHOOLGIRL_comboAttack1");
		if (_enemyDir == (int)ENEMY_RIGHT)
		{
			_enemyAni = KEYANIMANAGER->findAnimation("SCHOOLGIRL_comboAttack1R");
		}
		if (_enemyDir == (int)ENEMY_LEFT)
		{
			_enemyAni = KEYANIMANAGER->findAnimation("SCHOOLGIRL_comboAttack1L");
		}
	}
	else if (_EattackIdx == 1)
	{
		_enemyImg = IMAGEMANAGER->findImage("SCHOOLGIRL_comboAttack2");
		if (_enemyDir == (int)ENEMY_RIGHT)
		{
			_enemyAni = KEYANIMANAGER->findAnimation("SCHOOLGIRL_comboAttack2R");
		}
		if (_enemyDir == (int)ENEMY_LEFT)
		{
			_enemyAni = KEYANIMANAGER->findAnimation("SCHOOLGIRL_comboAttack2L");
		}
	}
	else if (_EattackIdx == 2)
	{
		_enemyImg = IMAGEMANAGER->findImage("SCHOOLGIRL_comboAttack3");
		if (_enemyDir == (int)ENEMY_RIGHT)
		{
			_enemyAni = KEYANIMANAGER->findAnimation("SCHOOLGIRL_comboAttack2R");
		}
		if (_enemyDir == (int)ENEMY_LEFT)
		{
			_enemyAni = KEYANIMANAGER->findAnimation("SCHOOLGIRL_comboAttack2L");
		}
	}


	return S_OK;
}

void enemyAttack::release()
{
}

void enemyAttack::update()
{
	enemyState::update();

	if (_EattackIdx == 0)
	{
		_enemyImg = IMAGEMANAGER->findImage("SCHOOLGIRL_comboAttack1");
		if (_enemyDir == (int)ENEMY_RIGHT)
		{
			_enemyAni = KEYANIMANAGER->findAnimation("SCHOOLGIRL_comboAttack1R");
		}
		else if (_enemyDir == (int)ENEMY_LEFT)
		{
			_enemyAni = KEYANIMANAGER->findAnimation("SCHOOLGIRL_comboAttack1L");
		}
	}
	else if (_EattackIdx == 1)
	{
		_enemyImg = IMAGEMANAGER->findImage("SCHOOLGIRL_comboAttack2");
		if (_enemyDir == (int)ENEMY_RIGHT)
		{
			_enemyAni = KEYANIMANAGER->findAnimation("SCHOOLGIRL_comboAttack2R");
		}
		else if (_enemyDir == (int)ENEMY_LEFT)
		{
			_enemyAni = KEYANIMANAGER->findAnimation("SCHOOLGIRL_comboAttack2L");
		}
	}
	else if (_EattackIdx == 2)
	{
		_enemyImg = IMAGEMANAGER->findImage("SCHOOLGIRL_comboAttack3");
		if (_enemyDir == (int)ENEMY_RIGHT)
		{
			_enemyAni = KEYANIMANAGER->findAnimation("SCHOOLGIRL_comboAttack3R");
		}
		else if (_enemyDir == (int)ENEMY_LEFT)
		{
			_enemyAni = KEYANIMANAGER->findAnimation("SCHOOLGIRL_comboAttack3L");
		}
	}
	
	//callBk();
	
	//_enemyImg = IMAGEMANAGER->findImage("SCHOOLGIRL_comboAttack3");

	
	
	if(!_enemy->getIsEnemyAttack())						//어택 했을시
	{
		switch (_EattackIdx)							//어택 콤보수
		{	
		case 0:
			_enemy->setIsEnemyAttack(true);
			_enemyImg = IMAGEMANAGER->findImage("SCHOOLGIRL_comboAttack1");
			//_EattackIdx = 1;
			break;
	
		case 1:
			_enemy->setIsEnemyAttack(true);
			_enemyImg = IMAGEMANAGER->findImage("SCHOOLGIRL_comboAttack2");
			//_EattackIdx = 2;
			break;
			
		case 2:
			_enemy->setIsEnemyAttack(true);
			_enemyImg = IMAGEMANAGER->findImage("SCHOOLGIRL_comboAttack3");
			//_EattackIdx = 0;
			break;
		}
	}
}

void enemyAttack::render()
{
	enemyState::render();
}

void enemyAttack::enemyStateChange()
{
	if (_enemy->getEnemyDistance() >= 85 && !_enemy->getIsEnemyAttack())
	{
		_enemy->setIsEnemyAttack(false);
		_enemyAni->stop();
		_enemy->setEnemySpeed(2.f);
		_enemy->setEnemyState(new enemyChase);
	}



}

void enemyAttack::enemyAni()
{



	if (_enemyDir == (int)ENEMY_LEFT)
	{
	
		//if (!_enemyAni->isPlay()) _enemyAni->start();
		//if (_enemyAni->isPlay()) _enemyAni->resume();
		switch (_EattackIdx)
		{
		case 0:
			_enemyAni = KEYANIMANAGER->findAnimation("SCHOOLGIRL_comboAttack1L");
			_enemyAni->resume();
			//_enemy->setIsEnemyAttack(false);
			break;
		
		case 1:
			_enemyAni = KEYANIMANAGER->findAnimation("SCHOOLGIRL_comboAttack2L");
			_enemyAni->resume();
			//_enemy->setIsEnemyAttack(false);
			break;
		
		case 2:
			_enemyAni = KEYANIMANAGER->findAnimation("SCHOOLGIRL_comboAttack3L");
			_enemyAni->resume();
			//_enemy->setIsEnemyAttack(false);
			break;
		
		default:
			_enemyAni = KEYANIMANAGER->findAnimation("SCHOOLGIRL_comboAttack1L");
			_enemyAni->resume();
			break;
		}
		
	}
	if (_enemyDir == (int)ENEMY_RIGHT)
	{
		switch (_EattackIdx)
		{
		case 0:
			_enemyAni = KEYANIMANAGER->findAnimation("SCHOOLGIRL_comboAttack1R");
			_enemyAni->resume();
			break;
	
		case 1:
			_enemyAni = KEYANIMANAGER->findAnimation("SCHOOLGIRL_comboAttack2R");
			_enemyAni->resume();
			break;
	
		case 2:
			_enemyAni = KEYANIMANAGER->findAnimation("SCHOOLGIRL_comboAttack3R");
			_enemyAni->resume();
			break;
	
		default:
			_enemyAni = KEYANIMANAGER->findAnimation("SCHOOLGIRL_comboAttack1R");
			_enemyAni->resume();
			break;
		}

		
	}
	

}
void enemyAttack::callBk()				
{
	if (!_enemyAni->isPlay())						// 어택이 끊길시 idle로 바뀜
	{
		if (_enemy->getIsEnemyAttack())
		{
			_enemyAni->stop();
			if (_EattackIdx < 2) _EattackIdx++;
			else _EattackIdx = 0;
			_enemy->setIsEnemyAttack(false);
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