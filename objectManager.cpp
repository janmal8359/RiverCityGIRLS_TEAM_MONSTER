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

void objectManager::update()
{
	for (_viObject = _vObject.begin(); _viObject != _vObject.end(); ++_viObject)
	{
		(*_viObject)->update();
	}

	//for (int i = 0; i < _objectManager->getVObject().size; ++i) - _objectManager 변수명 선언 시
	//{

	//}
}

void objectManager::render()
{
	for (_viObject = _vObject.begin(); _viObject != _vObject.end(); ++_viObject)
	{
		(*_viObject)->render();
	}

	//for (int i = 0; i < _objectManager->getVObject().size; ++i) - _objectManager 변수명 선언 시
	//{

	//}
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
