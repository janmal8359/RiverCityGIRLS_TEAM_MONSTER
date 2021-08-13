#pragma once
#include "gameNode.h"
#include "firstStage.h"
#include "secondStage.h"
#include "thirdStage.h"
#include "bossStage1.h"
#include "bossStage2.h"
#include "camera.h"

class player;

enum PlayerDir
{
	PLAYERLEFT,
	PLAYERRIGHT
};

enum STAGETYPE
{
	FIRSTSTAGE,
	SECONDSTAGE,
	THIRDSTAGE,
	BOSSSTAGE
};

class pixelCollisionClass : public gameNode
{
private:
	image* _stage;				//�������� Ÿ�Կ� ���� ��������

	STAGETYPE _stageType;		//�������� Ÿ��

	player* _player;

	firstStage*		_first;
	secondStage*	_second;
	thirdStage*		_third;
	bossStage1*		_boss1;
	bossStage2*		_boss2;

	camera* _camera;

	RECT _probeLBox, _probeRBox, _probeTBox, _probeBBox;

	RECT _rc;
	float _x, _y;

	//�ȼ� Ž����
	float _probeLX, _probeTY, _probeRX, _probeBY;

	//player ����
	int _dir;

public:
	pixelCollisionClass();
	~pixelCollisionClass();

	virtual HRESULT init();
	virtual HRESULT init(float x, float y, int type);
	virtual void release();
	virtual void update();
	virtual void render();

	void Colloision();

	void setPixelPlayer(player* player) { _player = player; }

	inline RECT getRect() { return _rc; }
	int getPixelType() { return (int)_stageType; }

	void setfIRSTSTAGEMemoryAddressLink(firstStage* first) { _first = first; }
	void setSECONDSTAGEMemoryAddressLink(secondStage* second) { _second = second; }
	void setTHIRDSTAGEMemoryAddressLink(thirdStage* third) { _third = third; }
	void setBOSSSTAGE1MemoryAddressLink(bossStage1* boss1) { _boss1 = boss1; }
	void setBOSSSTAGE2MemoryAddressLink(bossStage2* boss2) { _boss2 = boss2; }
	void setCAMERAMemoryAddressLink(camera* camera) { _camera = camera; }
};