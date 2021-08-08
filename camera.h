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

	image* _backGroundImg;
	image* _pixelImg;

	float _camX, _camY;




public:

	 HRESULT init();
	 void release();
	 void update(float playerX,float playerY);
	 void render();


};

