#include "pch.h"
#include "objectManager.h"

objectManager::objectManager()
{
}

objectManager::~objectManager()
{
}

HRESULT objectManager::init()
{
	return S_OK;
}

void objectManager::release()
{
}

void objectManager::update()//값 true
{
	for (_viObject = _vObject.begin(); _viObject != _vObject.end(); ++_viObject)
	{
		(*_viObject)->update();
	}


}

void objectManager::render()//값 false
{
	for (_viObject = _vObject.begin(); _viObject != _vObject.end(); ++_viObject)
	{
		(*_viObject)->render();
	}
}

void objectManager::setObject()
{
	int num = 0;

	for (int i = 0; i < 6; i++)
	{
		switch (num)
		{
		case 0://책상
			{
				for (int j = 0; j < 2; j++)
				{
					object* object;
					object = new desk;
					object->init(1028 - j * 200, 665 + j * 200, DESK);
					_vObject.push_back(object);
				}
			}
			break;
		}

	}

}
