#include "pch.h"
#include "firstStage.h"
#include "pixelCollisionClass.h"

firstStage::firstStage()
{
}

firstStage::~firstStage()
{
}

HRESULT firstStage::init()
{
	IMAGEMANAGER->findImage("STAGE_stage1");
	//_first = IMAGEMANAGER->findImage("STAGE_stagePixel1");
	IMAGEMANAGER->findImage("BATTLE_unlockDoor1");
	IMAGEMANAGER->findImage("BATTLE_unlockDoor2");
	
	

	
	_boss = new boss;
	_boss->setPlayerMemoryAddressLink(_player);
	_boss->init();

	_enemy = new enemy;
	_enemy->init();
	
	_camera = new camera;
	_camera->init();
	_camera->setStage(1);
	
	_player = new player;
	_player->init();
	_player->setCamera(_camera);



	_enemy->setPlayerMemoryLink(_player);				//�÷��̾� ����

	_zO = new zOrder;
	_zO->init();
	
	_zO->setPlayer(_player);
	_zO->setBoss(_boss);
	_zO->setEnemy(_enemy);


	_isCheck = false;

	_pixel = new pixelCollisionClass;

	_pixel->init(0, 0, 0);
	_pixel->setPixelPlayer(_player);



	return S_OK; 
}

void firstStage::release()
{
}

void firstStage::update()
{
	_player->update();

	_player->getState()->setPlayer(_player);

	_boss->setPlayerMemoryAddressLink(_player);
	_boss->update();

	//_pixel->setPixelPlayer(_player);
	//_pixel->update();

	_enemy->update();
	_enemy->getEnemyState()->setEnemy(_enemy);

	//pixelCollision();

	_zO->update();
}

void firstStage::render()
{
	//IMAGEMANAGER->findImage("STAGE_stage1")->render(getMemDC(), 0, 0);
	
	if (KEYMANAGER->isToggleKey(VK_TAB))
	{
		//_first->render(getMemDC(), 0, 0);
		_pixel->render();
	}
	_zO->render();
	_camera->render();
	//_player->render();
	//_enemy->render();
	//_boss->render();
}