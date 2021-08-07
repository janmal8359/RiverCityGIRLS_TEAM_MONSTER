#include "pch.h"
#include "secondStage.h"

secondStage::secondStage()
{
}

secondStage::~secondStage()
{
}

HRESULT secondStage::init()
{
	IMAGEMANAGER->findImage("STAGE_stage4");
	IMAGEMANAGER->findImage("STAGE_stagePixel4");
	IMAGEMANAGER->findImage("BATTLE_unlockDoor1");
	IMAGEMANAGER->findImage("BATTLE_unlockDoor2");

	return S_OK;
}

void secondStage::release()
{
}

void secondStage::update()
{
}

void secondStage::render()
{
	IMAGEMANAGER->findImage("STAGE_stage4")->render(getMemDC(), 0, 0);
	IMAGEMANAGER->findImage("STAGE_stagePixel4")->render(getMemDC(), 0, 0);
}
