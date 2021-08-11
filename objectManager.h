#pragma once
#include "gameNode.h"
#include "crafting.h"
#include <vector>

class objectManager : public gameNode
{
private:
	typedef vector<object*>				vObject;
	typedef vector<object*>::iterator	viObject;

private:
	vObject		_vObject;
	viObject	_viObject;

public:
	objectManager();
	~objectManager();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	vector<object*> getVObject() { return _vObject; }
	vector<object*>::iterator getViObject() { return _viObject; }
};
