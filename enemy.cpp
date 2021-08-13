#include "pch.h"
#include "enemy.h"
#include "player.h"


enemy::enemy()
{
}

enemy::~enemy()
{
}

HRESULT enemy::init()
{
	//enemyAni();
	//
	//_enemyState = new enemyIdle;
	//_enemyState->init();
	//
	//_enemyImg = _enemyState->getEnemyImg();
	//_enemyShadowImg = IMAGEMANAGER->findImage("SHADOW");
	//
	//_enemySX = WINSIZEX / 2 + 200;
	//_enemySY = WINSIZEY / 2;
	//
	//_enemyX = _enemySX;
	//_enemyY = _enemySY - _enemyImg->getFrameHeight() / 2;
	//
	//_enemyRc = RectMakeCenter(_enemyX, _enemyY, _enemyImg->getFrameWidth(), _enemyImg->getFrameWidth());
	//_enemyShadowRc = RectMakeCenter(_enemySX, _enemySY, _enemyShadowImg->getWidth(), _enemyShadowImg->getHeight());
	//		
	//_enemySpeed = 0;
	//_enemyJP = 0;
	//
	//
	//
	//_isEIdle = false;
	//_isEJump = false;
	//_isEAttack = false;
	//_isEChase = false;
	//_isEHurt = false;
	//_isEWaitAttack = false;
	//_isRun = false;
	//_isRunAttack = false;
	//_isDie = false;
	//
	//
	//
	////ex.x = 500;
	////ex.y = 500;

	

	return S_OK;
}

HRESULT enemy::init(POINT pt)
{
	enemyAni();

	_enemyState = new enemyIdle;
	_enemyState->init();

	_enemyImg = _enemyState->getEnemyImg();
	_enemyShadowImg = IMAGEMANAGER->findImage("SHADOW");

	_enemySX = pt.x;
	_enemySY = pt.y;

	_enemyX = _enemySX;
	_enemyY = _enemySY - _enemyImg->getFrameHeight() / 2;

	_enemyRc = RectMakeCenter(_enemyX, _enemyY, _enemyImg->getFrameWidth(), _enemyImg->getFrameWidth());
	_enemyShadowRc = RectMakeCenter(_enemySX, _enemySY, _enemyShadowImg->getWidth(), _enemyShadowImg->getHeight());

	_enemySpeed = 0;
	_enemyJP = 10.f;
	_enemyGravity = 0.5f;

	_vanishImgCount = 200;

	_enemyHp = 1000;
	


	_isEIdle = false;
	_isEJump = false;
	_isEAttack = false;
	_isEChase = false;
	_isEHurt = false;
	_isEWaitAttack = false;
	_isRun = false;
	_isRunAttack = false;
	_isDie = false;
	_isCompleteDeath = false;
	_isVanishImg = false;

	return S_OK;
}

void enemy::release()
{
}

void enemy::update()
{
	_enemyState->setEnemy(this);
	
	enemyMove();
	playerHit();

	//_enemyX = _enemySX;
	if (!_isDie)
	{
		_enemyY = _enemySY - _enemyImg->getFrameHeight() / 2;
	}

	_enemyDistance = getDistance(_player->getShadowX() + 125, _player->getShadowY(), _enemySX , _enemySY);		//���� ���� �ٶ󺼶�
	_enemyDistanceR = getDistance(_player->getShadowX() - 125, _player->getShadowY(), _enemySX , _enemySY);		//���� ������ �ٶ󺼶�
	
	_enemyState->update();
	_enemyImg = _enemyState->getEnemyImg();
	
	_enemySX != _player->getShadowX();
	_enemySY != _player->getShadowY();
}

void enemy::render()
{

	char str1[128];

	sprintf_s(str1, "�÷��̾� hit : %d", _enemyState->gethitCheck());
	TextOut(getMemDC(), _enemySX, _enemySY + 50, str1, strlen(str1));

	sprintf_s(str1, "�� �̹��� ������°� : %d", _vanishImgCount);
	TextOut(getMemDC(), _enemySX , _enemySY + 70, str1, strlen(str1));
	
	sprintf_s(str1, "�� �̹����� ������°� : %d", _isVanishImg);
	TextOut(getMemDC(), _enemySX , _enemySY + 90 , str1, strlen(str1));
	//
	//sprintf_s(str1, "ü�� : %d", _enemyHp);
	//TextOut(getMemDC(), _enemySX, _enemySY + 90, str1, strlen(str1));
	//
	//sprintf_s(str1, "���� : %d", _enemyDir);
	//TextOut(getMemDC(), _enemySX, _enemySY + 110, str1, strlen(str1));
	//
	//sprintf_s(str1, "�÷��̾� ���� : %d",_player->getDir());
	//TextOut(getMemDC(), _enemySX, _enemySY + 130, str1, strlen(str1));
	//
	//sprintf_s(str1, "�׾��°� : %d", (int)_isDie);
	//TextOut(getMemDC(), _enemySX, _enemySY + 150, str1, strlen(str1));
	//
	//sprintf_s(str1, "������ �׾��°� : %d", (int)_isCompleteDeath);
	//TextOut(getMemDC(), _enemySX, _enemySY + 170, str1, strlen(str1));
	//
	//sprintf_s(str1, "������ �ױ� �� : %d", (int) _completeDeath);
	//TextOut(getMemDC(), _enemySX, _enemySY + 190, str1, strlen(str1));
	//sprintf_s(str1, "�� �����޺� : %d", _enemyState->getEattackIdx());
	//TextOut(getMemDC(), _enemySX , _enemySY + 90 , str1, strlen(str1));
	//
	//sprintf_s(str1, "�� ���ݻ��� : %d", (int)_isEAttack);
	//TextOut(getMemDC(), _enemySX , _enemySY + 130, str1, strlen(str1));
	//
	//sprintf_s(str1, "�� ����ī��Ʈ : %d", (int)_enemyCount);
	//TextOut(getMemDC(), _enemySX , _enemySY + 110 , str1, strlen(str1));
	//
	//sprintf_s(str1, "�� �ǰ��޺�: %d", (int)_enemyState->getEhultIdx());
	//TextOut(getMemDC(), _enemySX , _enemySY + 150 , str1, strlen(str1));
	//
	//sprintf_s(str1, "�� �̵� Ȯ�� : %d", _isEChase);
	//TextOut(getMemDC(), _enemySX, _enemySY + 170 , str1, strlen(str1));
	//
	//sprintf_s(str1, "�� �⺻ Ȯ�� : %d", _isEIdle);
	//TextOut(getMemDC(), _enemySX, _enemySY + 190 , str1, strlen(str1));
	//
	//sprintf_s(str1, "�� ���� ��� Ȯ�� : %d", _isEWaitAttack);
	//TextOut(getMemDC(), _enemySX, _enemySY + 210, str1, strlen(str1));
	//
	//sprintf_s(str1, "�� �ǰ� Ȯ�� : %d", _isEHurt);
	//TextOut(getMemDC(), _enemySX, _enemySY + 230 , str1, strlen(str1));
	//
	//sprintf_s(str1, "�� �ǰ� ī��Ʈ : %d", _enemyState->getEhurtcount());
	//TextOut(getMemDC(), _enemySX , _enemySY + 250 , str1, strlen(str1));
	//
	//sprintf_s(str1, "�� �޸��� Ȯ�� : %d", _isRun);
	//TextOut(getMemDC(), _enemySX + 150, _enemySY + 170, str1, strlen(str1));
	//
	//sprintf_s(str1, "�� �ӵ� : % .2f", _enemySpeed);
	//TextOut(getMemDC(), _enemySX + 150, _enemySY + 150, str1, strlen(str1));
	//
	//sprintf_s(str1, "�� �뽬���� Ȯ�� : %d",_isRunAttack);
	//TextOut(getMemDC(), _enemySX + 150, _enemySY + 190, str1, strlen(str1));
	//
	//sprintf_s(str1, "�� ���� Ȯ�� : %d", _isDie);
	//TextOut(getMemDC(), _enemySX + 150, _enemySY + 210, str1, strlen(str1));
	//
	//sprintf_s(str1, "�� ���� ī��Ʈ : %d", _hitCount);
	//TextOut(getMemDC(), _enemySX + 150, _enemySY + 230, str1, strlen(str1));

	
	
	if (!_isVanishImg)
	{
		_enemyShadowImg->render(getMemDC(), _enemyShadowRc.left, _enemyShadowRc.top);
		_enemyState->render();
	}
	
}

void enemy::enemyStateRender(animation* motion)
{

	_enemyImg->aniRender(getMemDC(), _enemyRc.left, _enemyRc.top, motion);

}

void enemy::enemyMove()
{
	if(_enemyDir == ENEMY_RIGHT)
	{
		if (_enemyDistance < 800  && _enemyDistance >= 10)	//�i�ư��°�
		{			
			_isEChase = true;
		}
	}

	if (_enemyDir == ENEMY_LEFT)
	{
		if (_enemyDistanceR < 800 && _enemyDistanceR >= 10)	//�i�ư��°�
		{
			_isEChase = true;
		}
	}

	if (_enemyDir == ENEMY_LEFT)
	{
		if (_enemyDistance < 10)
		{
			_isEChase = false;
		}
	}
	
	if (_enemyDir == ENEMY_RIGHT)
	{
		if (_enemyDistanceR < 10)
		{
			_isEChase = false;
		}
	}

	if (_isEChase)	//   �߰ݽ� �̵��ӵ� ����
	{
		if (_enemyDir == (int)ENEMY_LEFT)
		{
			_enemyX = _enemySX;
			_enemySX -= cosf(getAngle(_player->getShadowX()+125, _player->getShadowY(), _enemySX, _enemySY )) * _enemySpeed;
			_enemySY -= -sin(getAngle(_player->getShadowX()+125, _player->getShadowY(), _enemySX, _enemySY )) * _enemySpeed;
		}

		if (_enemyDir == (int)ENEMY_RIGHT)
		{
			_enemyX = _enemySX;
			_enemySX -= cosf(getAngle(_player->getShadowX()-125, _player->getShadowY(), _enemySX, _enemySY )) * _enemySpeed;
			_enemySY -= -sin(getAngle(_player->getShadowX()-125, _player->getShadowY(), _enemySX, _enemySY )) * _enemySpeed;

		}
	
	}
	if (!_isEChase)	// �߰��� �ƴҽ� �̵��ӵ� 0��
	{
		if (_enemyDir == (int)ENEMY_LEFT)
		{
			_enemyX = _enemySX;
			_enemySX -= cosf(getAngle(_player->getShadowX() + 125, _player->getShadowY(), _enemySX , _enemySY )) * _enemySpeed;
			_enemySY -= -sin(getAngle(_player->getShadowX() + 125, _player->getShadowY(), _enemySX , _enemySY )) * _enemySpeed;
		}

		if (_enemyDir == (int)ENEMY_RIGHT)
		{
			_enemyX = _enemySX;
			_enemySX -= cosf(getAngle(_player->getShadowX() - 125, _player->getShadowY(), _enemySX , _enemySY )) * _enemySpeed;
			_enemySY -= -sin(getAngle(_player->getShadowX() - 125, _player->getShadowY(), _enemySX , _enemySY )) * _enemySpeed;
		}
		

	}
	
	if (_enemyDir == (int)ENEMY_LEFT)
	{
		if (_player->getIsAttacking() && _player->getDir() != _enemyDir && !_isEHurt && _enemyDistance < 10)	//�÷��̾�� ���ʹ��� ������ �ٸ��� �÷��̾ ������ �ǰݸ�� �߰� �ϴ°�
		{
			enemyHp();
			_isEHurt = true;
		}
	}
	if (_enemyDir == (int)ENEMY_RIGHT)
	{
		if (_player->getIsAttacking() && _player->getDir() != _enemyDir && !_isEHurt && _enemyDistanceR < 10)	//�÷��̾�� ���ʹ��� ������ �ٸ��� �÷��̾ ������ �ǰݸ�� �߰� �ϴ°�
		{
			enemyHp();
			_isEHurt = true;
		}
	}

	if (_enemyDir == (int)ENEMY_LEFT)			//�׾����� ���󰡴°�
	{
		if (_isDie)
		{
			_dieSpeed = 2;
			_dieCount++;
			_completeDeath++;

			if (_dieCount > 30)
			{
				_dieSpeed = 0;
			}

			_enemySX += _dieSpeed;
		}
	}

	if (_enemyDir == (int)ENEMY_RIGHT)
	{
		if (_isDie) 
		{

			_dieSpeed = 2;
			_dieCount++;
			_completeDeath++;


			if (_dieCount > 30)
			{
				_dieSpeed = 0;
			}

			_enemySX -= _dieSpeed;
		}
	}

	if (_isDie && _enemyRc.bottom < _enemySY)
	{
		_enemyY -= _enemyJP;
		_enemyJP -= _enemyGravity;
	}

	if (_completeDeath > 31)
	{
		_isCompleteDeath = true;
	}

	if (_isCompleteDeath)
	{
		_vanishImgCount--;
	}

	if (_vanishImgCount < 0)
	{
		_isVanishImg = true;
	}

	if(!_player->getIsAttacking() && _isEHurt)
	{
		_isEHurt = false;

	}

	//�÷��̾���� �Ÿ��� �ľ��ؼ� ���� ��ȯ
	if (_player->getShadowX() > _enemySX && !_isDie && !_isCompleteDeath)
	{
		enemyHp();
		_enemyDir = (int)ENEMY_RIGHT;
	}
	if (_player->getShadowX() < _enemySX && !_isDie && !_isCompleteDeath)
	{
		enemyHp();
		_enemyDir = (int)ENEMY_LEFT;
	}

	_enemyRc = RectMakeCenter(_enemyX , _enemyY , _enemyImg->getFrameWidth(), _enemyImg->getFrameHeight());
	_enemyShadowRc = RectMakeCenter(_enemySX , _enemySY , _enemyShadowImg->getWidth(), _enemyShadowImg->getHeight());


}

void enemy::enemyHp()
{
	if (_isEHurt)
	{
		_enemyHp -= 10;
	}
}

void enemy::playerHit()
{
	if (_enemyDir == ENEMY_RIGHT)
	{
		if (_enemyDistanceR < 10 && _enemyState->gethitCheck() && !_player->getIsGetHit())
		{
			_player->setIsGetHit(true);
		}
	
	}

	if (_enemyDir == ENEMY_LEFT)
	{
		if (_enemyDistance < 10 && _enemyState->gethitCheck() && !_player->getIsGetHit())
		{
			_player->setIsGetHit(true);
		}

	}
}





void enemy::enemyAni()
{
	//�⺻ ����
	KEYANIMANAGER->addCoordinateFrameAnimation("SCHOOLGIRL_idleR", "SCHOOLGIRL_idle", 0, 9, 10, false, true);
	KEYANIMANAGER->addCoordinateFrameAnimation("SCHOOLGIRL_idleL", "SCHOOLGIRL_idle", 19, 10, 10, false, true);
	//�ȴ� ����
	KEYANIMANAGER->addCoordinateFrameAnimation("SCHOOLGIRL_walkL", "SCHOOLGIRL_walk", 23, 12, 10, false, true);
	KEYANIMANAGER->addCoordinateFrameAnimation("SCHOOLGIRL_walkR", "SCHOOLGIRL_walk", 0, 11, 10, false, true);
	//�ٴ� ����
	KEYANIMANAGER->addCoordinateFrameAnimation("SCHOOLGIRL_runL", "SCHOOLGIRL_run", 19, 10, 10, false, true);
	KEYANIMANAGER->addCoordinateFrameAnimation("SCHOOLGIRL_runR", "SCHOOLGIRL_run", 0, 9, 10, false, true);
	////���� ����
	//KEYANIMANAGER->addCoordinateFrameAnimation("SCHOOLGIRL_stunL", "SCHOOLGIRL_stun", 7, 4, 10, false, true);
	//KEYANIMANAGER->addCoordinateFrameAnimation("SCHOOLGIRL_stunR", "SCHOOLGIRL_stun", 0, 3, 10, false, true);
	
	////���� ����
	//
	//int EleftJump[] = { 5,4,3,4,5 };
	//int ErigthJump[] = { 0,1,2,1,0 };
	//
	//KEYANIMANAGER->addArrayFrameAnimation("SCHOOLGIRL_jumpL", "SCHOOLGIRL_jump", EleftJump, 5, 10, false);
	//KEYANIMANAGER->addArrayFrameAnimation("SCHOOLGIRL_jumpR", "SCHOOLGIRL_jump", ErigthJump, 0, 10, false);
	//���� ����1
	KEYANIMANAGER->addCoordinateFrameAnimation("SCHOOLGIRL_comboAttack1L", "SCHOOLGIRL_comboAttack1", 13, 7, 10, false, false);
	KEYANIMANAGER->addCoordinateFrameAnimation("SCHOOLGIRL_comboAttack1R", "SCHOOLGIRL_comboAttack1", 0, 6, 10, false, false);
	//���� ����2
	KEYANIMANAGER->addCoordinateFrameAnimation("SCHOOLGIRL_comboAttack2L", "SCHOOLGIRL_comboAttack2", 15, 8, 10, false, false);
	KEYANIMANAGER->addCoordinateFrameAnimation("SCHOOLGIRL_comboAttack2R", "SCHOOLGIRL_comboAttack2", 0, 7, 10, false, false);
	//���� ����3
	KEYANIMANAGER->addCoordinateFrameAnimation("SCHOOLGIRL_comboAttack3L", "SCHOOLGIRL_comboAttack3", 23, 12, 10, false, false);
	KEYANIMANAGER->addCoordinateFrameAnimation("SCHOOLGIRL_comboAttack3R", "SCHOOLGIRL_comboAttack3", 0, 11, 10, false, false);

	////���� ����
	//KEYANIMANAGER->addCoordinateFrameAnimation("SCHOOLGIRL_jumpAttackL", "SCHOOLGIRL_jumpAttack", 13, 7, 10, false, false);
	//KEYANIMANAGER->addCoordinateFrameAnimation("SCHOOLGIRL_jumpAttackR", "SCHOOLGIRL_jumpAttack", 0, 6, 10, false, false);

	////�뽬 ����
	//KEYANIMANAGER->addCoordinateFrameAnimation("SCHOOLGIRL_dashAttackL", "SCHOOLGIRL_jumpAttack", 11, 7, 10, false, false);
	//KEYANIMANAGER->addCoordinateFrameAnimation("SCHOOLGIRL_dashAttackR", "SCHOOLGIRL_jumpAttack", 2, 6, 10, false, false);

	//������ ����
	KEYANIMANAGER->addCoordinateFrameAnimation("SCHOOLGIRL_dieL", "SCHOOLGIRL_weapon_swing", 33, 17, 10, false, false);
	KEYANIMANAGER->addCoordinateFrameAnimation("SCHOOLGIRL_dieR", "SCHOOLGIRL_weapon_swing", 0, 17, 10, false, false);

	//������ ���� ����
	KEYANIMANAGER->addCoordinateFrameAnimation("SCHOOLGIRL_CompleteDeathL", "SCHOOLGIRL_weapon_swing", 18, 17, 10, false, false);
	KEYANIMANAGER->addCoordinateFrameAnimation("SCHOOLGIRL_CompleteDeathR", "SCHOOLGIRL_weapon_swing", 16, 17, 10, false, false);

	//�ǰ� ������ ����
	KEYANIMANAGER->addCoordinateFrameAnimation("SCHOOLGIRL_backdownL", "SCHOOLGIRL_backdown", 53, 27, 10, false, false);
	KEYANIMANAGER->addCoordinateFrameAnimation("SCHOOLGIRL_backdownR", "SCHOOLGIRL_backdown", 0, 26, 10, false, false);
	//��� ����
	KEYANIMANAGER->addCoordinateFrameAnimation("SCHOOLGIRL_blockL", "SCHOOLGIRL_block", 5, 3, 10, false, false);
	KEYANIMANAGER->addCoordinateFrameAnimation("SCHOOLGIRL_blockR", "SCHOOLGIRL_block", 0, 2, 10, false, false);
	
	//�ǰ� ����1
	KEYANIMANAGER->addCoordinateFrameAnimation("SCHOOLGIRL_gethit1L", "SCHOOLGIRL_gethit", 17, 15, 10, false, false);
	KEYANIMANAGER->addCoordinateFrameAnimation("SCHOOLGIRL_gethit1R", "SCHOOLGIRL_gethit", 0, 2, 10, false, false);
	//�ǰ� ����2
	KEYANIMANAGER->addCoordinateFrameAnimation("SCHOOLGIRL_gethit2L", "SCHOOLGIRL_gethit", 14, 12, 10, false, false);
	KEYANIMANAGER->addCoordinateFrameAnimation("SCHOOLGIRL_gethit2R", "SCHOOLGIRL_gethit", 3, 5, 10, false, false);
	//�ǰ� ����3
	KEYANIMANAGER->addCoordinateFrameAnimation("SCHOOLGIRL_gethit3L", "SCHOOLGIRL_gethit", 11, 9, 10, false, false);
	KEYANIMANAGER->addCoordinateFrameAnimation("SCHOOLGIRL_gethit3R", "SCHOOLGIRL_gethit", 6, 8, 10, false, false);
	
	////�׺� ����
	//KEYANIMANAGER->addCoordinateFrameAnimation("SCHOOLGIRL_beggingL", "SCHOOLGIRL_begging", 4, 3, 10, false, false);
	//KEYANIMANAGER->addCoordinateFrameAnimation("SCHOOLGIRL_beggingR", "SCHOOLGIRL_begging", 1, 2, 10, false, false);
	////���� �� �ǰ� ����
	//KEYANIMANAGER->addCoordinateFrameAnimation("SCHOOLGIRL_heldHitL", "SCHOOLGIRL_heldHit", 7, 4, 10, false, false);
	//KEYANIMANAGER->addCoordinateFrameAnimation("SCHOOLGIRL_heldHitR", "SCHOOLGIRL_heldHit", 0, 3, 10, false, false);
	////���� �� Ǯ�� ����
	//KEYANIMANAGER->addCoordinateFrameAnimation("SCHOOLGIRL_heldReleaseL", "SCHOOLGIRL_heldRelease", 7, 4, 10, false, false);
	//KEYANIMANAGER->addCoordinateFrameAnimation("SCHOOLGIRL_heldReleaseR", "SCHOOLGIRL_heldRelease", 0, 3, 10, false, false);

	/////////////////// ���� ���� ///////////////////////////

	////�⺻ ����
	//KEYANIMANAGER->addCoordinateFrameAnimation("SCHOOLBOY_idleR", "SCHOOLBOY_idle", 0, 7, 10, false, true);
	//KEYANIMANAGER->addCoordinateFrameAnimation("SCHOOLBOY_idleL", "SCHOOLBOY_idle", 15, 8, 10, false, true);
	////�ȴ� ����
	//KEYANIMANAGER->addCoordinateFrameAnimation("SCHOOLBOY_walkL", "SCHOOLBOY_walk", 23, 12, 10, false, true);
	//KEYANIMANAGER->addCoordinateFrameAnimation("SCHOOLBOY_walkR", "SCHOOLBOY_walk", 0, 11, 10, false, true);
	////�ٴ� ����
	//KEYANIMANAGER->addCoordinateFrameAnimation("SCHOOLBOY_runR", "SCHOOLBOY_run", 19, 10, 10, false, true);
	//KEYANIMANAGER->addCoordinateFrameAnimation("SCHOOLBOY_runL", "SCHOOLBOY_run", 0, 9, 10, false, true);
	////���� ����1
	//KEYANIMANAGER->addCoordinateFrameAnimation("SCHOOLBOY_comboAttack1L", "SCHOOLBOY_comboAttack1", 13, 7, 10, false, false);
	//KEYANIMANAGER->addCoordinateFrameAnimation("SCHOOLBOY_comboAttack1R", "SCHOOLBOY_comboAttack1", 0, 6, 10, false, false);
	////���� ����2
	//KEYANIMANAGER->addCoordinateFrameAnimation("SCHOOLBOY_comboAttack2L", "SCHOOLBOY_comboAttack2", 13, 7, 10, false, false);
	//KEYANIMANAGER->addCoordinateFrameAnimation("SCHOOLBOY_comboAttack2R", "SCHOOLBOY_comboAttack2", 0, 6, 10, false, false);
	////���� ����3
	//KEYANIMANAGER->addCoordinateFrameAnimation("SCHOOLBOY_comboAttack3L", "SCHOOLBOY_comboAttack2", 17, 8, 10, false, false);
	//KEYANIMANAGER->addCoordinateFrameAnimation("SCHOOLBOY_comboAttack3R", "SCHOOLBOY_comboAttack2", 0, 8, 10, false, false);
	//
	////�ǰ� ����1
	//KEYANIMANAGER->addCoordinateFrameAnimation("SCHOOLBOY_gethit1", "SCHOOLBOY_gethit", 17, 15, 10, false, false);
	//KEYANIMANAGER->addCoordinateFrameAnimation("SCHOOLBOY_gethit1", "SCHOOLBOY_gethit", 0, 2, 10, false, false);
	////�ǰ� ����2
	//KEYANIMANAGER->addCoordinateFrameAnimation("SCHOOLBOY_gethit2", "SCHOOLBOY_gethit", 14, 12, 10, false, false);
	//KEYANIMANAGER->addCoordinateFrameAnimation("SCHOOLBOY_gethit2", "SCHOOLBOY_gethit", 3, 5, 10, false, false);
	////�ǰ� ����3
	//KEYANIMANAGER->addCoordinateFrameAnimation("SCHOOLBOY_gethit3", "SCHOOLBOY_gethit", 11, 9, 10, false, false);
	//KEYANIMANAGER->addCoordinateFrameAnimation("SCHOOLBOY_gethit3", "SCHOOLBOY_gethit", 6, 8, 10, false, false);


}

void enemy::callBack(void* obj)
{
	enemy* play = (enemy*)obj;

	play->setEnemyState(new enemyIdle);
}
