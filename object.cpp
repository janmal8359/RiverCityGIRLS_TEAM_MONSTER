#include "pch.h"
#include "object.h"

object::object()
{
}

object::~object()
{
}

HRESULT object::init()
{
	return S_OK;
}

HRESULT object::init(float x, float y, int objectType)
{
	_objectType = (OBJECTTYPE)objectType;

	if (_objectType == 0)_objectImg = IMAGEMANAGER->findImage("OBJECT_desk1");

	_objectMX = 600;
	_objectMY = 300;

	_objectOX = _objectMX;
	_objectOY = _objectMY - (_objectImg->getHeight() / 2);

	_objectRc = RectMakeCenter(_objectOX, _objectOY, _objectImg->getWidth(), _objectImg->getHeight());
	
	return S_OK;
}

void object::release()
{
}

void object::update()
{
	_objectRc = RectMakeCenter(_objectOX, _objectOY, _objectImg->getWidth(), _objectImg->getHeight());
}

void object::render()
{
	_objectImg->render(getMemDC(), _objectRc.left, _objectRc.top);
}
