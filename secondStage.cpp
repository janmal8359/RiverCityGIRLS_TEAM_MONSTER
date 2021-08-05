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
	
}
