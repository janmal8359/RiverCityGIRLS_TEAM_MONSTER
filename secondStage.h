#pragma once
#include "gameNode.h"
#include "player.h"

class pixelCollisionClass;

//±³¹«½Ç
class secondStage : public gameNode
{
private:
	bool _isCheck;
	bool _isNextCount;

	player* _player;

	pixelCollisionClass* _pixel;

public:
	secondStage();
	~secondStage();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	void setPlayer(player* player) { _player = player; }

	void setpixelCollisionClassMemoryAddressLink(pixelCollisionClass* pixel) { _pixel = pixel; }
};

