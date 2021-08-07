#include "pch.h"
#include "guard.h"
#include "player.h"

HRESULT guard::init()
{
	_playerImg = IMAGEMANAGER->findImage("PLAYER_grab");
	return S_OK;
}

void guard::release()
{

}

void guard::update()
{
	state::update();
	_playerImg = IMAGEMANAGER->findImage("PLAYER_grab");
}

void guard::render()
{
	state::render();
}

void guard::stateChange()
{
}

void guard::ani()
{
}

void guard::callBk()
{
}
