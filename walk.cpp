#include "pch.h"
#include "walk.h"
#include "player.h"

HRESULT walk::init()
{
  


    return S_OK;
}

void walk::release()
{
}

void walk::update()
{
    //state::update();
  //  _playerImg = IMAGEMANAGER->findImage("PLAYER_walk");
}

void walk::render()
{
 //   state::render();
}

void walk::stateChange()
{
    //if (KEYMANAGER->isOnceKeyDown(VK_LEFT) ||
    //    KEYMANAGER->isOnceKeyDown(VK_RIGHT) ||
    //    KEYMANAGER->isOnceKeyDown(VK_UP) ||
    //    KEYMANAGER->isOnceKeyDown(VK_DOWN))
    //{

    //}
}

void walk::ani()
{
  /*  _player->setSpeed(5.0f);

    if (_dir == LEFT)
    {
        _playerAni = KEYANIMANAGER->findAnimation("PLAYER_walkL");
        _playerAni->resume();
    }
    else if (_dir == RIGHT)
    {
        _playerAni = KEYANIMANAGER->findAnimation("PLAYER_walkR");
        _playerAni->resume();
    }*/
}

