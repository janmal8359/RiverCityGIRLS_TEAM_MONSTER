#include "pch.h"
#include "idle.h"
#include "player.h"

HRESULT idle::init()
{
	state::init();

	_playerImg = IMAGEMANAGER->findImage("PLAYER_idle");
	return S_OK;
}

void idle::release()
{
}

void idle::update()
{
	state::update();
	_playerImg = IMAGEMANAGER->findImage("PLAYER_idle");

}

void idle::render()
{
	state::render();


}

void idle::stateChange()
{
	// 이동키를 눌렀을 땐 플레이어 상태를 걷는 상태로 정의한다
	if (KEYMANAGER->isOnceKeyDown(VK_LEFT)  ||
		KEYMANAGER->isOnceKeyDown(VK_RIGHT) ||
		KEYMANAGER->isOnceKeyDown(VK_UP)	||
		KEYMANAGER->isOnceKeyDown(VK_DOWN))
	{
		_player->setState(new walk);
	}
    if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
	{
		_player->setState(new jump);
		_player->setJumpPower(20.0f);
	}
	else if (KEYMANAGER->isOnceKeyDown('Q'))
	{
		_player->setState(new atk);
	}

}

void idle::ani()
{
	_player->setSpeed(0.0f);

	if (_dir == LEFT)
	{
		_playerAni = KEYANIMANAGER->findAnimation("PLAYER_idleL");
		_playerAni->resume();
	}
	if (_dir == RIGHT)
	{
		_playerAni = KEYANIMANAGER->findAnimation("PLAYER_idleR");
		_playerAni->resume();
	}
}

