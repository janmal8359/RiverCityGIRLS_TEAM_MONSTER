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

	_player = new player;
	_player->init();

	_boss = new boss;
	_boss->init();

	_enemy = new enemy;
	_enemy->init();
	_enemy->setPlayerMemoryLink(_player);				//플레이어 연동

	_isCheck = false;

	return S_OK;
}

void firstStage::release()
{
}

void firstStage::update()
{
	_player->update();

	_player->getState()->setPlayer(_player);

	_boss->update();

	_enemy->update();
	_enemy->getEnemyState()->setEnemy(_enemy);
	

	//pixelCollision();
}

void firstStage::render()
{
	IMAGEMANAGER->findImage("STAGE_stage1")->render(getMemDC(), 0, 0);
	
	if (KEYMANAGER->isToggleKey(VK_TAB))
	{
		_first->render(getMemDC(), 0, 0);
	}

	_player->render();
	_enemy->render();
	_boss->render();
}

void firstStage::pixelCollision()
{
	//그림자 4개의 꼭지점
	//(_sX - 64, _sY - (_shadowRc.top + _shadowRc.bottom) / 2 <- {19}),		좌측 상단
	//(_sX - 64, _sY + (_shadowRc.top + _shadowRc.bottom) / 2 <- {19}),		좌측 하단
	//(_sX + 64, _sY - (_shadowRc.top + _shadowRc.bottom) / 2 <- {19}),		우측 상단
	//(_sX + 64, _sY + (_shadowRc.top + _shadowRc.bottom) / 2 <- {19})		우측 하단
	//_player->getShadowX(), _player->getShadowY();									확인용

	_probeLX = _player->getShadowX() - _player->getShadowImg()->getWidth() / 2;
	_probeRX = _player->getShadowX() + _player->getShadowImg()->getWidth() / 2;
	_probeTY = _player->getShadowY() - _player->getShadowImg()->getHeight() / 2;
	_probeBY = _player->getShadowY() + _player->getShadowImg()->getHeight() / 2;


	////벽 충돌
	for (int i = _probeLX - 5; i < _probeLX; i++)
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

	for (int i = _probeRX; i < _probeLX + 5; i++)
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
				//_player->setShadowX(-8);
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

	for (int i = _probeTY - 5; i < _probeTY; i++)
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


	for (int i = _probeBY; i < _probeBY + 2; i++)
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
				//_player->setShadowY(+8);
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