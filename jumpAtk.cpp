#include "pch.h"
#include "jumpAtk.h"
#include "player.h"

HRESULT jumpAtk::init()
{
	_playerImg = IMAGEMANAGER->findImage("PLAYER_grab");
	return S_OK;
}

void jumpAtk::release()
{
}

void jumpAtk::update()
{
	state::update();
	_playerImg = IMAGEMANAGER->findImage("PLAYER_grab");
}

void jumpAtk::render()
{
	state::render();
}

void jumpAtk::stateChange()
{
}

void jumpAtk::ani()
{
}

void jumpAtk::callBk()
{
}
