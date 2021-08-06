#include "pch.h"
#include "atk.h"
#include "player.h"

HRESULT atk::init()
{
	return S_OK;
}

void atk::release()
{
}

void atk::update()
{
	state::update();

	if (KEYMANAGER->isOnceKeyDown('Q') && _attackIdx < 2)
	{
		if (_playerAni->getNowPlayIdx() >= _playerImg->getMaxFrameX())
		{

		}
	}

	switch (_attackIdx)
	{
	case 1:
		_playerImg = IMAGEMANAGER->findImage("PLAYER_comboAttack1");
		break;
	case 2:
		_playerImg = IMAGEMANAGER->findImage("PLAYER_comboAttack1");
		break;
	case 3:
		_playerImg = IMAGEMANAGER->findImage("PLAYER_comboAttack1");
		break;
	default:
		break;
	}


	
	
}

void atk::render()
{
	state::render();
}

void atk::stateChange()
{
}

void atk::ani()
{
	if (_dir == LEFT)
	{
		switch (_attackIdx)
		{
		case 1:
			_playerAni = KEYANIMANAGER->findAnimation("PLAYER_1atkL");
			break;
		case 2:
			_playerAni = KEYANIMANAGER->findAnimation("PLAYER_2atkL");
			break;
		case 3:
			_playerAni = KEYANIMANAGER->findAnimation("PLAYER_3atkL");
			break;

		default:
			break;
		}

	}
	else if (_dir == RIGHT)
	{
		switch (_attackIdx)
		{
		case 1:
			_playerAni = KEYANIMANAGER->findAnimation("PLAYER_1atkR");
			break;
		case 2:
			_playerAni = KEYANIMANAGER->findAnimation("PLAYER_2atkR");
			break;
		case 3:
			_playerAni = KEYANIMANAGER->findAnimation("PLAYER_3atkR");
			break;

		default:
			break;
		}
	}
}
