#include "pch.h"
#include "player.h"
 

player::player()
{
}

player::~player()
{
}

HRESULT player::init()
{

    _imgStorage = new imageStorage;
    _imgStorage->init();

    playerAni();

    _state = new idle;
    _state->init();

    //플레이어 의 이미지와 그림자 이미지
    _playerImg = _state->getPlImg();
    _shadowImg = IMAGEMANAGER->findImage("SHADOW");

    //그림자의 초기 좌표값 및 중점
    _sX = WINSIZEX / 2;
    _sY = WINSIZEY / 2;

    _pX = _sX; // 플레이어의 x는 그림자X값과 같다.
    _pY = _sY - _playerImg->getFrameHeight() / 2;

    _playerRc = RectMakeCenter(_pX, _pY, _playerImg->getFrameWidth(), _playerImg->getFrameHeight());
    _shadowRc = RectMakeCenter(_sX, _sY, _shadowImg->getWidth(), _shadowImg->getHeight());

    _speed = 0;
    _jumpPower = 0;

    _isJump = false;



    return S_OK;
}

void player::release()
{

    
}

void player::update()
{
    _state->setPlayer(this);

    move();

    _state->update();
    _playerImg = _state->getPlImg();


}

void player::render()
{
   _shadowImg->render(getMemDC(), _shadowRc.left, _shadowRc.top);
    _state->render();
}

void player::stateRender(animation* motion)
{
    _playerImg->aniRender(getMemDC(), _playerRc.left, _playerRc.top, motion);
}

void player::move()
{
    if (KEYMANAGER->isStayKeyDown(VK_LEFT)) _dir = LEFT;
    if (KEYMANAGER->isStayKeyDown(VK_RIGHT)) _dir = RIGHT;
    if (KEYMANAGER->isStayKeyDown(VK_UP))
        if (KEYMANAGER->isStayKeyDown(VK_DOWN))
            if (KEYMANAGER->isStayKeyDown(VK_SPACE)) _isJump = true;




   _playerRc = RectMakeCenter(_pX, _pY, _playerImg->getFrameWidth(), _playerImg->getFrameHeight());
    _shadowRc = RectMakeCenter(_sX, _sY, _shadowImg->getWidth(), _shadowImg->getHeight());

}



void player::playerAni()
{
    KEYANIMANAGER->addCoordinateFrameAnimation("PLAYER_idleL", "PLAYER_idle", 11, 0, 10, false, true);
    KEYANIMANAGER->addCoordinateFrameAnimation("PLAYER_idleR", "PLAYER_idle", 23, 12, 10, false, true);

    //KEYANIMANAGER->addCoordinateFrameAnimation("PLAYER_walkL", "PLAYER_walk", 11, 0, 10, false, true);
    //KEYANIMANAGER->addCoordinateFrameAnimation("PLAYER_walkR", "PLAYER_walk", 23, 12, 10, false, true);

    //KEYANIMANAGER->addCoordinateFrameAnimation("PLAYER_runL", "PLAYER_run", 11, 0, 10, false, true);
    //KEYANIMANAGER->addCoordinateFrameAnimation("PLAYER_runR", "PLAYER_run", 23, 12, 10, false, true);

    //KEYANIMANAGER->addCoordinateFrameAnimation("PLAYER_atkL", "PLAYER_atk", 11, 0, 10, false, true);
    //KEYANIMANAGER->addCoordinateFrameAnimation("PLAYER_atkR", "PLAYER_atk", 23, 12, 10, false, true);

}

void player::callBack(void* obj)
{
    player* play = (player*)obj;
   
    play->setState(new idle);
}


