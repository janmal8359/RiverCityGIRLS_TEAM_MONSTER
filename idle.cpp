#include "pch.h"
#include "idle.h"
#include "player.h"

HRESULT idle::init()
{
	_playerImg = IMAGEMANAGER->findImage("PLAYER_idle");
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
