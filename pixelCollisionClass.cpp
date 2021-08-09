#include "pch.h"
#include "pixelCollisionClass.h"

pixelCollisionClass::pixelCollisionClass()
{
}

pixelCollisionClass::~pixelCollisionClass()
{
}

HRESULT pixelCollisionClass::init()
{

	return S_OK;
}

HRESULT pixelCollisionClass::init(float x, float y, int stageType)
{
	_probeLX = _player->getShadowX() - _player->getShadowImg()->getWidth() / 2;
	_probeRX = _player->getShadowX() + _player->getShadowImg()->getWidth() / 2;
	_probeTY = _player->getShadowY() - _player->getShadowImg()->getHeight() / 2;
	_probeBY = _player->getShadowY() + _player->getShadowImg()->getHeight() / 2;

	//_firstStage = IMAGEMANAGER->findImage("STAGE_stagePixel1");
	//_secondStage = IMAGEMANAGER->findImage("STAGE_stagePixel4");
	//_thirdStage = IMAGEMANAGER->findImage("STAGE_normalPixel");
	//_bossStage = IMAGEMANAGER->findImage("STAGE_bossPixel");

	_stageType = (STAGETYPE)stageType;
	
	if (_stageType == 0) _stage = IMAGEMANAGER->findImage("STAGE_stagePixel1");
	if (_stageType == 1) _stage = IMAGEMANAGER->findImage("STAGE_stagePixel4");
	if (_stageType == 2) _stage = IMAGEMANAGER->findImage("STAGE_normalPixel");
	if (_stageType == 3) _stage = IMAGEMANAGER->findImage("STAGE_bossPixel");

	_x = x;
	_y = y;
	_rc = RectMakeCenter(_x, _y, _stage->getWidth(), _stage->getHeight());

	return S_OK;
}

void pixelCollisionClass::release()
{
}

void pixelCollisionClass::update()
{
	Colloision();
}

void pixelCollisionClass::render()
{

	if(_stage != NULL) _stage->render(getMemDC(), _rc.left, _rc.top);
	//_stage->render(getMemDC(), _rc.left, _rc.top);
}

void pixelCollisionClass::Colloision()
{
	
	for (int _stageType = 0; _stageType < 4; _stageType++)
	{

		for (int i = _probeLX - 5; i < _probeRX + 5; i++)
		{
			COLORREF color = GetPixel(_stage->getMemDC(), i, _player->getShadowY());

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
			COLORREF color = GetPixel(_stage->getMemDC(), _player->getShadowX(), i);

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
}
