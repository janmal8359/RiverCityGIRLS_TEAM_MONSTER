#include "pch.h"
#include "idle.h"
#include "player.h"

HRESULT idle::init()
{
	_playerImg = IMAGEMANAGER->findImage("PLAYER_idle");

	_playerAniL = new animation;
	_playerAniL->init(_playerImg->getWidth(), _playerImg->getHeight(), 12, 2);
	_playerAniL->setPlayFrame(5, 0, false, false);
	_playerAniL->setFPS(1);



	return S_OK;
}

void idle::release()
{
}

void idle::update()
{
}

void idle::render()
{
}
