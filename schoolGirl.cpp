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

	IMAGEMANAGER->frameRender("SCHOOLGIRL_idle",getMemDC(), _rc.left, _rc.top);

}
