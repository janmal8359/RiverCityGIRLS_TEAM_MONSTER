#include "pch.h"
#include "thirdStage.h"
#include "pixelCollisionClass.h"

thirdStage::thirdStage()
{
}

thirdStage::~thirdStage()
{
}

HRESULT thirdStage::init()
{
	IMAGEMANAGER->findImage("STAGE_normal");
	//IMAGEMANAGER->findImage("STAGE_normalPixel");
	IMAGEMANAGER->findImage("BATTLE_unlockDoor1");
	IMAGEMANAGER->findImage("BATTLE_unlockDoor2");

	_player = new player;
	_player->init();

	_pixel = new pixelCollisionClass;

	_pixel->init(0, 0, 2);
	_pixel->setPixelPlayer(_player);

	return S_OK;
}

void thirdStage::release()
{
}

void thirdStage::update()
{
	_player->update();

	_player->getState()->setPlayer(_player);

	_pixel->setPixelPlayer(_player);
	_pixel->update();
}

void thirdStage::render()
{
	IMAGEMANAGER->findImage("STAGE_normal")->render(getMemDC(), 0, 0);
	//IMAGEMANAGER->findImage("STAGE_normalPixel")->render(getMemDC(), 0, 0);

	if (KEYMANAGER->isToggleKey(VK_TAB))
	{
		_pixel->render();
	}

	_player->render();
}
