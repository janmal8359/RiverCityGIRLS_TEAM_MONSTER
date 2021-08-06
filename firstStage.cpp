#include "pch.h"
#include "firstStage.h"

firstStage::firstStage()
{
}

firstStage::~firstStage()
{
}

HRESULT firstStage::init()
{
	IMAGEMANAGER->findImage("STAGE_stage1");
	_first = IMAGEMANAGER->findImage("STAGE_stagePixel1");
	IMAGEMANAGER->findImage("BATTLE_unlockDoor1");
	IMAGEMANAGER->findImage("BATTLE_unlockDoor2");



	return S_OK;
}

void firstStage::release()
{
}

void firstStage::update()
{
	pixelCollision();
}

void firstStage::render()
{
	IMAGEMANAGER->findImage("STAGE_stagePixel1")->render(getMemDC(), 0, 0);
	IMAGEMANAGER->findImage("STAGE_stage1")->render(getMemDC(), 0, 0);
}

void firstStage::pixelCollision()
{
	
	//�׸��� 4���� ������
	//(_sX - 64, _sY - (_shadowRc.top + _shadowRc.bottom) / 2 <- {19}),		���� ���
	//(_sX - 64, _sY + (_shadowRc.top + _shadowRc.bottom) / 2 <- {19}),		���� �ϴ�
	//(_sX + 64, _sY - (_shadowRc.top + _shadowRc.bottom) / 2 <- {19}),		���� ���
	//(_sX + 64, _sY + (_shadowRc.top + _shadowRc.bottom) / 2 <- {19})		���� �ϴ�
	//_pl->getShadowX(), _pl->getShadowY();									Ȯ�ο�

	_probeLX = _pl->getShadowX() - 64;
	_probeRX = _pl->getShadowX() + 64;		
	_probeTY = _pl->getShadowY() - 19;
	_probeBY = _pl->getShadowY() + 19;

	//�� �浹
	for (int i = _probeLX; i < _probeRX; i++)
	{
		COLORREF color = GetPixel(_first->getMemDC(), 0, 0);

		int R = GetRValue(color);
		int G = GetGValue(color);
		int B = GetBValue(color);
		
		float _speed = _pl->getSpeed();

		if ((R == 255 && G == 0 && B == 255))
		{
			_speed = 0;
		}
	}

	for (int i = _probeTY; i < _probeBY; i++)
	{
		COLORREF color = GetPixel(_first->getMemDC(), 0, 0);

		int R = GetRValue(color);
		int G = GetGValue(color);
		int B = GetBValue(color);

		float _speed = _pl->getSpeed();

		if ((R == 255 && G == 0 && B == 255))
		{
			_speed = 0;
		}
	}
	//==============================!��!��!==============================

}
