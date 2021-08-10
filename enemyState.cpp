#include "pch.h"
#include "enemyState.h"
#include "enemy.h"


#pragma region �ʱ�

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
//////////////////////////////////////////////  ��   ��  ///////////////////////////////////////////////////////////
#pragma region �⺻ ����

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
	if (_enemy->getEnemyDistance() <= 400)			//�÷��̾���� �Ÿ��� �۾����� �߰ݻ����̹�����
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
//////////////////////////////////////////////  ��   ��  ///////////////////////////////////////////////////////////
#pragma region �߰� ����

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

	if (_enemy->getEnemyDistance() > 400)			//�÷��̾���� �Ÿ��� Ŀ���� �⺻�����̹�����
	{
		_enemy->setIsEnemyAttack(false);
		_enemy->setEnemyState(new enemyIdle);
	}
	//RND->getFromIntTo(0,600)
	if (_enemy->getEnemyDistance() < 85)			//�÷��̾���� �Ÿ��� 80���� �۾�����
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
//////////////////////////////////////////////	��   ��  ////////////////////////////////////////////////////////////
#pragma region ���� ����
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

	
	
	if(!_enemy->getIsEnemyAttack())						//���� ������
	{
		switch (_EattackIdx)							//���� �޺���
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
	if (!_enemyAni->isPlay())						// ������ ����� idle�� �ٲ�
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
//////////////////////////////////////////////	��   ��  ////////////////////////////////////////////////////////////
#pragma region �ǰ� ����

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
//////////////////////////////////////////////	��   ��  ////////////////////////////////////////////////////////////
#pragma region ���� ����
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
//////////////////////////////////////////////	��   ��  ////////////////////////////////////////////////////////////
#pragma region ���� ����

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
//////////////////////////////////////////////	��   ��  ////////////////////////////////////////////////////////////
#pragma region �������� �Ͼ

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
//////////////////////////////////////////////	��   ��  ////////////////////////////////////////////////////////////
#pragma region ������
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