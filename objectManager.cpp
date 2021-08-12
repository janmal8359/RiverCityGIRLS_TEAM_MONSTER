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


}

void objectManager::render()
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
		case 0://Ã¥»ó
			{
				for (int j = 0; j < 2; j++)
				{
					object* object;
					object = new desk;
					//object->init(_object->getObjectOX() + (WINSIZEX / 2) - 150, _object->getObjectOY() + (WINSIZEY / 2) + (50 + 50 * j), 0);
					object->init(WINSIZEX / 2 - (150 - 100 * j), WINSIZEY / 2 + (50 + 100 * j), 0);
					_vObject.push_back(object);
				}
			}
			break;
		}

	}

}
