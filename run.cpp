#include "pch.h"
#include "run.h"
#include "player.h"

HRESULT run::init()
{
	_playerImg = IMAGEMANAGER->findImage("PLAYER_run");
	return S_OK;
}

void run::release()
{
}

void run::update()
{
	state::update();

	_playerImg = IMAGEMANAGER->findImage("PLAYER_run");
}

void run::render()
{
	state::render();
}

void run::stateChange()
{
    if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
    {
        //_player->setState(new jump);
    }
    if (KEYMANAGER->isOnceKeyDown('Q'))
    {
       // _player->setState(new atk);
    }
    if (KEYMANAGER->isOnceKeyUp(VK_LSHIFT))
    {
        _player->setState(new walk);
    }

    if (!KEYMANAGER->isStayKeyDown(VK_LEFT) &&
        !KEYMANAGER->isStayKeyDown(VK_RIGHT) &&
        !KEYMANAGER->isStayKeyDown(VK_UP) &&
        !KEYMANAGER->isStayKeyDown(VK_DOWN))
    {
        _player->setState(new idle);
    }
}

void run::ani()
{
    _player->setSpeed(8.0f);


    if (_dir == LEFT)
    {
        _playerAni = KEYANIMANAGER->findAnimation("PLAYER_runL");
        _playerAni->resume();
    }
    else if (_dir == RIGHT)
    {
        _playerAni = KEYANIMANAGER->findAnimation("PLAYER_runR");
        _playerAni->resume();
    }
}
