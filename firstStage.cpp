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
	
//	_boss = new boss;
//	_boss->setPlayerMemoryAddressLink(_player);
//	_boss->init();

//	_enemy = new enemy;
	//_enemy->init();
	
	_camera = new camera;
	_camera->init();
	_camera->setStage(0);
	
	_player = new player;
	_player->init();
	_player->setCamera(_camera);

	//_enemy->setPlayerMemoryLink(_player);				//플레이어 연동

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

	//_boss->setPlayerMemoryAddressLink(_player);
	//_boss->update();

	_pixel->setPixelPlayer(_player);
	_pixel->update();

//	_enemy->update();
	//_enemy->getEnemyState()->setEnemy(_enemy);
}

void firstStage::render()
{
	if (KEYMANAGER->isToggleKey(VK_TAB))
	{
		_pixel->render();
	}
	
	_camera->render();
	_player->render();
	//_enemy->render();
	//_boss->render();
}