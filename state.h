#pragma once
#include "gameNode.h"
#include "animation.h"

#define GRAVITY 0.3f;

class player;					//���漱��

enum dir
{
	LEFT,
	RIGHT
};

class state : public gameNode
{
protected:
	
	image* _playerImg;
	int _dir;

	animation* _playerAni;

	

	float _jump = 10.0f;

	player* _player;
	RECT _playerRc;

public:

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	virtual void stateChange() {};
	virtual void ani() {};


	virtual void setPlayer(player* player) { _player = player; }

	//������ // ������
	
	virtual animation* getPlayerAni() { return _playerAni; }
	virtual image* getPlImg() { return _playerImg; }

	//�����Ŀ� ��������
	virtual float getJumpPower() { return _jump; }


	

	

};

