#include "pch.h"
#include "playGround.h"

playGround::playGround()
{
}


playGround::~playGround()
{
}

//�ʱ�ȭ�� ���⿡�� �ض�!!!
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

	//��������(�� �Ŵ���)
	SCENEMANAGER->addScene("stage1", new firstStage);
	SCENEMANAGER->addScene("stage2", new secondStage);
	SCENEMANAGER->addScene("stage3", new thirdStage);
	SCENEMANAGER->addScene("bossStage1", new bossStage1);
	SCENEMANAGER->addScene("bossStage2", new bossStage2);
	SCENEMANAGER->changeScene("stage1");

	//SOUNDMANAGER->play("")

	return S_OK;
}

//�޸� ������ ����� �ض�!!!!
void playGround::release()
{
	gameNode::release();

	_gameManager->release();
}

//����ó���� ����ٰ�!
void playGround::update()
{
	gameNode::update();

	_gameManager->update();

	EFFECTMANAGER->update();

	if (KEYMANAGER->isOnceKeyDown('4'))
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
	}
	//if (KEYMANAGER->isStayKeyDown(VK_LBUTTON))
	//{
	//	//_ef->startEffect(WINSIZEX / 2, WINSIZEY / 2);
	//	IMAGEMANAGER->addFrameImage("smash", "resources/IMG/effect/Boss smash.bmp", 960, 89, 10, 1, true, RGB(255, 0, 255));
	//	IMAGEMANAGER->frameRender("smash", getMemDC(), WINSIZEX / 2, WINSIZEY / 2);
	//}

	//��������(�� �Ŵ���)
	SCENEMANAGER->update();
}

//����� �׷����!!!
void playGround::render()
{
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//==============������ ���� �ǵ帮�� ���� ============

	//��������(�� �Ŵ���)
	SCENEMANAGER->render();

	_gameManager->render();

	//EFFECTMANAGER->render();

	//=============== �ؿ��� �ǵ������� ================
	_backBuffer->render(getHDC(), 0, 0);
}