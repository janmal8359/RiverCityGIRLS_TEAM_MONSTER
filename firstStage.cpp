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
	
}
