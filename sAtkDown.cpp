#include "pch.h"
#include "sAtkDown.h"
#include "player.h"

HRESULT sAtkDown::init()
{
	_playerImg = IMAGEMANAGER->findImage("PLAYER_down");
	return S_OK;
}

void sAtkDown::release()
{
}

void sAtkDown::update()
{
	state::update();
	_playerImg = IMAGEMANAGER->findImage("PLAYER_down");
}

void sAtkDown::render()
{
	state::render();
}

void sAtkDown::stateChange()
{
}

void sAtkDown::ani()
{
}

void sAtkDown::callBk()
{
}
