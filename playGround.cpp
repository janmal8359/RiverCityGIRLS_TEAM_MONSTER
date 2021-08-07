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

	_imgStorage = new imageStorage;
	_imgStorage->init();

	_player = new player;
	_player->init();

	_boss = new boss;
	_boss->init();

	_enemy = new enemy;
	_enemy->init();
	
	SCENEMANAGER->addScene("SG", new schoolGirl);
	SCENEMANAGER->changeScene("SG");

	//스테이지(다이랙트)
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
	//스테이지(씬 매니저)
	//SCENEMANAGER->addScene("stageNum", new firstStage);
	//SCENEMANAGER->changeScene("stageNum");
	
	return S_OK;
}

//메모리 해제는 여기다 해라!!!!
void playGround::release()
{
	gameNode::release();


}

//연산처리는 여기다가!
void playGround::update()
{
	gameNode::update();

	//스테이지(다이랙트)
	//_stage1->update();
	//_stage2->update();
	//_stage3->update();
	//_stage4->update();
	//_stage5->update();
	//스테이지(씬 매니저)
	//SCENEMANAGER->update();

	_player->update();

	_player->getState()->setPlayer(_player);

	_boss->update();

	_enemy->update();
	_enemy->getEnemyState()->setEnemy(_enemy);
	
	//testCollision();
}

//여기다 그려줘라!!!
void playGround::render()
{
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//==============위에는 제발 건드리지 마라 ============

	_boss->render();

	//스테이지(다이랙트)
	//_stage1->render();
	//_stage2->render();
	//_stage3->render();
	//_stage4->render();
	//_stage5->render();
	//스테이지(씬 매니저)
	SCENEMANAGER->render();

	_player->render();
	_enemy->render();


	//=============== 밑에도 건들지마라 ================
	_backBuffer->render(getHDC(), 0, 0);

}
/*
void playGround::testCollision()
{
	_probeLX = _player->getShadowX() - 64;
	_probeRX = _player->getShadowX() + 64;
	_probeTY = _player->getShadowY() - 19;
	_probeBY = _player->getShadowY() + 19;

	//벽 충돌
	for (int i = _probeLX; i < _probeRX; i++)
	{
		COLORREF color = GetPixel(_stage1->getMemDC(), -200, -200);

		int R = GetRValue(color);
		int G = GetGValue(color);
		int B = GetBValue(color);

		float _speed = _player->getSpeed();

		if ((R == 255 && G == 0 && B == 255))
		{
			_speed = 0;
		}
	}

	for (int i = _probeTY; i < _probeBY; i++)
	{
		COLORREF color = GetPixel(_stage1->getMemDC(), -200, -200);

		int R = GetRValue(color);
		int G = GetGValue(color);
		int B = GetBValue(color);

		float _speed = _player->getSpeed();

		if ((R == 255 && G == 0 && B == 255))
		{
			_speed = 0;
		}
	}
}
*/