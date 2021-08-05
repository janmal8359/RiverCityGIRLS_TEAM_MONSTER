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
	
}
