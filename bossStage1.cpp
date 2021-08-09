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
	_isCheck = false;
	_isNextCount = false;
	_isStop = false;

	IMAGEMANAGER->findImage("STAGE_bossStage1");
	//IMAGEMANAGER->findImage("STAGE_bossPixel");

	_x = 800;
	_y = WINSIZEY / 2;

	_rc = RectMakeCenter(_x, _y, 10, 1080);


	return S_OK;
}

void bossStage1::release()
{
}

void bossStage1::update()
{
	/*
	if(player.rc.right >= 790)
	{
		_isCheck = true;
		_isNextCount = true;
		_isStop = true;
	}
	*/

}

void bossStage1::render()
{
	IMAGEMANAGER->findImage("STAGE_bossStage1")->render(getMemDC(), 0, 0);
	//IMAGEMANAGER->findImage("STAGE_bossPixel")->render(getMemDC(), 0, 0);

	/*
	if(_isCheck)
	{
	videoPlay
	}
	*/
}
