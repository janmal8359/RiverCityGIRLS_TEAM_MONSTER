#include "pch.h"
#include "sAtk.h"
#include "player.h"

HRESULT sAtk::init()
{
	_playerImg = IMAGEMANAGER->findImage("PLAYER_down");
	return S_OK;
}

void sAtk::release()
{
}

void sAtk::update()
{
	state::update();
	_playerImg = IMAGEMANAGER->findImage("PLAYER_down");
}

void sAtk::render()
{
	state::render();
}

void sAtk::stateChange()
{
}

void sAtk::ani()
{
}

void sAtk::callBk()
{
}
