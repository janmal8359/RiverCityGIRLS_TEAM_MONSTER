#include "pch.h"
#include "schoolGirl.h"

schoolGirl::schoolGirl()
{
}

schoolGirl::~schoolGirl()
{
}

HRESULT schoolGirl::init()
{

	IMAGEMANAGER->addFrameImage("SCHOOLGIRL_idle", "Resource/IMG/character/enemy/schoolGirl/idle.bmp", 1170, 354, 10, 2, true, RGB(255, 0, 255));					//±âº»

	_rc = RectMakeCenter(100,100, 100, 100);

	return S_OK;
}
void schoolGirl::release()
{
	
}

void schoolGirl::update()
{
}

void schoolGirl::render()
{
	Rectangle(getMemDC(), _rc);

	IMAGEMANAGER->frameRender("SCHOOLGIRL_idle", getMemDC(), _rc.left, _rc.top);

}
