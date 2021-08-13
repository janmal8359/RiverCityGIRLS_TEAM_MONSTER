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
	_enemyAni = KEYANIMANAGER->findAnimation("SCHOOLGIRL_idleL");
	_enemyAni = KEYANIMANAGER->findAnimation("SCHOOLGIRL_idleR");
	return S_OK;
}

void enemyIdle::release()
{
}

void enemyIdle::update()
{
	enemyState::update();

	_enemy->setIsEnemyAttack(false);					//�⺻ ���¶� ������ ����
	_enemy->setIsEnemyChase(false);						//�⺻ ���¶� ������ ����
	_enemy->setIsEnemyWaitAttack(false);				//�ٰ����� �����ϱ��� ���
	_enemy->setIsEnemyHurt(false);						//�⺻ ���¶� ���� ����
	_enemy->setIsEnemyIdle(true);						//�⺻ ���¶� �⺻��
	_enemy->setEnemyCount(_enemy->getEnemyCount() + 1);	//�⺻ ���¿� ���� ī��Ʈ�� �ö�
	_enemy->setEnemySpeed(0);							//�⺻ ���¶� �ӵ��� 0
	_enemy->setIsEnemyRun(false);
	
	_enemyImg = IMAGEMANAGER->findImage("SCHOOLGIRL_idle");

}

void enemyIdle::render()
{

	enemyState::render();
}

void enemyIdle::enemyStateChange()
{	

	//CHASE���·� �ٲ۴�
	if (_enemyDir == ENEMY_LEFT)
	{
		if (_enemy->getEnemyDistance() < 600 && _enemy->getIsEenmyChase() && _enemy->getIsEnemyIdle())			//�÷��̾���� �Ÿ��� �۾����� �߰ݻ����̹�����
		{
			_enemy->setEnemyState(new enemyChase);
		}
	}
	if (_enemyDir == ENEMY_RIGHT)
	{
		if (_enemy->getEnemyDistanceR() < 600 && _enemy->getIsEenmyChase() && _enemy->getIsEnemyIdle())			//�÷��̾���� �Ÿ��� �۾����� �߰ݻ����̹�����
		{
			_enemy->setEnemyState(new enemyChase);
		}
	}
	//�޸��� 
	if (_enemyDir == ENEMY_LEFT)
	{
		if (_enemy->getEnemyDistance() < 790 && !_enemy->getIsEenmyChase() &&_enemy->getIsEnemyIdle())
		{
			_enemy->setEnemyState(new enemyRun);
		}
	}
	if (_enemyDir == ENEMY_RIGHT)
	{
		if (_enemy->getEnemyDistanceR() < 790)
		{
			_enemy->setEnemyState(new enemyRun);
		}
	}


	//���ݻ��·�
	if (_enemyDir == ENEMY_LEFT)
	{
		if (_enemy->getEnemyDistance() < 10 && !_enemy->getIsEenmyChase() && !_enemy->getIsEnemyAttack() && !_enemy->getIsEnemyIdle() && _enemy->getIsEnemyWaitAttack() && _enemy->getEnemyCount() > 100)
		{
			_enemy->setEnemyState(new enemyAttack);
			
		}
	}
	if (_enemyDir == ENEMY_RIGHT)
	{
		if (_enemy->getEnemyDistanceR() < 10 && !_enemy->getIsEenmyChase() && !_enemy->getIsEnemyAttack() && !_enemy->getIsEnemyIdle() && _enemy->getIsEnemyWaitAttack() && _enemy->getEnemyCount() > 100)
		{
			_enemy->setEnemyState(new enemyAttack);
	
		}
	}
	//�ǰݽ�
	if (_enemyDir == ENEMY_LEFT)
	{
		if (_enemy->getIsEnemyHurt())
		{
			_enemy->setEnemyState(new enemyHurt);

		}
	}

	if (_enemyDir == ENEMY_RIGHT)
	{
		if (_enemy->getIsEnemyHurt())
		{
			_enemy->setEnemyState(new enemyHurt);

		}
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
	_enemyImg = IMAGEMANAGER->findImage("SCHOOLGIRL_walk");
	_enemyAni = KEYANIMANAGER->findAnimation("SCHOOLGIRL_walkL");
	_enemyAni = KEYANIMANAGER->findAnimation("SCHOOLGIRL_walkR");
	return S_OK;
}

void enemyChase::release()
{
}

void enemyChase::update()
{
	enemyState::update();


	_enemy->setEnemyCount(_enemy->getEnemyCount() + 1);
	
	_enemy->setEnemySpeed(3.f);
	_enemy->setIsEnemyAttack(false);
	_enemy->setIsEnemyWaitAttack(false);
	_enemy->setIsEnemyIdle(false);
	_enemy->setIsEnemyHurt(false);
	_enemy->setIsEnemyChase(true);
	_enemy->setIsEnemyRun(false);


	_enemyImg = IMAGEMANAGER->findImage("SCHOOLGIRL_walk");

}

void enemyChase::render()
{
	enemyState::render();
}

void enemyChase::enemyStateChange()
{
	
		if (_enemyDir == ENEMY_LEFT)
		{
			if (_enemy->getEnemyDistance() > 800 && !_enemy->getIsEnemyAttack() && _enemy->getIsEenmyChase())			//�÷��̾���� �Ÿ��� Ŀ���� �⺻�����̹�����
			{
				_enemy->setIsEnemyAttack(false);
				_enemy->setEnemyState(new enemyIdle);
			}
		}
		if (_enemyDir == ENEMY_RIGHT)
		{
			if (_enemy->getEnemyDistanceR() > 800 && !_enemy->getIsEnemyAttack() && _enemy->getIsEenmyChase())			//�÷��̾���� �Ÿ��� Ŀ���� �⺻�����̹�����
			{
				_enemy->setIsEnemyAttack(false);
				_enemy->setEnemyState(new enemyIdle);
			}
		}
		
		
		if (_enemyDir == ENEMY_LEFT)
		{
			if (_enemy->getEnemyDistance() < 10 && !_enemy->getIsEnemyAttack() && _enemy->getIsEenmyChase())
			{	
				_enemy->setEnemyState(new enemyWaitAttack);
				
			}
		}
		if (_enemyDir == ENEMY_RIGHT)
		{
			if (_enemy->getEnemyDistanceR() < 10 && !_enemy->getIsEnemyAttack() && _enemy->getIsEenmyChase())			//�÷��̾���� �Ÿ��� 10���� �۾�����
			{
				_enemy->setEnemyState(new enemyWaitAttack);
			}
		}
		
		//�ǰݽ�
		
		if (_enemyDir == ENEMY_LEFT && _enemy->getEnemyDistance() < 10)
		{
			if (_enemy->getIsEnemyHurt())
			{
				_enemy->setEnemyState(new enemyHurt);

			}
		}

		if (_enemyDir == ENEMY_RIGHT && _enemy->getEnemyDistanceR() < 10)
		{
			if (_enemy->getIsEnemyHurt())
			{
				_enemy->setEnemyState(new enemyHurt);

			}
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

}

#pragma endregion
//////////////////////////////////////////////	��   ��  ////////////////////////////////////////////////////////////
#pragma region ���� ����
enemyAttack::enemyAttack()
{
	_EattackIdx = 0;

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
		_enemyImg = IMAGEMANAGER->findImage
		("SCHOOLGIRL_comboAttack1");
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
	
	_enemy->setEnemySpeed(0);
	_enemy->setIsEnemyRun(false);
	_enemy->setIsEnemyIdle(false);
	_enemy->setIsEnemyChase(false);
	_enemy->setIsEnemyWaitAttack(false);
	_enemy->setIsEnemyAttack(true);


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
			_enemyAni = KEYANIMANAGER->findAnimation("SCHOOLGIRL_comboAttack3R");
		}
		if (_enemyDir == (int)ENEMY_LEFT)
		{
			_enemyAni = KEYANIMANAGER->findAnimation("SCHOOLGIRL_comboAttack3L");
		}
	}
	
	if(!_enemy->getIsEnemyAttack())						//���� ������
	{
		switch (_EattackIdx)							//���� �޺���
		{	
		
		case 0:
			_enemy->setIsEnemyAttack(true);
			_enemyImg = IMAGEMANAGER->findImage("SCHOOLGIRL_comboAttack1");
			
			break;
	
		case 1:
			_enemy->setIsEnemyAttack(true);
			_enemyImg = IMAGEMANAGER->findImage("SCHOOLGIRL_comboAttack2");
			
			break;
			
		case 2:
			_enemy->setIsEnemyAttack(true);
			_enemyImg = IMAGEMANAGER->findImage("SCHOOLGIRL_comboAttack3");
			
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
	if (_enemyDir == ENEMY_LEFT)
	{
		if (_enemy->getEnemyDistance() >= 10 && !_enemy->getIsEnemyAttack() && !_enemy->getIsEenmyChase())
		{
			_enemy->setIsEnemyAttack(false);
			_enemyAni->stop();
			_enemy->setEnemySpeed(2.f);
			_enemy->setEnemyState(new enemyChase);
		}
	}
	if (_enemyDir == ENEMY_RIGHT)
	{
		if (_enemy->getEnemyDistanceR() >= 10 && !_enemy->getIsEnemyAttack() && !_enemy->getIsEenmyChase())
		{
			_enemy->setIsEnemyAttack(false);
			_enemyAni->stop();
			_enemy->setEnemySpeed(2.f);
			_enemy->setEnemyState(new enemyChase);
		}
	}

	if (_enemyDir == ENEMY_LEFT)
	{
		if (_enemy->getEnemyDistance() < 10 && _enemy->getIsEnemyAttack() && _EattackIdx >3)
		{
			_enemy->setIsEnemyAttack(false);
			_enemy->setEnemyState(new enemyIdle);
	
		}
	}
	
	if (_enemyDir == ENEMY_RIGHT)
	{
		if (_enemy->getEnemyDistanceR() < 10 && _enemy->getIsEnemyAttack()&& _EattackIdx >3)
		{
			_enemy->setIsEnemyAttack(false);
			_enemy->setEnemyState(new enemyIdle);
	
		}
	}

	//�ǰݽ�
	if (_enemyDir == ENEMY_LEFT)
	{
		if (_enemy->getIsEnemyHurt())
		{
			_enemy->setEnemyState(new enemyHurt);

		}
	}

	if (_enemyDir == ENEMY_RIGHT)
	{
		if (_enemy->getIsEnemyHurt())
		{
			_enemy->setEnemyState(new enemyHurt);

		}
	}
}

void enemyAttack::enemyAni()
{
	if (_enemyDir == (int)ENEMY_LEFT)
	{
		switch (_EattackIdx)
		{
		case 0:
			_enemyAni = KEYANIMANAGER->findAnimation("SCHOOLGIRL_comboAttack1L");
			_enemyAni->resume();
	
			break;
		
		case 1:
			_enemyAni = KEYANIMANAGER->findAnimation("SCHOOLGIRL_comboAttack2L");
			_enemyAni->resume();
		
			break;
		
		case 2:
			_enemyAni = KEYANIMANAGER->findAnimation("SCHOOLGIRL_comboAttack3L");
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
		}

		
	}
}
void enemyAttack::callBk()				
{
	if (!_enemyAni->isPlay())					
	{
		if (_enemy->getIsEnemyAttack())
		{

			_enemyAni->stop();
			if (_EattackIdx < 3) _EattackIdx++;
			else _EattackIdx = 0;
			
			if (_EattackIdx >= 3)
			{
				_enemy->setEnemyCount(0);
				_enemy->setEnemyState(new enemyWaitAttack);
			}
		}
	}
}

#pragma endregion
//////////////////////////////////////////////	��   ��  ////////////////////////////////////////////////////////////
#pragma region �ǰ� ����

enemyHurt::enemyHurt()
{
	_EattackIdx = 0;

	if (_EhultIdx == 0)
	{
		_enemyImg = IMAGEMANAGER->findImage("SCHOOLGIRL_gethit");
		if (_enemyDir == (int)ENEMY_RIGHT)
		{
			_enemyAni = KEYANIMANAGER->findAnimation("SCHOOLGIRL_gethit1R");
		}
		if (_enemyDir == (int)ENEMY_LEFT)
		{
			_enemyAni = KEYANIMANAGER->findAnimation("SCHOOLGIRL_gethit1L");
		}
	}
	else if (_EhultIdx == 1)
	{
		_enemyImg = IMAGEMANAGER->findImage("SCHOOLGIRL_gethit");
		if (_enemyDir == (int)ENEMY_RIGHT)
		{
			_enemyAni = KEYANIMANAGER->findAnimation("SCHOOLGIRL_gethit2R");
		}
		if (_enemyDir == (int)ENEMY_LEFT)
		{
			_enemyAni = KEYANIMANAGER->findAnimation("SCHOOLGIRL_gethit2L");
		}
	}
	else if (_EhultIdx == 2)
	{
		_enemyImg = IMAGEMANAGER->findImage("SCHOOLGIRL_gethit");
		if (_enemyDir == (int)ENEMY_RIGHT)
		{
			_enemyAni = KEYANIMANAGER->findAnimation("SCHOOLGIRL_gethit3R");
		}
		if (_enemyDir == (int)ENEMY_LEFT)
		{
			_enemyAni = KEYANIMANAGER->findAnimation("SCHOOLGIRL_gethit3L");
		}
	}
}

enemyHurt::~enemyHurt()
{
}

HRESULT enemyHurt::init()
{
	if (_EhultIdx == 0)
	{
		_enemyImg = IMAGEMANAGER->findImage("SCHOOLGIRL_gethit");
		if (_enemyDir == (int)ENEMY_RIGHT)
		{
			_enemyAni = KEYANIMANAGER->findAnimation("SCHOOLGIRL_gethit1R");
		}
		if (_enemyDir == (int)ENEMY_LEFT)
		{
			_enemyAni = KEYANIMANAGER->findAnimation("SCHOOLGIRL_gethit1L");
		}
	}
	else if (_EhultIdx == 1)
	{
		_enemyImg = IMAGEMANAGER->findImage("SCHOOLGIRL_gethit");
		if (_enemyDir == (int)ENEMY_RIGHT)
		{
			_enemyAni = KEYANIMANAGER->findAnimation("SCHOOLGIRL_gethit2R");
		}
		if (_enemyDir == (int)ENEMY_LEFT)
		{
			_enemyAni = KEYANIMANAGER->findAnimation("SCHOOLGIRL_gethit2L");
		}
	}
	else if (_EhultIdx == 2)
	{
		_enemyImg = IMAGEMANAGER->findImage("SCHOOLGIRL_gethit");
		if (_enemyDir == (int)ENEMY_RIGHT)
		{
			_enemyAni = KEYANIMANAGER->findAnimation("SCHOOLGIRL_gethit3R");
		}
		if (_enemyDir == (int)ENEMY_LEFT)
		{
			_enemyAni = KEYANIMANAGER->findAnimation("SCHOOLGIRL_gethit3L");
		}
	}


	return S_OK;
}

void enemyHurt::release()
{
}

void enemyHurt::update()
{
	
	enemyState::update();
	_enemy->setIsEnemyIdle(false);
	_enemy->setIsEnemyAttack(false);
	_enemy->setIsEnemyWaitAttack(false);
	_enemy->setIsEnemyChase(false);
	_enemy->setEnemyCount(0);

	_EHurtcount++;

	_enemy->setEnemySpeed(0);
	
	if (_EhultIdx == 0)
	{
		_enemyImg = IMAGEMANAGER->findImage("SCHOOLGIRL_gethit");
		if (_enemyDir == (int)ENEMY_RIGHT)
		{
			_enemyAni = KEYANIMANAGER->findAnimation("SCHOOLGIRL_gethit1R");
		}
		if (_enemyDir == (int)ENEMY_LEFT)
		{
			_enemyAni = KEYANIMANAGER->findAnimation("SCHOOLGIRL_gethit1L");
		}
	}
	else if (_EhultIdx == 1)
	{
		_enemyImg = IMAGEMANAGER->findImage("SCHOOLGIRL_gethit");
		if (_enemyDir == (int)ENEMY_RIGHT)
		{
			_enemyAni = KEYANIMANAGER->findAnimation("SCHOOLGIRL_gethit2R");
		}
		if (_enemyDir == (int)ENEMY_LEFT)
		{
			_enemyAni = KEYANIMANAGER->findAnimation("SCHOOLGIRL_gethit2L");
		}
	}
	else if (_EhultIdx == 2)
	{
		_enemyImg = IMAGEMANAGER->findImage("SCHOOLGIRL_gethit");
		if (_enemyDir == (int)ENEMY_RIGHT)
		{
			_enemyAni = KEYANIMANAGER->findAnimation("SCHOOLGIRL_gethit3R");
		}
		if (_enemyDir == (int)ENEMY_LEFT)
		{
			_enemyAni = KEYANIMANAGER->findAnimation("SCHOOLGIRL_gethit3L");
		}
	}

	if (!_enemy->getIsEnemyHurt())						
	{
		switch (_EhultIdx)							//���� �޺���
		{
		case 0:
			
			_enemyImg = IMAGEMANAGER->findImage("SCHOOLGIRL_gethit");
			break;

		case 1:
			
			_enemyImg = IMAGEMANAGER->findImage("SCHOOLGIRL_gethit");
			break;

		case 2:
			
			_enemyImg = IMAGEMANAGER->findImage("SCHOOLGIRL_gethit");
			break;
		}
	}

	//callBk();



}

void enemyHurt::render()
{
	enemyState::render();
}

void enemyHurt::enemyStateChange()
{
	
	
	if (_enemyDir == ENEMY_LEFT)
	{
		if (_enemy->getEnemyDistance() < 10 && _enemy->getIsEnemyHurt() && _EhultIdx > 3)
		{
			_enemy->setEnemyState(new enemyWaitAttack);

		}
	}
	
	if (_enemyDir == ENEMY_RIGHT)
	{
		if (_enemy->getEnemyDistanceR() < 10 && _enemy->getIsEnemyHurt() && _EhultIdx > 3)
		{
			_enemy->setEnemyState(new enemyWaitAttack);
		}
	}

	if (_enemyDir == ENEMY_LEFT)
	{
		if (_enemy->getEnemyDistance() >= 10 && !_enemy->getIsEenmyChase())
		{
			_enemyAni->stop();
			_enemy->setEnemySpeed(2.f);
			_enemy->setEnemyState(new enemyChase);
		}
	}
	if (_enemyDir == ENEMY_RIGHT)
	{
		if (_enemy->getEnemyDistanceR() >= 10 && !_enemy->getIsEenmyChase())
		{
			_enemyAni->stop();
			_enemy->setEnemySpeed(2.f);
			_enemy->setEnemyState(new enemyChase);
		}
	}
}

void enemyHurt::enemyAni()
{
	if (_enemyDir == (int)ENEMY_LEFT)
	{
		switch (_EhultIdx)
		{
		case 0:
			_enemyAni = KEYANIMANAGER->findAnimation("SCHOOLGIRL_gethit1L");
			_enemyAni->resume();
			break;

		case 1:
			_enemyAni = KEYANIMANAGER->findAnimation("SCHOOLGIRL_gethit2L");
			_enemyAni->resume();
			break;

		case 2:
			_enemyAni = KEYANIMANAGER->findAnimation("SCHOOLGIRL_gethit3L");
			_enemyAni->resume();
			break;

		}

	}
	if (_enemyDir == (int)ENEMY_RIGHT)
	{
		switch (_EhultIdx)
		{
		case 0:
			_enemyAni = KEYANIMANAGER->findAnimation("SCHOOLGIRL_gethit1R");
			_enemyAni->resume();
			break;

		case 1:
			_enemyAni = KEYANIMANAGER->findAnimation("SCHOOLGIRL_gethit2R");
			_enemyAni->resume();
			break;

		case 2:
			_enemyAni = KEYANIMANAGER->findAnimation("SCHOOLGIRL_gethit3R");
			_enemyAni->resume();
			break;
		}


	}
}
void enemyHurt::callBk()
{
	if (!_enemyAni->isPlay())
	{
		if (_enemy->getIsEnemyHurt())
		{
			
			_enemyAni->stop();

			//�´� ī��Ʈ�� 3���� ������ ī��Ʈ�� �÷���!
			if (_EhultIdx < 3 && _enemy->getIsEnemyHurt())
			{
				_EHurtcount = 0;
				_EhultIdx += 1;
			}
			else _EhultIdx = 0;
				
			}
			if (_EHurtcount > 20)
			{
				_enemy->setEnemyState(new enemyWaitAttack);
			}
		}
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
	_enemyAni = KEYANIMANAGER->findAnimation("SCHOOLGIRL_jumpL");
	_enemyAni = KEYANIMANAGER->findAnimation("SCHOOLGIRL_jumpR");
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
//////////////////////////////////////////////	���ݴ��  ////////////////////////////////////////////////////////////
#pragma region �����ϱ��� ��� ���

enemyWaitAttack::enemyWaitAttack()
{
	_enemyImg = IMAGEMANAGER->findImage("SCHOOLGIRL_idle");
}

enemyWaitAttack::~enemyWaitAttack()
{
	
}

HRESULT enemyWaitAttack::init()
{
	enemyState::init();

	_enemyImg = IMAGEMANAGER->findImage("SCHOOLGIRL_idle");

	return S_OK;
}

void enemyWaitAttack::release()
{
}

void enemyWaitAttack::update()
{
	_enemy->setEnemyCount(_enemy->getEnemyCount() + 1);
	_enemy->setEnemySpeed(0.f);
	_enemy->setIsEnemyAttack(false);
	_enemy->setIsEnemyIdle(false);
	_enemy->setIsEnemyChase(false);
	_enemy->setIsEnemyHurt(false);
	_enemy->setIsEnemyRun(false);
	_enemy->setIsEnemyRunAttack(false);
	_enemy->setIsEnemyWaitAttack(true);
	_EhultIdx = 0;


	enemyState::update();

	_enemyImg = IMAGEMANAGER->findImage("SCHOOLGIRL_idle");
}

void enemyWaitAttack::render()
{
	enemyState::render();
}

void enemyWaitAttack::enemyStateChange()
{
	if (_enemyDir == ENEMY_LEFT)
	{
		if(_enemy->getEnemyDistance() >= 10)
		{
			_enemy->setEnemyState(new enemyChase);
		}
	}

	if (_enemyDir == ENEMY_RIGHT)
	{
		if (_enemy->getEnemyDistanceR() >= 10)
		{
			_enemy->setEnemyState(new enemyChase);
		}
	}

	if (_enemyDir == ENEMY_LEFT)
	{
		if (_enemy->getEnemyDistance() < 10 && !_enemy->getIsEenmyChase() && !_enemy->getIsEnemyAttack() && !_enemy->getIsEnemyIdle() && _enemy->getIsEnemyWaitAttack() && _enemy->getEnemyCount() > RND->getFromFloatTo(50, 200))
		{
			_enemy->setEnemyState(new enemyAttack);

		}
	}
	
	if (_enemyDir == ENEMY_RIGHT)
	{
		if (_enemy->getEnemyDistanceR() < 10 && !_enemy->getIsEenmyChase() && !_enemy->getIsEnemyAttack() && !_enemy->getIsEnemyIdle() && _enemy->getIsEnemyWaitAttack() && _enemy->getEnemyCount() > RND->getFromFloatTo(50,200))
		{
			_enemy->setEnemyState(new enemyAttack);
		}
	}

	//�ǰݽ�
	if (_enemyDir == ENEMY_LEFT)
	{
		if (_enemy->getIsEnemyHurt())
		{
			_enemy->setEnemyState(new enemyHurt);

		}
	}

	if (_enemyDir == ENEMY_RIGHT)
	{
		if (_enemy->getIsEnemyHurt())
		{
			_enemy->setEnemyState(new enemyHurt);

		}
	}

	if (_enemyDir == ENEMY_LEFT)
	{
		if (_enemy->getEnemyDistance() < 10 && !_enemy->getIsEnemyAttack() && _enemy->getIsEnemyRunAttack())
		{
			_enemy->setEnemyState(new enemyRunAttack);
		}
	}

	if (_enemyDir == ENEMY_RIGHT)
	{
		if (_enemy->getEnemyDistanceR() < 10 && !_enemy->getIsEnemyAttack() && _enemy->getIsEnemyRunAttack())
		{
			_enemy->setEnemyState(new enemyRunAttack);
		}
	}
}

void enemyWaitAttack::enemyAni()
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
//////////////////////////////////////////////	�� �� ��  ////////////////////////////////////////////////////////////
#pragma region �޸���



enemyRun::enemyRun()
{
	_enemyImg = IMAGEMANAGER->findImage("SCHOOLGIRL_run");
}

enemyRun::~enemyRun()
{
}

HRESULT enemyRun::init()
{
	enemyState::init();

	_enemyImg = IMAGEMANAGER->findImage("SCHOOLGIRL_run");

	return S_OK;
}

void enemyRun::release()
{
}

void enemyRun::update()
{
	_enemy->setIsEnemyIdle(false);
	_enemy->setIsEnemyAttack(false);
	_enemy->setIsEnemyChase(false);
	_enemy->setIsEnemyRun(true);
	_enemy->setEnemySpeed(4.0f);

	enemyState::update();

	_enemyImg = IMAGEMANAGER->findImage("SCHOOLGIRL_run");
}

void enemyRun::render()
{
	enemyState::render();
}

void enemyRun::enemyStateChange()
{
	if(_enemyDir == (int)ENEMY_LEFT)
	{
		if (_enemy->getEnemyDistance() > 800)
		{
			_enemy->setEnemyState(new enemyWaitAttack);
		}
	}
	
	if (_enemyDir == (int)ENEMY_RIGHT)
	{
		if (_enemy->getEnemyDistanceR() > 800)
		{
			_enemy->setEnemyState(new enemyWaitAttack);
		}
	}

	if (_enemyDir == (int)ENEMY_LEFT)
	{
		if (_enemy->getEnemyDistance() < 10)
		{
			_enemy->setEnemyState(new enemyRunAttack);
		}
	}
	if (_enemyDir == (int)ENEMY_RIGHT)
	{
		if (_enemy->getEnemyDistanceR() < 10)
		{
			_enemy->setEnemyState(new enemyRunAttack);
		}
	}
}

void enemyRun::enemyAni()
{
	if (_enemyDir == (int)ENEMY_LEFT)
	{
		_enemyAni = KEYANIMANAGER->findAnimation("SCHOOLGIRL_runL");
		_enemyAni->resume();
	}
	if (_enemyDir == (int)ENEMY_RIGHT)
	{
		_enemyAni = KEYANIMANAGER->findAnimation("SCHOOLGIRL_runR");
		_enemyAni->resume();
	}
}
#pragma endregion
//////////////////////////////////////////////	�뽬����  ////////////////////////////////////////////////////////////
#pragma region �뽬����
enemyRunAttack::enemyRunAttack()
{
	_enemyImg = IMAGEMANAGER->findImage("SCHOOLGIRL_jumpAttack");
}

enemyRunAttack::~enemyRunAttack()
{
}

HRESULT enemyRunAttack::init()
{
	enemyState::init();

	_enemyImg = IMAGEMANAGER->findImage("SCHOOLGIRL_jumpAttack");
	return S_OK;
}

void enemyRunAttack::release()
{
}

void enemyRunAttack::update()
{
	enemyState::update();
	
	_enemy->setEnemySpeed(0);
	_enemy->setEnemyCount(0);
	_enemy->setIsEnemyChase(false);
	_enemy->setIsEnemyRun(false);
	_enemy->setIsEnemyIdle(false);
	_enemy->setIsEnemyHurt(false);
	_enemy->setIsEnemyRunAttack(true);

	_enemyImg = IMAGEMANAGER->findImage("SCHOOLGIRL_jumpAttack");

}

void enemyRunAttack::render()
{
	enemyState::render();
}

void enemyRunAttack::enemyStateChange()
{
	//�Ÿ��� �־����� ���� ��� �������
	if (_enemyDir == ENEMY_LEFT)
	{
		if (_enemy->getEnemyDistance() > 10)
		{
			_enemy->setEnemyState(new enemyWaitAttack);
		}
	}
	if (_enemyDir == ENEMY_RIGHT)
	{
		if (_enemy->getEnemyDistanceR() > 10)
		{
			_enemy->setEnemyState(new enemyWaitAttack);
		}
	}

	//�ǰݽ�
	if (_enemyDir == ENEMY_LEFT)
	{
		if (_enemy->getIsEnemyHurt())
		{
			_enemy->setEnemyState(new enemyHurt);

		}
	}

	if (_enemyDir == ENEMY_RIGHT)
	{
		if (_enemy->getIsEnemyHurt())
		{
			_enemy->setEnemyState(new enemyHurt);

		}
	}

}

void enemyRunAttack::enemyAni()
{
	if (_enemyDir == (int)ENEMY_LEFT)
	{
		_enemyAni = KEYANIMANAGER->findAnimation("SCHOOLGIRL_dashAttackL");
		_enemyAni->resume();
	}
	if (_enemyDir == (int)ENEMY_RIGHT)
	{
		_enemyAni = KEYANIMANAGER->findAnimation("SCHOOLGIRL_dashAttackR");
		_enemyAni->resume();
	}
}
void enemyRunAttack::callBk()
{
	//if (!_enemyAni->isPlay())
	//{
	//	if (_enemy->getIsEnemyRunAttack())
	//	{			
	//		//_enemyAni->stop();
	//		//_enemy->setEnemyState(new enemyIdle);
	//	}	
	//}
}
#pragma endregion