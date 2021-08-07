#include "pch.h"
#include "hit.h"
#include "player.h"

HRESULT hit::init()
{
	_playerImg = IMAGEMANAGER->findImage("PLAYER_grab");
	return S_OK;
}

void hit::release()
{
}

void hit::update()
{
	state::update();
	_playerImg = IMAGEMANAGER->findImage("PLAYER_grab");
}

void hit::render()
{
	state::render();
}

void hit::stateChange()
{
}

void hit::ani()
{
}

void hit::callBk()
{
}
