#pragma once
#include "gameNode.h"
#include "object.h"
#include "desk.h"
#include "camera.h"
#include <vector>

class objectManager : public gameNode
{
private:
	typedef vector<object*>				vObject;
	typedef vector<object*>::iterator	viObject;

private:
	vObject		_vObject;
	viObject	_viObject;

	object* _object;

	camera* _camera;

public:
	objectManager();
	~objectManager();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	void setObject();

	vector<object*> getVObject() { return _vObject; }
	vector<object*>::iterator getViObject() { return _viObject; }

	void setObjectMemoryAddressLink(object* object) { _object = object; }
};
