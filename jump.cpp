#include "pch.h"
#include "jump.h"
#include "player.h"

HRESULT jump::init()
{
	


	return S_OK;
}

void jump::release()
{
}

void jump::update()
{
	state::update();
	_playerImg = IMAGEMANAGER->findImage("PLAYER_jump");

	
}

void jump::render()
{
	state::render();
}

void jump::stateChange()
{
	if (_player->getJumpPower() < 0 && !_player->getIsJump())
	{
		if (KEYMANAGER->isStayKeyDown(VK_LEFT) ||
			KEYMANAGER->isStayKeyDown(VK_LEFT) ||
			KEYMANAGER->isStayKeyDown(VK_LEFT) ||
			KEYMANAGER->isStayKeyDown(VK_LEFT))
		{

		}

	}
}

void jump::ani()
{
}

