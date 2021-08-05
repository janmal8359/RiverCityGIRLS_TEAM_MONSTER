#include "pch.h"
#include "bossStage1.h"

bossStage1::bossStage1()
{
}

bossStage1::~bossStage1()
{
}

HRESULT bossStage1::init()
{
	IMAGEMANAGER->findImage("STAGE_bossStage1");
	IMAGEMANAGER->findImage("STAGE_bossPixel");

	return S_OK;
}

void bossStage1::release()
{
}

void bossStage1::update()
{
}

void bossStage1::render()
{
	IMAGEMANAGER->findImage("STAGE_bossPixel")->render(getMemDC(), 0, 0);
	IMAGEMANAGER->findImage("STAGE_bossStage1")->render(getMemDC(), 0, 0);
}
