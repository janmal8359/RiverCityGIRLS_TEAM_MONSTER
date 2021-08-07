#include "pch.h"
#include "stun.h"
#include "player.h"

HRESULT stun::init()
{
	return S_OK;
}

void stun::release()
{
}

void stun::update()
{
	state::update();
	_playerImg = IMAGEMANAGER->findImage("PLAYER_down");
}

void stun::render()
{
	state::render();
	_playerImg = IMAGEMANAGER->findImage("PLAYER_down");
}

void stun::stateChange()
{
}

void stun::ani()
{
}

void stun::callBk()
{
}
