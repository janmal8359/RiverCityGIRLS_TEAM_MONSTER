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
	_IS = new imageStorage;
	_IS->init();


	enemyAni();

	_ES = new enemyIdle;
	_ES->init();

	_enemyImg = _ES->getEnemyImg();
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
	
	
	ex.x = 500;
	ex.y = 500;

	

	return S_OK;
}

void enemy::release()
{
}

void enemy::update()
{

	exRc = RectMakeCenter(ex.x, ex.y, 100, 100);	//연습용
	


	_ES->setEnemy(this);

	enemyMove();
	enemyChase();

	_ES->update();
	_enemyImg = _ES->getEnemyImg();
}

void enemy::render()
{

	char str1[128];
	sprintf_s(str1, "스피드 : %f", _enemySpeed);
	TextOut(getMemDC(), 100, 500, str1, strlen(str1));

	_enemyShadowImg->render(getMemDC(), _enemyShadowRc.left, _enemyShadowRc.top);
	_ES->render();

	Rectangle(getMemDC(), exRc);

	

}

void enemy::enemyStateRender(animation* motion)
{

	_enemyImg->aniRender(getMemDC(), _enemyRc.left, _enemyRc.top, motion);

}

void enemy::enemyMove()
{
	if (getDistance(ex.x, ex.y, _enemyX, _enemyY) > 10)					//쫒아가는거
	{
		
		_enemySX = _enemyX;
		_enemyX -= cosf(getAngle(ex.x, ex.y, _enemyX, _enemyY)) * 2;

		_enemySY = _enemyY + _enemyImg->getFrameHeight() / 2 + 30;
		_enemyY -= -sin(getAngle(ex.x, ex.y, _enemyX, _enemyY)) * 2;
	
	}



	//if (_enemySpeed > 0.01) _enemySpeed -= _enemyRes;
	//else _enemySpeed = 0;
	//
	//if (_enemySpeed >= 6.0f) _enemySpeed = 6.0;
	//
	//if (_enemyDir == 0)
	//{
	//	_enemySX -= _enemySpeed;
	//	_enemyX -= _enemySpeed;
	//}
	//else
	//{
	//	_enemySX += _enemySpeed;
	//	_enemyX += _enemySpeed;
	//}

	_enemyRc = RectMakeCenter(_enemyX, _enemyY, _enemyImg->getFrameWidth(), _enemyImg->getFrameWidth());
	_enemyShadowRc = RectMakeCenter(_enemySX, _enemySY, _enemyShadowImg->getWidth(), _enemyShadowImg->getHeight());
}

void enemy::enemyChase()
{


}

void enemy::enemyAni()
{
	KEYANIMANAGER->addCoordinateFrameAnimation("SCHOOLGIRL_idleL", "SCHOOLGIRL_idle", 0, 9, 10, false, true);
	KEYANIMANAGER->addCoordinateFrameAnimation("SCHOOLGIRL_idleR", "SCHOOLGIRL_idle", 19, 10, 10, false, true);

	KEYANIMANAGER->addCoordinateFrameAnimation("SCHOOLGIRL_walkL", "SCHOOLGIRL_walk", 23, 12, 10, false, true);
	KEYANIMANAGER->addCoordinateFrameAnimation("SCHOOLGIRL_walkR", "SCHOOLGIRL_walk", 11, 0, 10, false, true);
}

void enemy::callBack(void* obj)
{
	enemy* play = (enemy*)obj;

	play->setEnemyState(new enemyIdle);
}
