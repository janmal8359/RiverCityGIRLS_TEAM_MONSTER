#pragma once
#include "gameNode.h"


enum stageImg
{
	FIRST_STAGE,
	SECOND_STAGE,
	THIRD_STAGE,
	BOSS_STAGE1,
	BOSS_STAGE2,
};





class camera : public gameNode
{

private:
	stageImg _stageImg;

	RECT _cameraRc;

	int  _stage;


	image* _backGroundImg;
	image* _pixelImg;


	float _camXrc, _camYrc;



	 
public:

	 HRESULT init();
	 void release();
	 void update();
	 void render();


	 float getCamX() { return _camXrc; }
	 float getCamY() { return _camYrc; }

	 RECT getCameraRc() { return _cameraRc; }


	 
};

