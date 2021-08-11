#include "pch.h"
#include "enemy.h"
#include "player.h"
#include "camera.h"

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
	

	_isEIdle = false;
	_isEJump = false;
	_isEAttack = false;
	_isEChase = false;
	_isEHurt = false;
	_isEWaitAttack = false;
	
	
	
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
	
	_enemyDistance = getDistance(_player->getShadowX() + 125, _player->getShadowY(), _enemySX -_camera->getCamX(), _enemySY - _camera->getCamY());		//적이 왼쪽 바라볼때
	_enemyDistanceR = getDistance(_player->getShadowX() - 125, _player->getShadowY(), _enemySX - _camera->getCamX(), _enemySY - _camera->getCamY());		//적이 오른쪽 바라볼때
	
	_enemyState->update();
	_enemyImg = _enemyState->getEnemyImg();
}

void enemy::render()
{

	char str1[128];
	sprintf_s(str1, "적과 플레이어거리 : %.2f", _enemyDistance);
	TextOut(getMemDC(), _enemySX - _camera->getCamX(), _enemySY + 50 - _camera->getCamY(), str1, strlen(str1));

	sprintf_s(str1, "적과 플레이어거리R : %.2f", _enemyDistanceR);
	TextOut(getMemDC(), _enemySX - _camera->getCamX(), _enemySY + 70 - _camera->getCamY(), str1, strlen(str1));

	sprintf_s(str1, "적 공격콤보 : %d", _enemyState->getEattackIdx());
	TextOut(getMemDC(), _enemySX - _camera->getCamX(), _enemySY + 90 - _camera->getCamY(), str1, strlen(str1));

	sprintf_s(str1, "적 공격상태 : %d", (int)_isEAttack);
	TextOut(getMemDC(), _enemySX - _camera->getCamX(), _enemySY + 130 - _camera->getCamY(), str1, strlen(str1));
	
	sprintf_s(str1, "적 동작카운트 : %d", (int)_enemyCount);
	TextOut(getMemDC(), _enemySX - _camera->getCamX(), _enemySY + 110 - _camera->getCamY(), str1, strlen(str1));

	sprintf_s(str1, "적 피격콤보: %d", (int)_enemyState->getEhultIdx());
	TextOut(getMemDC(), _enemySX - _camera->getCamX(), _enemySY + 150 - _camera->getCamY(), str1, strlen(str1));

	sprintf_s(str1, "적 이동 확인 : %d", _isEChase);
	TextOut(getMemDC(), _enemySX- _camera->getCamX(), _enemySY + 170 - _camera->getCamY(), str1, strlen(str1));
	
	sprintf_s(str1, "적 기본 확인 : %d", _isEIdle);
	TextOut(getMemDC(), _enemySX - _camera->getCamX(), _enemySY + 190 - _camera->getCamY(), str1, strlen(str1));

	sprintf_s(str1, "적 공격 대기 확인 : %d", _isEWaitAttack);
	TextOut(getMemDC(), _enemySX - _camera->getCamX(), _enemySY + 210 - _camera->getCamY(), str1, strlen(str1));

	sprintf_s(str1, "적 피격 확인 : %d", _isEHurt);
	TextOut(getMemDC(), _enemySX - _camera->getCamX(), _enemySY + 230 - _camera->getCamY(), str1, strlen(str1));

	sprintf_s(str1, "적 피격 카운트 : %d", _enemyState->getEhurtcount());
	TextOut(getMemDC(), _enemySX - _camera->getCamX(), _enemySY + 230 - _camera->getCamY(), str1, strlen(str1));

	_enemyShadowImg->render(getMemDC(), _enemyShadowRc.left, _enemyShadowRc.top);
	
	

	
	
	
	_enemyState->render();
}

void enemy::enemyStateRender(animation* motion)
{

	_enemyImg->aniRender(getMemDC(), _enemyRc.left, _enemyRc.top, motion);

}

void enemy::enemyMove()
{
	
	if (_enemyDistance < 400 || _enemyDistanceR < 400 && _enemyDistance >= 10 ||_enemyDistanceR >=10)	//쫒아가는거
	{			
		_isEChase = true;
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

	if (_isEChase)	//   추격시 이동속도 증가
	{
		if (_enemyDir == (int)ENEMY_LEFT)
		{
			_enemyX = _enemySX;
			_enemySX -= cosf(getAngle(_player->getShadowX()+125, _player->getShadowY(), _enemySX - _camera->getCamX(), _enemySY) - _camera->getCamY()) * _enemySpeed;
			_enemySY -= -sin(getAngle(_player->getShadowX()+125, _player->getShadowY(), _enemySX - _camera->getCamX(), _enemySY - _camera->getCamY())) * _enemySpeed;
		}

		if (_enemyDir == (int)ENEMY_RIGHT)
		{
			_enemyX = _enemySX;
			_enemySX -= cosf(getAngle(_player->getShadowX()-125, _player->getShadowY(), _enemySX - _camera->getCamX(), _enemySY - _camera->getCamY())) * _enemySpeed;
			_enemySY -= -sin(getAngle(_player->getShadowX()-125, _player->getShadowY(), _enemySX - _camera->getCamX(), _enemySY - _camera->getCamY())) * _enemySpeed;

		}
	
	}
	if (!_isEChase)	// 추격이 아닐시 이동속도 0됨
	{
		if (_enemyDir == (int)ENEMY_LEFT)
		{
			_enemyX = _enemySX;
			_enemySX -= cosf(getAngle(_player->getShadowX()+125, _player->getShadowY(), _enemySX - _camera->getCamX(), _enemySY - _camera->getCamY())) * 0;
			_enemySY -= -sin(getAngle(_player->getShadowX() + 125, _player->getShadowY(), _enemySX - _camera->getCamX(), _enemySY - _camera->getCamY())) * 0;
		}

		if (_enemyDir == (int)ENEMY_RIGHT)
		{
			_enemyX = _enemySX;
			_enemySX -= cosf(getAngle(_player->getShadowX()-125, _player->getShadowY(), _enemySX - _camera->getCamX(), _enemySY - _camera->getCamY())) * 0;
			_enemySY -= -sin(getAngle(_player->getShadowX() - 125, _player->getShadowY(), _enemySX - _camera->getCamX(), _enemySY - _camera->getCamY())) * 0;
		}
		

	}
	//에너미 동작 키눌렀을때 확인해보려고 만든거 나중에 지워야함

	if (KEYMANAGER->isOnceKeyDown('B'))
	{
		_isEHurt = true;
	}
	if (KEYMANAGER->isOnceKeyUp('B'))
	{
		_isEHurt = false;
	}
	

	//플레이어와의 거리를 파악해서 방향 전환
	if (_player->getShadowX() > _enemySX - _camera->getCamX())
	{
		_enemyDir = (int)ENEMY_RIGHT;
	}
	if (_player->getShadowX() < _enemySX - _camera->getCamX())
	{
		_enemyDir = (int)ENEMY_LEFT;
	}

	_enemyRc = RectMakeCenter(_enemyX - _camera->getCamX(), _enemyY - _camera->getCamY(), _enemyImg->getFrameWidth(), _enemyImg->getFrameHeight());
	_enemyShadowRc = RectMakeCenter(_enemySX - _camera->getCamX(), _enemySY - _camera->getCamY(), _enemyShadowImg->getWidth(), _enemyShadowImg->getHeight());
}

void enemy::enemyAttack()
{
	

	
	
}



void enemy::enemyAni()
{
	//기본 상태
	KEYANIMANAGER->addCoordinateFrameAnimation("SCHOOLGIRL_idleR", "SCHOOLGIRL_idle", 0, 9, 10, false, true);
	KEYANIMANAGER->addCoordinateFrameAnimation("SCHOOLGIRL_idleL", "SCHOOLGIRL_idle", 19, 10, 10, false, true);
	//걷는 상태
	KEYANIMANAGER->addCoordinateFrameAnimation("SCHOOLGIRL_walkL", "SCHOOLGIRL_walk", 23, 12, 10, false, true);
	KEYANIMANAGER->addCoordinateFrameAnimation("SCHOOLGIRL_walkR", "SCHOOLGIRL_walk", 0, 11, 10, false, true);
	//뛰는 상태
	KEYANIMANAGER->addCoordinateFrameAnimation("SCHOOLGIRL_runL", "SCHOOLGIRL_run", 19, 10, 10, false, true);
	KEYANIMANAGER->addCoordinateFrameAnimation("SCHOOLGIRL_runR", "SCHOOLGIRL_run", 0, 9, 10, false, true);
	//스턴 상태
	KEYANIMANAGER->addCoordinateFrameAnimation("SCHOOLGIRL_stunL", "SCHOOLGIRL_stun", 7, 4, 10, false, true);
	KEYANIMANAGER->addCoordinateFrameAnimation("SCHOOLGIRL_stunR", "SCHOOLGIRL_stun", 0, 3, 10, false, true);
	
	//점프 상태
	
	int EleftJump[] = { 5,4,3,4,5 };
	int ErigthJump[] = { 0,1,2,1,0 };

	KEYANIMANAGER->addArrayFrameAnimation("SCHOOLGIRL_jumpL", "SCHOOLGIRL_jump", EleftJump, 5, 10, false);
	KEYANIMANAGER->addArrayFrameAnimation("SCHOOLGIRL_jumpR", "SCHOOLGIRL_jump", ErigthJump, 0, 10, false);
	//공격 상태1
	KEYANIMANAGER->addCoordinateFrameAnimation("SCHOOLGIRL_comboAttack1L", "SCHOOLGIRL_comboAttack1", 13, 7, 10, false, false);
	KEYANIMANAGER->addCoordinateFrameAnimation("SCHOOLGIRL_comboAttack1R", "SCHOOLGIRL_comboAttack1", 0, 6, 10, false, false);
	//공격 상태2
	KEYANIMANAGER->addCoordinateFrameAnimation("SCHOOLGIRL_comboAttack2L", "SCHOOLGIRL_comboAttack2", 15, 8, 10, false, false);
	KEYANIMANAGER->addCoordinateFrameAnimation("SCHOOLGIRL_comboAttack2R", "SCHOOLGIRL_comboAttack2", 0, 7, 10, false, false);
	//공격 상태3
	KEYANIMANAGER->addCoordinateFrameAnimation("SCHOOLGIRL_comboAttack3L", "SCHOOLGIRL_comboAttack3", 23, 12, 10, false, false);
	KEYANIMANAGER->addCoordinateFrameAnimation("SCHOOLGIRL_comboAttack3R", "SCHOOLGIRL_comboAttack3", 0, 11, 10, false, false);

	//점프 공격
	KEYANIMANAGER->addCoordinateFrameAnimation("SCHOOLGIRL_jumpAttackL", "SCHOOLGIRL_jumpAttack", 13, 7, 10, false, false);
	KEYANIMANAGER->addCoordinateFrameAnimation("SCHOOLGIRL_jumpAttackR", "SCHOOLGIRL_jumpAttack", 0, 6, 10, false, false);

	//피격 쓰러진 상태
	KEYANIMANAGER->addCoordinateFrameAnimation("SCHOOLGIRL_backdownL", "SCHOOLGIRL_backdown", 53, 27, 10, false, false);
	KEYANIMANAGER->addCoordinateFrameAnimation("SCHOOLGIRL_backdownR", "SCHOOLGIRL_backdown", 0, 26, 10, false, false);
	//방어 상태
	KEYANIMANAGER->addCoordinateFrameAnimation("SCHOOLGIRL_blockL", "SCHOOLGIRL_block", 5, 3, 10, false, false);
	KEYANIMANAGER->addCoordinateFrameAnimation("SCHOOLGIRL_blockR", "SCHOOLGIRL_block", 0, 2, 10, false, false);
	
	//피격 상태1
	KEYANIMANAGER->addCoordinateFrameAnimation("SCHOOLGIRL_gethit1L", "SCHOOLGIRL_gethit", 17, 15, 10, false, false);
	KEYANIMANAGER->addCoordinateFrameAnimation("SCHOOLGIRL_gethit1R", "SCHOOLGIRL_gethit", 0, 2, 10, false, false);
	//피격 상태2
	KEYANIMANAGER->addCoordinateFrameAnimation("SCHOOLGIRL_gethit2L", "SCHOOLGIRL_gethit", 14, 12, 10, false, false);
	KEYANIMANAGER->addCoordinateFrameAnimation("SCHOOLGIRL_gethit2R", "SCHOOLGIRL_gethit", 3, 5, 10, false, false);
	//피격 상태3
	KEYANIMANAGER->addCoordinateFrameAnimation("SCHOOLGIRL_gethit3L", "SCHOOLGIRL_gethit", 11, 9, 10, false, false);
	KEYANIMANAGER->addCoordinateFrameAnimation("SCHOOLGIRL_gethit3R", "SCHOOLGIRL_gethit", 6, 8, 10, false, false);
	
	//항복 상태
	KEYANIMANAGER->addCoordinateFrameAnimation("SCHOOLGIRL_beggingL", "SCHOOLGIRL_begging", 4, 3, 10, false, false);
	KEYANIMANAGER->addCoordinateFrameAnimation("SCHOOLGIRL_beggingR", "SCHOOLGIRL_begging", 1, 2, 10, false, false);
	//잡힌 후 피격 상태
	KEYANIMANAGER->addCoordinateFrameAnimation("SCHOOLGIRL_heldHitL", "SCHOOLGIRL_heldHit", 7, 4, 10, false, false);
	KEYANIMANAGER->addCoordinateFrameAnimation("SCHOOLGIRL_heldHitR", "SCHOOLGIRL_heldHit", 0, 3, 10, false, false);
	//잡힌 거 풀기 상태
	KEYANIMANAGER->addCoordinateFrameAnimation("SCHOOLGIRL_heldReleaseL", "SCHOOLGIRL_heldRelease", 7, 4, 10, false, false);
	KEYANIMANAGER->addCoordinateFrameAnimation("SCHOOLGIRL_heldReleaseR", "SCHOOLGIRL_heldRelease", 0, 3, 10, false, false);
}

void enemy::callBack(void* obj)
{
	enemy* play = (enemy*)obj;

	play->setEnemyState(new enemyIdle);
}
