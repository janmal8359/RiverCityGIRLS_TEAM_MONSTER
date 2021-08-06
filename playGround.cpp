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

	_imgStorage = new imageStorage;
	_imgStorage->init();

	SCENEMANAGER->addScene("SG", new schoolGirl);
	SCENEMANAGER->changeScene("SG");

	//_stage1 = new firstStage;
	//_stage1->init();
	//_stage2 = new secondStage;
	//_stage2->init();
	//_stage3 = new thirdStage;
	//_stage3->init();
	//_stage4 = new bossStage1;
	//_stage4->init();
	//_stage5 = new bossStage2;
	//_stage5->init();
	//SCENEMANAGER->addScene("stageNum", new stageManager);
	//SCENEMANAGER->changeScene("stageNum");

	_player = new player;
	_player->init();
	
	return S_OK;
}

//�޸� ������ ����� �ض�!!!!
void playGround::release()
{
	gameNode::release();


}

//����ó���� ����ٰ�!
void playGround::update()
{
	gameNode::update();

	//_stage1->update();
	//_stage2->update();
	//_stage3->update();
	//_stage4->update();
	//_stage5->update();

	_player->update();

	_player->getState()->setPlayer(_player);

	
}

//����� �׷����!!!
void playGround::render()
{
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//==============������ ���� �ǵ帮�� ���� ============
	


	//_stage1->render();
	//_stage2->render();
	//_stage3->render();
	//_stage4->render();
	//_stage5->render();

	_player->render();


	//=============== �ؿ��� �ǵ������� ================
	_backBuffer->render(getHDC(), 0, 0);

}

