#include "pch.h"
#include "walk.h"
#include "player.h"

HRESULT walk::init()
{
  


	KEYANIMANAGER->addCoordinateFrameAnimation("PLAYER_walkL", "PLAYER_walk", 11, 0, 10, false, true, this);
	KEYANIMANAGER->addCoordinateFrameAnimation("PLAYER_walkR", "PLAYER_walk", 12, 23, 10, false, true, this);
	
	_speed = 5.0f;


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

