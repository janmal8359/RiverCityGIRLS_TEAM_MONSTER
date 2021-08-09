#include "pch.h"
#include "thirdStage.h"

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

	return S_OK;
}

void thirdStage::release()
{
}

void thirdStage::update()
{

}

void thirdStage::render()
{
	IMAGEMANAGER->findImage("STAGE_normal")->render(getMemDC(), 0, 0);
	//IMAGEMANAGER->findImage("STAGE_normalPixel")->render(getMemDC(), 0, 0);

}
