#pragma once
#include "gameNode.h"
#include "player.h"

class pixelCollisionClass;

//������(���� ��)
class bossStage2 : public gameNode
{
private:
	//������Ʈ ��
	image _object[6];
	RECT _rc;
	float _X, _Y;
	float _radius;
	float _angle;
	float _speed;
	float _gravity;
	int _alphaValue;

	player* _player;

	pixelCollisionClass* _pixel;

	bool _isBreak;

public:
	bossStage2();
	~bossStage2();
	
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	void setPlayer(player* player) { _player = player; }

	void setpixelCollisionClassMemoryAddressLink(pixelCollisionClass* pixel) { _pixel = pixel; }
};

