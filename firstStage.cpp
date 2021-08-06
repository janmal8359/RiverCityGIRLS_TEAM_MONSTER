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
	IMAGEMANAGER->findImage("STAGE_stagePixel1");
	IMAGEMANAGER->findImage("BATTLE_unlockDoor1");
	IMAGEMANAGER->findImage("BATTLE_unlockDoor2");
	return S_OK;
}

void firstStage::release()
{
}

void firstStage::update()
{
}

void firstStage::render()
{
	IMAGEMANAGER->findImage("STAGE_stagePixel1")->render(getMemDC(), 0, 0);
	IMAGEMANAGER->findImage("STAGE_stage1")->render(getMemDC(), 0, 0);
}
