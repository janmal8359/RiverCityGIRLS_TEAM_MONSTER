#include "pch.h"
#include "playGround.h"

playGround::playGround()
{
}


playGround::~playGround()
{
}

//초기화는 여기에다 해라!!!
HRESULT playGround::init()
{
	gameNode::init(true);

	_imageStorage = new imageStorage;
	_imageStorage->init();

	//_sfxStorage = new sfxStorage;
	//_sfxStorage->init();

	_gameManager = new gameManager;
	_gameManager->init();



	SCENEMANAGER->addScene("imageStorage", _imageStorage);

	//스테이지(씬 매니저)
	SCENEMANAGER->addScene("stage1", new firstStage);
	SCENEMANAGER->addScene("stage2", new secondStage);
	SCENEMANAGER->addScene("stage3", new thirdStage);
	SCENEMANAGER->addScene("bossStage1", new bossStage1);
	SCENEMANAGER->addScene("bossStage2", new bossStage2);
	SCENEMANAGER->changeScene("stage1");

	//SOUNDMANAGER->play("")

	return S_OK;
}

//메모리 해제는 여기다 해라!!!!
void playGround::release()
{
	gameNode::release();

	_gameManager->release();
}

//연산처리는 여기다가!
void playGround::update()
{
	gameNode::update();

	_gameManager->update();

	/*if (KEYMANAGER->isOnceKeyDown('4'))
	{
		SCENEMANAGER->changeScene("stage1");
	}
	if (KEYMANAGER->isOnceKeyDown('5'))
	{
		SCENEMANAGER->changeScene("stage2");
	}
	if (KEYMANAGER->isOnceKeyDown('6'))
	{
		SCENEMANAGER->changeScene("stage3");
	}
	if (KEYMANAGER->isOnceKeyDown('7'))
	{
		SCENEMANAGER->changeScene("bossStage1");
	}
	if (KEYMANAGER->isOnceKeyDown('8'))
	{
		SCENEMANAGER->changeScene("bossStage2");
	}*/

	//스테이지(씬 매니저)
	SCENEMANAGER->update();
}

//여기다 그려줘라!!!
void playGround::render()
{
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//==============위에는 제발 건드리지 마라 ============

	//스테이지(씬 매니저)
	SCENEMANAGER->render();

	_gameManager->render();

	//=============== 밑에도 건들지마라 ================
	_backBuffer->render(getHDC(), 0, 0);
}