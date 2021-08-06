#include "pch.h"
#include "bossStage2.h"

bossStage2::bossStage2()
{
}

bossStage2::~bossStage2()
{
}

HRESULT bossStage2::init()
{
	IMAGEMANAGER->findImage("OBJECT_backPillar");
	IMAGEMANAGER->findImage("OBJECT_firstPillar");
	IMAGEMANAGER->findImage("OBJECT_particle1");
	IMAGEMANAGER->findImage("OBJECT_particle2");
	IMAGEMANAGER->findImage("OBJECT_particle3");
	IMAGEMANAGER->findImage("STAGE_bossStage2");
	IMAGEMANAGER->findImage("STAGE_bossPixel");

	return S_OK;
}

void bossStage2::release()
{
}

void bossStage2::update()
{
}

void bossStage2::render()
{
	IMAGEMANAGER->findImage("STAGE_bossPixel")->render(getMemDC(), 0, 0);
	IMAGEMANAGER->findImage("STAGE_bossStage2")->render(getMemDC(), 0, 0);
}
