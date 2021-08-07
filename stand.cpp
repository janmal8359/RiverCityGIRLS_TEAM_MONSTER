#include "pch.h"
#include "stand.h"
#include "player.h"

HRESULT stand::init()
{
    _playerImg = IMAGEMANAGER->findImage("PLAYER_down");
    return S_OK;
}

void stand::release()
{
}

void stand::update()
{
    state::update();
    _playerImg = IMAGEMANAGER->findImage("PLAYER_down");
}

void stand::render()
{
    state::render();

}

void stand::stateChange()
{
}

void stand::ani()
{
}

void stand::callBk()
{
}
