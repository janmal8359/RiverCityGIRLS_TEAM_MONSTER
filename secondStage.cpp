#include "pch.h"
#include "secondStage.h"
#include "pixelCollisionClass.h"

secondStage::secondStage()
{
}

secondStage::~secondStage()
{
}

HRESULT secondStage::init()
{
	IMAGEMANAGER->findImage("STAGE_stage4");
	IMAGEMANAGER->findImage("BATTLE_unlockDoor1");
	IMAGEMANAGER->findImage("BATTLE_unlockDoor2");

	_player = new player;
	_player->init();

	_pixel = new pixelCollisionClass;

	_pixel->init(0, 0, 1);
	_pixel->setPixelPlayer(_player);

	return S_OK;
}

void secondStage::release()
{
}

void secondStage::update()
{
	_player->update();

	_player->getState()->setPlayer(_player);

	_pixel->setPixelPlayer(_player);
	_pixel->update();
}

void secondStage::render()
{
	IMAGEMANAGER->findImage("STAGE_stage4")->render(getMemDC(), 0, 0);

	if (KEYMANAGER->isToggleKey(VK_TAB))
	{
		_pixel->render();
	}

	_player->render();
}
