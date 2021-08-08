#include "pch.h"
#include "pixelCollision.h"

pixelCollision::pixelCollision()
{
}

pixelCollision::~pixelCollision()
{
}

HRESULT pixelCollision::init()
{
	_probeLX = _player->getShadowX() - _player->getShadowImg()->getWidth() / 2;
	_probeRX = _player->getShadowX() + _player->getShadowImg()->getWidth() / 2;
	_probeTY = _player->getShadowY() - _player->getShadowImg()->getHeight() / 2;
	_probeBY = _player->getShadowY() + _player->getShadowImg()->getHeight() / 2;

	_firstStage = IMAGEMANAGER->findImage("STAGE_stagePixel1");
	_secondStage = IMAGEMANAGER->findImage("STAGE_stagePixel4");
	_thirdStage = IMAGEMANAGER->findImage("STAGE_normalPixel");
	_bossStage = IMAGEMANAGER->findImage("STAGE_bossPixel");

	return S_OK;
}

void pixelCollision::release()
{
}

void pixelCollision::update()
{
	Colloision();
}

void pixelCollision::render()
{
}

void pixelCollision::Colloision()
{
	for (int i = _probeLX - 5; i < _probeRX + 5; i++)
	{
		COLORREF color = GetPixel(_first->getMemDC(), i, _player->getShadowY());
	
		int R = GetRValue(color);
		int G = GetGValue(color);
		int B = GetBValue(color);
	
		if (!(R == 255 && G == 0 && B == 255))
		{
			//벽
			if (R == 255 && G == 0 && B == 0)//레드
			{
				_player->setSpeed(0);
			}
			//책상 바닥
			else if ((R == 0 && G == 255 && B == 0))//그린
			{
				//_player->setShadowX(+8);
				//_player->setSpeed(6);
				_player->setSpeed(0);
			}
			//아이콘 출현 구간
			else if (R == 0 && G == 255 && B == 255)//민트
			{
				_player->setSpeed(6);
	
			}
			//그 이외
			else
			{
				_player->setSpeed(1);
			}
		}
		else
		{
			_player->setSpeed(6);
		}
	}
	
	for (int i = _probeTY - 5; i < _probeBY + 5; i++)
	{
		COLORREF color = GetPixel(_first->getMemDC(), _player->getShadowX(), i);
	
		int R = GetRValue(color);
		int G = GetGValue(color);
		int B = GetBValue(color);
	
		if (!(R == 255 && G == 0 && B == 255))
		{
			//벽
			if (R == 255 && G == 0 && B == 0)//레드
			{
				_player->setSpeed(0);
			}
			//책상 바닥
			else if ((R == 0 && G == 255 && B == 0))//그린
			{
				//_player->setShadowY(-8);
				//_player->setSpeed(6);
				_player->setSpeed(0);
			}
			//아이콘 출현 구간
			else if (R == 0 && G == 255 && B == 255)//민트
			{
				_player->setSpeed(1);
	
			}
			//그 이외
			else
			{
				_player->setSpeed(6);
			}
		}
		else
		{
			_player->setSpeed(6);
		}
	}
}
