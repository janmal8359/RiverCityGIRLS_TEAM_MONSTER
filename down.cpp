#include "pch.h"
#include "down.h"
#include "player.h"

HRESULT down::init()
{
	_playerImg =IMAGEMANAGER->findImage("PLAYER_down");
	return S_OK;
}

void down::release()
{
}

void down::update()
{
	state::update();
	_playerImg = IMAGEMANAGER->findImage("PLAYER_down");
}

void down::render()
{
	state::render();
}

void down::stateChange()
{
}

void down::ani()
{
}

void down::callBk()
{
}
