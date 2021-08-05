#include "pch.h"
#include "walk.h"
#include "player.h"

HRESULT walk::init()
{
    _playerImg = IMAGEMANAGER->findImage("PLAYER_walk");
    return S_OK;
}

void walk::release()
{
}

void walk::update()
{
    state::update();
    _playerImg = IMAGEMANAGER->findImage("PLAYER_walk");
}

void walk::render()
{
     state::render();
}

void walk::stateChange()
{
    if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
    {
        _player->setJumpPower(20.0f);
       // _player->setState(new jump);
    }

    //모든 버튼은 때면 idle로 돌아가는구문
    if (!KEYMANAGER->isStayKeyDown(VK_LEFT)  &&
        !KEYMANAGER->isStayKeyDown(VK_RIGHT) &&
        !KEYMANAGER->isStayKeyDown(VK_UP)    &&
        !KEYMANAGER->isStayKeyDown(VK_DOWN))
    {
        _player->setState(new idle);
    }
}

void walk::ani()
{
    _player->setSpeed(5.0f);

    if (!_player->getIsJump())
    {
        if (_dir == LEFT)
        {
            _playerAni = KEYANIMANAGER->findAnimation("PLAYER_walkL");
            _playerAni->resume();
        }
        else if (_dir == RIGHT)
        {
            _playerAni = KEYANIMANAGER->findAnimation("PLAYER_walkR");
            _playerAni->resume();
        }

    }
}

