#include "pch.h"
#include "walk.h"
#include "player.h"

HRESULT walk::init()
{
    
	_playerImg = IMAGEMANAGER->findImage("PLAYER_walk");
	_shadowImg = IMAGEMANAGER->findImage("SHADOW");

	KEYANIMANAGER->addCoordinateFrameAnimation("PLAYER_walkL", "PLAYER_walk", 11, 0, 10, false, true, this);
	KEYANIMANAGER->addCoordinateFrameAnimation("PLAYER_walkR", "PLAYER_walk", 12, 23, 10, false, true, this);
	
	_speed = 5.0f;

    return S_OK;
}

void walk::release()
{
}

void walk::update()
{
	move();

	if (_dir == LEFT)
	{
		_playerAni = KEYANIMANAGER->findAnimation("PLAYER_walkL");

	}
	if (_dir == RIGHT)
	{
		_playerAni = KEYANIMANAGER->findAnimation("PLAYER_walkR");
	}


	
	_playerAni->resume();
	KEYANIMANAGER->update();
}

void walk::render()
{
	
	_playerImg->aniRender(getMemDC(), _playerRc.left, _playerRc.top, _playerAni);
	_shadowImg->render(getMemDC(), _shadowRc.left, _shadowRc.top);
}

void walk::move()
{
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		_dir = LEFT;
		_sX -= _speed;

		if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
		{
			_isJump = true;
			_player->setJump();
		}
	}
	else if (KEYMANAGER->isOnceKeyUp(VK_LEFT))
	{
		_player->setIdle();
	}
	else if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		_dir = RIGHT;
		_sX += _speed;
		
		if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
		{
			_player->setJump();
		}
	}
	else if (KEYMANAGER->isOnceKeyUp(VK_RIGHT))
	{
		_player->setIdle();
	}
	if (KEYMANAGER->isStayKeyDown(VK_UP))
	{

		_sY -= _speed;

		if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
		{
			_isJump = true;
			_player->setJump();
		}

	}
	else if (KEYMANAGER->isOnceKeyUp(VK_UP))
	{
		_player->setIdle();
	}

	else if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		_sY += _speed;

		if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
		{
			_isJump = true;
			_player->setJump();
		}

	}
	else if (KEYMANAGER->isOnceKeyUp(VK_DOWN))
	{
		_player->setIdle();
	}
}
