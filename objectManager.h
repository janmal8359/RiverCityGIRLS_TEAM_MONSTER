#pragma once
#include "gameNode.h"
#include "desk.h"
#include "player.h"
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

	camera* _camera;

	player* _player;

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
	 
	void setPlayerMemoryAddressLink(player* player) { _player = player; }

	void setCameraMemoryAddressLink(camera* camera) { _camera = camera; }
};
