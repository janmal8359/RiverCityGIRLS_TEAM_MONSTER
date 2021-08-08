#include "pch.h"
#include "player.h"
#include "boss.h"

player::player()
{
}

player::~player()
{
}

HRESULT player::init()
{
    playerAni();

    _state = new idle;
    _state->init();

    //_imageStorage = new imageStorage;
   // _imageStorage->init();

    //�÷��̾� �� �̹����� �׸��� �̹���
    _playerImg = _state->getPlImg();
    _shadowImg = IMAGEMANAGER->findImage("SHADOW");

    //�׸����� �ʱ� ��ǥ�� �� ����
    _sX = WINSIZEX / 2;
    _sY = WINSIZEY / 2;

    _pX = _sX; // �÷��̾��� x�� �׸���X���� ����.
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
    //_bState->setPlayer(this);       // ������ �÷��̾� ��ġ �� �޾ƿ��� ��

    move();

    _state->update();
    _playerImg = _state->getPlImg();
}

void player::render()
{
    _shadowImg->render(getMemDC(), _shadowRc.left, _shadowRc.top);
    _state->render();

    char str[128];
    sprintf_s(str, " _isJump : %d", _isJump);
    TextOut(getMemDC(), 0, 200, str, strlen(str));

    sprintf_s(str, "shadowX : %.2f", _sX);
    TextOut(getMemDC(), 0, 10, str, strlen(str));
}

void player::stateRender(animation* motion)
{
    _playerImg->aniRender(getMemDC(), _playerRc.left, _playerRc.top, motion);
}

void player::move()
{
    //�������°� �ƴҶ�
    if (!_isJump)
    {
        if (KEYMANAGER->isStayKeyDown(VK_SPACE)) _isJump = true;

        if (KEYMANAGER->isStayKeyDown(VK_LEFT))
        {
            _dir = LEFT;
            _sX -= _speed;
        }
        
        if (KEYMANAGER->isStayKeyDown(VK_RIGHT)) 
        {
            _dir = RIGHT;
            _sX += _speed;
        }
        if (KEYMANAGER->isStayKeyDown(VK_UP))
        {
            _sY -= _speed;
        }
        if (KEYMANAGER->isStayKeyDown(VK_DOWN))
        {
            _sY += _speed;
        }

        _pX = _sX;
        _pY = _sY - _playerImg->getFrameHeight() / 2;
    }
    else if (_isJump)
    {
        if (_playerRc.bottom <= _sY) //
        {
            _pX = _sX;
            _pY -= _jumpPower;
            _jumpPower -= GRAVITY;
        }
        else
        {
            _pY = _sY - _playerImg->getFrameHeight() / 2;
            _isJump = false;
        }

        if (KEYMANAGER->isStayKeyDown(VK_LEFT))
        {
            _dir = LEFT;
            _sX -= _speed;
        }

        if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
        {
            _dir = RIGHT;
            _sX += _speed;
        }
        if (KEYMANAGER->isStayKeyDown(VK_UP))
        {
            _pY -= _speed;
            _sY -= _speed;
        }
        if (KEYMANAGER->isStayKeyDown(VK_DOWN))
        {
            _pY += _speed;
            _sY += _speed;
        }
    }



    _playerRc = RectMakeCenter(_pX, _pY, _playerImg->getFrameWidth(), _playerImg->getFrameHeight());
    _shadowRc = RectMakeCenter(_sX, _sY, _shadowImg->getWidth(), _shadowImg->getHeight());

}



void player::playerAni()
{
    KEYANIMANAGER->addCoordinateFrameAnimation("PLAYER_idleL", "PLAYER_idle", 11, 0, 10, false, true);
    KEYANIMANAGER->addCoordinateFrameAnimation("PLAYER_idleR", "PLAYER_idle", 23, 12, 10, false, true);

    KEYANIMANAGER->addCoordinateFrameAnimation("PLAYER_walkL", "PLAYER_walk", 11, 0, 10, false, true);
    KEYANIMANAGER->addCoordinateFrameAnimation("PLAYER_walkR", "PLAYER_walk", 12, 23, 10, false, true);

    KEYANIMANAGER->addCoordinateFrameAnimation("PLAYER_runL", "PLAYER_run", 15, 0, 20, false, true);
    KEYANIMANAGER->addCoordinateFrameAnimation("PLAYER_runR", "PLAYER_run", 16, 31, 20, false, true);

    int leftJump[] = { 0, 1, 2, 1, 0 };
    int rightJump[] = { 5, 4, 3, 4, 5 };

    KEYANIMANAGER->addArrayFrameAnimation("PLAYER_jumpL", "PLAYER_jump", leftJump, 5, 10, false);
    KEYANIMANAGER->addArrayFrameAnimation("PLAYER_jumpR", "PLAYER_jump", rightJump, 5, 10, false);

    //�޺����ݾִϸ��̼�
    KEYANIMANAGER->addCoordinateFrameAnimation("PLAYER_1atkL", "PLAYER_comboAttack1", 5, 0, 10, false, false);
    KEYANIMANAGER->addCoordinateFrameAnimation("PLAYER_1atkR", "PLAYER_comboAttack1", 6, 11, 10, false,false);
                                                                                                    
    KEYANIMANAGER->addCoordinateFrameAnimation("PLAYER_2atkL", "PLAYER_comboAttack2", 6, 0, 10, false, false);
    KEYANIMANAGER->addCoordinateFrameAnimation("PLAYER_2atkR", "PLAYER_comboAttack2", 7, 13, 10, false,false);
                                                                                                    
    KEYANIMANAGER->addCoordinateFrameAnimation("PLAYER_3atkL", "PLAYER_comboAttack3", 8, 0, 10, false, false);
    KEYANIMANAGER->addCoordinateFrameAnimation("PLAYER_3atkR", "PLAYER_comboAttack3", 9, 17, 10, false,false);

    KEYANIMANAGER->addCoordinateFrameAnimation("PLAYER_dashAttackL", "PLAYER_dashAttack", 7, 0, 10, false, false);
    KEYANIMANAGER->addCoordinateFrameAnimation("PLAYER_dashAttackR", "PLAYER_dashAttack", 8, 15, 10, false, false);

    KEYANIMANAGER->addCoordinateFrameAnimation("PLAYER_dashSAttackL", "PLAYER_dashSAttack", 0, 20, 10, false, false);
    KEYANIMANAGER->addCoordinateFrameAnimation("PLAYER_dashSAttackR", "PLAYER_dashSAttack", 41, 21, 10, false, false);
}                                                                

void player::callBack(void* obj)
{
    player* play = (player*)obj;
   
    play->setState(new idle);
}


