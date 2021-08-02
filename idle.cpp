#include "pch.h"
#include "idle.h"
#include "player.h"

HRESULT idle::init()
{
	_playerImg = IMAGEMANAGER->findImage("PLAYER_idle");
	_shadowImg = IMAGEMANAGER->findImage("SHADOW");
	//플레이어의 왼쪽 Idle;
	_playerAniL = new animation;
	_playerAniL->init(_playerImg->getWidth(), _playerImg->getHeight(), 12, 2);
	_playerAniL->setPlayFrame(0, 11, false, false);
	_playerAniL->setFPS(1);

	//플레이어의 오른쪽 Idle;
	_playerAniR = new animation;
	_playerAniR->init(_playerImg->getWidth(), _playerImg->getHeight(), 12, 2);
	_playerAniR->setPlayFrame(12, 23, false, false);
	_playerAniR->setFPS(1);


	_sX = WINSIZEX / 2;
	_sY = WINSIZEY / 2;

	_pX = _sX;
	_pY = _sY - _playerImg->getFrameHeight() / 2;


	_playerRc = RectMakeCenter(_pX, _pY, _playerImg->getFrameWidth(), _playerImg->getFrameHeight());
	_shadowRc = RectMakeCenter(_sX, _sY, _shadowImg->getWidth(), _shadowImg->getHeight());



	return S_OK;
}

void idle::release()
{
}

void idle::update()
{
	move();
	aniChange();

	_playerAniL->frameUpdate(TIMEMANAGER->getElapsedTime() * 0.5f);
	_playerAniR->frameUpdate(TIMEMANAGER->getElapsedTime() * 0.5f);

	_playerRc = RectMakeCenter(_sX, _sY - _playerImg->getFrameHeight() / 2, _playerImg->getFrameWidth(), _playerImg->getFrameHeight());
}

void idle::render()
{
	if (_dir == LEFT)   _playerImg->aniRender(getMemDC(), _playerRc.left, _playerRc.top, _playerAniL);
	if (_dir == RIGHT)  _playerImg->aniRender(getMemDC(), _playerRc.left, _playerRc.top, _playerAniR);
}

void idle::move()
{
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		_dir = LEFT;
		_playerAniL->stop();
	}
	else if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		_dir = RIGHT;
		_playerAniR->stop();
	}
	if (KEYMANAGER->isStayKeyDown(VK_UP))
	{
		_playerAniL->stop();
		_playerAniR->stop();
	}
	else if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		_playerAniL->stop();
		_playerAniR->stop();

	}
}

void idle::aniChange()
{
}
