#include "pch.h"
#include "idle.h"
#include "player.h"

HRESULT idle::init()
{
	_playerImg = IMAGEMANAGER->findImage("PLAYER_idle");
	_shadowImg = IMAGEMANAGER->findImage("SHADOW");
	


	
	KEYANIMANAGER->addCoordinateFrameAnimation("PLAYER_idleL", "PLAYER_idle", 0, 11, 20, false, true);

	KEYANIMANAGER->addCoordinateFrameAnimation("PLAYER_idleR", "PLAYER_idle", 23, 12, 20, false, true);

	_playerAni = KEYANIMANAGER->findAnimation("PLAYER_idleR");
	//플레이어의 왼쪽 Idle;
	//_playerAniL = new animation;
	//_playerAniL->newInit(_playerImg->getWidth(), _playerImg->getHeight(), 12, 2);
	//_playerAniL->setPlayFrame(0, 11, false, true);
	//_playerAniL->setFPS(30);

	////플레이어의 오른쪽 Idle;
	//_playerAniR = new animation;
	//_playerAniR->newInit(_playerImg->getWidth(), _playerImg->getHeight(), 12, 2);
	//_playerAniR->setPlayFrame(12, 23, false, true);
	//_playerAniR->setFPS(30);


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

	
	if (_dir == LEFT)
	{
		_playerAni = KEYANIMANAGER->findAnimation("PLAYER_idleL");

	}
	if (_dir == RIGHT)
	{
		_playerAni = KEYANIMANAGER->findAnimation("PLAYER_idleR");

	}

	_playerRc = RectMakeCenter(_sX, _sY - _playerImg->getFrameHeight() / 2, _playerImg->getFrameWidth(), _playerImg->getFrameHeight());
	KEYANIMANAGER->update();
}

void idle::render()
{
	_shadowImg->render(getMemDC(), _shadowRc.left, _shadowRc.top);

	_playerImg->aniRender(getMemDC(),_playerRc.left, _playerRc.top, _playerAni);
	_playerAni->resume();

	
}

void idle::move()
{
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		_dir = LEFT;
		_player->setWalk();

		if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
		{
			_isJump = true;
			_player->setJump();
		}
	
		

	}
	else if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		_dir = RIGHT;

		if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
		{
			_player->setJump();
		}
	
	
	}
	if (KEYMANAGER->isStayKeyDown(VK_UP))
	{


		if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
		{
			_isJump = true;
			_player->setJump();
		}

	}
	else if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
	

		if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
		{
			_isJump = true;
			_player->setJump();
		}
	
	}
}

void idle::aniChange()
{

}
