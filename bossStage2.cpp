#include "pch.h"
#include "bossStage2.h"
#include "pixelCollisionClass.h"

bossStage2::bossStage2()
{
}

bossStage2::~bossStage2()
{
}

HRESULT bossStage2::init()
{
	_isBreak = false;

	IMAGEMANAGER->findImage("OBJECT_backPillar");
	IMAGEMANAGER->findImage("OBJECT_firstPillar");
	IMAGEMANAGER->findImage("OBJECT_particle1");
	IMAGEMANAGER->findImage("OBJECT_particle2");
	IMAGEMANAGER->findImage("OBJECT_particle3");
	IMAGEMANAGER->findImage("STAGE_bossStage2");
	//IMAGEMANAGER->findImage("STAGE_bossPixel");

	_player = new player;
	_player->init();

	_pixel = new pixelCollisionClass;

	_pixel->init(0, 0, 3);
	_pixel->setPixelPlayer(_player);

	return S_OK;
}

void bossStage2::release()
{
}

void bossStage2::update()
{
	_player->update();

	_player->getState()->setPlayer(_player);

	_pixel->setPixelPlayer(_player);
	_pixel->update();

}

void bossStage2::render()
{
	IMAGEMANAGER->findImage("STAGE_bossStage2")->render(getMemDC(), 0, 0);
	//IMAGEMANAGER->findImage("STAGE_bossPixel")->render(getMemDC(), 0, 0);

	if (KEYMANAGER->isToggleKey(VK_TAB))
	{
		_pixel->render();
	}

	_player->render();
}
