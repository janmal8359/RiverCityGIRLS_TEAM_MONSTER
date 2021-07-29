#pragma once
#include "gameNode.h"
#include "animation.h"

#define JUMPPOWER 4.0f;
#define GRAVITY 0.3f;

class player;					//전방선언

enum dir
{
	LEFT,
	RIGHT
};

class state
{
private:

	image* _img;
	int    _dir;
	animation* _playerAni;



	player* _player;

public:

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	static void callBack(void* obj);

	virtual void setPlayer(player* player) { _player = player; }
};

