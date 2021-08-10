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
	enemyAni();

	_enemyState = new enemyIdle;
	_enemyState->init();

	_enemyImg = _enemyState->getEnemyImg();
	_enemyShadowImg = IMAGEMANAGER->findImage("SHADOW");
	
	_enemySX = WINSIZEX / 2 + 200;
	_enemySY = WINSIZEY / 2;

	_enemyX = _enemySX;
	_enemyY = _enemySY - _enemyImg->getFrameHeight() / 2;

	_enemyRc = RectMakeCenter(_enemyX, _enemyY, _enemyImg->getFrameWidth(), _enemyImg->getFrameWidth());
	_enemyShadowRc = RectMakeCenter(_enemySX, _enemySY, _enemyShadowImg->getWidth(), _enemyShadowImg->getHeight());
			
	_enemySpeed = 2;
	_enemyJP = 0;
	

	_isEJump = false;
	_isEAttack = false;
	_isEChase = false;
	
	
	//ex.x = 500;
	//ex.y = 500;

	

	return S_OK;
}

void enemy::release()
{
}

void enemy::update()
{



	_enemyState->setEnemy(this);
	
	enemyMove();
	enemyAttack();

	_enemyY = _enemySY - _enemyImg->getFrameHeight() / 2;


	_enemyDistance = getDistance(_player->getShadowX(), _player->getShadowY(), _enemySX + _enemyShadowImg->getFrameWidth(), _enemySY);
	_enemyState->update();
	_enemyImg = _enemyState->getEnemyImg();
}

void enemy::render()
{

	char str1[128];
	sprintf_s(str1, "���� �÷��̾�Ÿ� : %.2f", _enemyDistance);
	TextOut(getMemDC(), _enemySX, _enemySY + 50, str1, strlen(str1));


	sprintf_s(str1, "�� ���� : %d", _enemyState->getEattackIdx());
	TextOut(getMemDC(), _enemySX, _enemySY + 70, str1, strlen(str1));


	sprintf_s(str1, "�� ���ݽ� : %d", (int)_isEAttack);
	TextOut(getMemDC(), _enemySX, _enemySY + 90, str1, strlen(str1));

	_enemyShadowImg->render(getMemDC(), _enemyShadowRc.left, _enemyShadowRc.top);
	
	

	
	
	
	_enemyState->render();
}

void enemy::enemyStateRender(animation* motion)
{

	_enemyImg->aniRender(getMemDC(), _enemyRc.left, _enemyRc.top, motion);

}

void enemy::enemyMove()
{
	if (!_isEJump)
	{
		if (_enemyDistance < 400)	//�i�ư��°�
		{
			if (_enemyDir == (int)ENEMY_RIGHT)
			{
				_enemyX = _enemySX;
				_enemySX -= cosf(getAngle(_player->getShadowX() - 80, _player->getShadowY(), _enemySX, _enemySY)) * _enemySpeed;
			}
			if (_enemyDir == (int)ENEMY_LEFT)
			{
				_enemyX= _enemySX;
				_enemySX -= cosf(getAngle(_player->getShadowX() + 80, _player->getShadowY(), _enemySX, _enemySY)) * _enemySpeed;
			}
			//_enemyY = _enemySY - _enemyImg->getFrameHeight() / 2;
			_enemySY -= -sin(getAngle(_player->getShadowX(), _player->getShadowY(), _enemySX, _enemySY)) * _enemySpeed;
		}
		if (_isEJump)
		{
			if (_enemyRc.bottom <= _enemySY)
			{
				_enemyX = _enemySX;
				_enemyY -= _enemyJP;
				_enemyJP -= GRAVITY;
			}
			else
			{
				_enemyY = _enemySY - _enemyImg->getFrameHeight() / 2;
				_isEJump = false;
			}
		}
	}


	//�÷��̾���� �Ÿ��� �ľ��ؼ� ���� ��ȯ
	if (_player->getShadowX() > _enemySX)
	{
		_enemyDir = (int)ENEMY_RIGHT;
	}
	if (_player->getShadowX() < _enemySX)
	{
		_enemyDir = (int)ENEMY_LEFT;
	}

	_enemyRc = RectMakeCenter(_enemyX, _enemyY, _enemyImg->getFrameWidth(), _enemyImg->getFrameHeight());
	_enemyShadowRc = RectMakeCenter(_enemySX, _enemySY, _enemyShadowImg->getWidth(), _enemyShadowImg->getHeight());
}

void enemy::enemyAttack()
{
	

	
	
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
	//���� ����
	KEYANIMANAGER->addCoordinateFrameAnimation("SCHOOLGIRL_stunL", "SCHOOLGIRL_stun", 7, 4, 10, false, true);
	KEYANIMANAGER->addCoordinateFrameAnimation("SCHOOLGIRL_stunR", "SCHOOLGIRL_stun", 0, 3, 10, false, true);
	
	//���� ����
	
	int EleftJump[] = { 5,4,3,4,5 };
	int ErigthJump[] = { 0,1,2,1,0 };

	KEYANIMANAGER->addArrayFrameAnimation("SCHOOLGIRL_jumpL", "SCHOOLGIRL_jump", EleftJump, 5, 10, false);
	KEYANIMANAGER->addArrayFrameAnimation("SCHOOLGIRL_jumpR", "SCHOOLGIRL_jump", ErigthJump, 0, 10, false);
	//���� ����1
	KEYANIMANAGER->addCoordinateFrameAnimation("SCHOOLGIRL_comboAttack1L", "SCHOOLGIRL_comboAttack1", 13, 7, 10, false, false);
	KEYANIMANAGER->addCoordinateFrameAnimation("SCHOOLGIRL_comboAttack1R", "SCHOOLGIRL_comboAttack1", 0, 6, 10, false, false);
	//���� ����2
	KEYANIMANAGER->addCoordinateFrameAnimation("SCHOOLGIRL_comboAttack2L", "SCHOOLGIRL_comboAttack2", 15, 8, 10, false, false);
	KEYANIMANAGER->addCoordinateFrameAnimation("SCHOOLGIRL_comboAttack2R", "SCHOOLGIRL_comboAttack2", 0, 7, 10, false, false);
	//���� ����3
	KEYANIMANAGER->addCoordinateFrameAnimation("SCHOOLGIRL_comboAttack3L", "SCHOOLGIRL_comboAttack3", 23, 12, 10, false, false);
	KEYANIMANAGER->addCoordinateFrameAnimation("SCHOOLGIRL_comboAttack3R", "SCHOOLGIRL_comboAttack3", 0, 11, 10, false, false);

	//���� ����
	KEYANIMANAGER->addCoordinateFrameAnimation("SCHOOLGIRL_jumpAttackL", "SCHOOLGIRL_jumpAttack", 13, 7, 10, false, false);
	KEYANIMANAGER->addCoordinateFrameAnimation("SCHOOLGIRL_jumpAttackR", "SCHOOLGIRL_jumpAttack", 0, 6, 10, false, false);

	//�ǰ� ������ ����
	KEYANIMANAGER->addCoordinateFrameAnimation("SCHOOLGIRL_backdownL", "SCHOOLGIRL_backdown", 53, 27, 10, false, false);
	KEYANIMANAGER->addCoordinateFrameAnimation("SCHOOLGIRL_backdownR", "SCHOOLGIRL_backdown", 0, 26, 10, false, false);
	//��� ����
	KEYANIMANAGER->addCoordinateFrameAnimation("SCHOOLGIRL_blockL", "SCHOOLGIRL_block", 5, 3, 10, false, false);
	KEYANIMANAGER->addCoordinateFrameAnimation("SCHOOLGIRL_blockR", "SCHOOLGIRL_block", 0, 2, 10, false, false);
	//�ǰ� ����
	KEYANIMANAGER->addCoordinateFrameAnimation("SCHOOLGIRL_gethitL", "SCHOOLGIRL_gethit", 17, 9, 10, false, false);
	KEYANIMANAGER->addCoordinateFrameAnimation("SCHOOLGIRL_gethitR", "SCHOOLGIRL_gethit", 0, 8, 10, false, false);
	//�׺� ����
	KEYANIMANAGER->addCoordinateFrameAnimation("SCHOOLGIRL_beggingL", "SCHOOLGIRL_begging", 4, 3, 10, false, false);
	KEYANIMANAGER->addCoordinateFrameAnimation("SCHOOLGIRL_beggingR", "SCHOOLGIRL_begging", 1, 2, 10, false, false);
	//���� �� �ǰ� ����
	KEYANIMANAGER->addCoordinateFrameAnimation("SCHOOLGIRL_heldHitL", "SCHOOLGIRL_heldHit", 7, 4, 10, false, false);
	KEYANIMANAGER->addCoordinateFrameAnimation("SCHOOLGIRL_heldHitR", "SCHOOLGIRL_heldHit", 0, 3, 10, false, false);
	//���� �� Ǯ�� ����
	KEYANIMANAGER->addCoordinateFrameAnimation("SCHOOLGIRL_heldReleaseL", "SCHOOLGIRL_heldRelease", 7, 4, 10, false, false);
	KEYANIMANAGER->addCoordinateFrameAnimation("SCHOOLGIRL_heldReleaseR", "SCHOOLGIRL_heldRelease", 0, 3, 10, false, false);
}

void enemy::callBack(void* obj)
{
	enemy* play = (enemy*)obj;

	play->setEnemyState(new enemyIdle);
}
