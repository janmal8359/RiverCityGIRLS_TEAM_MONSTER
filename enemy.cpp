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
	_enemyY = _enemySY - _enemyImg->getFrameHeight() / 2 - 30;

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

	//exRc = RectMakeCenter(ex.x, ex.y, 100, 100);	//연습용
	//
	//if(KEYMANAGER->isStayKeyDown('Y')) ex.x -= 5;
	//if(KEYMANAGER->isStayKeyDown('T')) ex.x += 5;

	_enemyState->setEnemy(this);

	enemyMove();


	_enemyState->update();
	_enemyImg = _enemyState->getEnemyImg();
}

void enemy::render()
{

	char str1[128];
	sprintf_s(str1, "적과 플레이어거리 : %.2f", _enemyDistance);
	TextOut(getMemDC(), _enemySX, _enemySY + 50, str1, strlen(str1));

	_enemyShadowImg->render(getMemDC(), _enemyShadowRc.left, _enemyShadowRc.top);
	_enemyState->render();

	//Rectangle(getMemDC(), exRc);

	

}

void enemy::enemyStateRender(animation* motion)
{

	_enemyImg->aniRender(getMemDC(), _enemyRc.left, _enemyRc.top, motion);

}

void enemy::enemyMove()
{
	_enemyDistance = getDistance(_player->getShadowX(), _player->getShadowY(), _enemySX + _enemyShadowImg->getFrameWidth(), _enemySY);


	if (_enemyDistance < 500 )	//쫒아가는거
	{
		
		_enemySX = _enemyX;
		_enemyX -= cosf(getAngle(_player->getShadowX(), _player->getShadowY(), _enemySX, _enemySY)) * _enemySpeed;

		_enemySY = _enemyY + _enemyImg->getFrameHeight() / 2 + 30;
		_enemyY -= -sin(getAngle(_player->getShadowX(), _player->getShadowY(), _enemySX, _enemySY)) * _enemySpeed;
	
	}



	 


	_enemyRc = RectMakeCenter(_enemyX, _enemyY, _enemyImg->getFrameWidth(), _enemyImg->getFrameWidth());
	_enemyShadowRc = RectMakeCenter(_enemySX, _enemySY, _enemyShadowImg->getWidth(), _enemyShadowImg->getHeight());
}



void enemy::enemyAni()
{
	KEYANIMANAGER->addCoordinateFrameAnimation("SCHOOLGIRL_idleL", "SCHOOLGIRL_idle", 0, 9, 10, false, true);
	KEYANIMANAGER->addCoordinateFrameAnimation("SCHOOLGIRL_idleR", "SCHOOLGIRL_idle", 19, 10, 10, false, true);

	KEYANIMANAGER->addCoordinateFrameAnimation("SCHOOLGIRL_walkL", "SCHOOLGIRL_walk", 23, 12, 10, false, true);
	KEYANIMANAGER->addCoordinateFrameAnimation("SCHOOLGIRL_walkR", "SCHOOLGIRL_walk", 0, 11, 10, false, true);

	KEYANIMANAGER->addCoordinateFrameAnimation("SCHOOLGIRL_runL", "SCHOOLGIRL_run", 19, 10, 10, false, true);
	KEYANIMANAGER->addCoordinateFrameAnimation("SCHOOLGIRL_runR", "SCHOOLGIRL_run", 0, 9, 10, false, true);
}

void enemy::callBack(void* obj)
{
	enemy* play = (enemy*)obj;

	play->setEnemyState(new enemyIdle);
}
