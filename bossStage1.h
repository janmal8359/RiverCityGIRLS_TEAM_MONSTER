#pragma once
#include "gameNode.h"
#include "player.h"

class pixelCollisionClass;

//������(���� ��)
class bossStage1 : public gameNode
{
private:
	//������Ʈ
	float _X, _Y;

	//�浹��
	RECT _rc;
	float _x, _y;
	bool _isCheck;
	bool _isNextCount;
	bool _isStop;

	player* _player;

	pixelCollisionClass* _pixel;

public:
	bossStage1();
	~bossStage1();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	void setPlayer(player* player) { _player = player; }

	void setpixelCollisionClassMemoryAddressLink(pixelCollisionClass* pixel) { _pixel = pixel; }
};

