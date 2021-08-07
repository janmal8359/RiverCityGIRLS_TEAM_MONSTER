#include "pch.h"
#include "die.h"
#include "player.h"

HRESULT die::init()
{
    _playerImg = IMAGEMANAGER->findImage("PLAYER_die");
    return S_OK;
}

void die::release()
{
}

void die::update()
{
    die::update();

    _playerImg = IMAGEMANAGER->findImage("PLAYER_die");
}

void die::render()
{
    die::render();
}

void die::stateChange()
{
}

void die::ani()
{
}
