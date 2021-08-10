#include "pch.h"
#include "bossStage1.h"
#include "pixelCollisionClass.h"

bossStage1::bossStage1()
{
}

bossStage1::~bossStage1()
{
}

HRESULT bossStage1::init()
{
	_isCheck = false;
	_isNextCount = false;
	_isStop = false;

	IMAGEMANAGER->findImage("STAGE_bossStage1");
	//IMAGEMANAGER->findImage("STAGE_bossPixel");

	_x = 800;
	_y = WINSIZEY / 2;

	_rc = RectMakeCenter(_x, _y, 10, 1080);

	_player = new player;
	_player->init();

	_pixel = new pixelCollisionClass;

	_pixel->init(0, 0, 3);
	_pixel->setPixelPlayer(_player);

	return S_OK;
}

void bossStage1::release()
{
}

void bossStage1::update()
{
	/*
	if(player.rc.right >= 790)
	{
		_isCheck = true;
		_isNextCount = true;
		_isStop = true;
	}
	*/

	_player->update();

	_player->getState()->setPlayer(_player);

	_pixel->setPixelPlayer(_player);
	_pixel->update();

}

void bossStage1::render()
{
	IMAGEMANAGER->findImage("STAGE_bossStage1")->render(getMemDC(), 0, 0);
	//IMAGEMANAGER->findImage("STAGE_bossPixel")->render(getMemDC(), 0, 0);

	/*
	if(_isCheck)
	{
	videoPlay
	}
	*/

	if (KEYMANAGER->isToggleKey(VK_TAB))
	{
		_pixel->render();
	}

	_player->render();

}
