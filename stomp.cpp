#include "pch.h"
#include "stomp.h"
#include "player.h"

HRESULT stomp::init()
{
	_playerImg = IMAGEMANAGER->findImage("PLAYER_down");
	return S_OK;
}

void stomp::release()
{
}

void stomp::update()
{
	state::update();
	_playerImg = IMAGEMANAGER->findImage("PLAYER_down");
}

void stomp::render()
{
	state::render();
}

void stomp::stateChange()
{
}

void stomp::ani()
{
}

void stomp::callBk()
{
}
