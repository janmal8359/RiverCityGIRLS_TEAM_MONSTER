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
	
	_camera = new camera;
	_camera->init();
	_camera->setStage(SECOND_STAGE);

	_boss = new boss;
	_boss->setPlayerMemoryAddressLink(_player);
	_boss->setCameraMemoryAddressLink(_camera);
	_boss->init();

	_enemy = new enemy;
	_enemy->init();
<<<<<<< HEAD

	//_camera = new camera;
	//_camera->init();
	//_camera->setStage(0);
=======
	
	_camera = new camera;
	_camera->init();
	_camera->setStage(1);
>>>>>>> parent of 682375e (zorder ì¼ë‹¨êµ¬í˜„ ê°ì²´í™” í™•ì¸)
	
	_player = new player;
	_player->init();
	_player->setCamera(_camera);
	_player->setBossMemoryAddressLink(_boss);

	_enemy->setPlayerMemoryLink(_player);				//ÇÃ·¹ÀÌ¾î ¿¬µ¿
	_enemy->setCameraMemoryLink(_camera);				//Ä«¸Ş¶ó ¿¬µ¿

	_zO = new zOrder;
	_zO->init();
	
	_zO->setPlayer(_player);
	_zO->setBoss(_boss);
	_zO->setEnemy(_enemy);

	_isCheck = false;

	_pixel = new pixelCollisionClass;

	_pixel->init(0, 0, 0);
	_pixel->setPixelPlayer(_player);
	_pixel->setCAMERAMemoryAddressLink(_camera);		//Ä«¸Ş¶ó °ª ¿¬µ¿



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
<<<<<<< HEAD
=======
	_boss->update();
>>>>>>> parent of 682375e (zorder ì¼ë‹¨êµ¬í˜„ ê°ì²´í™” í™•ì¸)

	_pixel->setPixelPlayer(_player);
	_pixel->update();

	_enemy->update();
	_enemy->getEnemyState()->setEnemy(_enemy);

	//pixelCollision();

	_zO->update();
}

void firstStage::render()
{
	_camera->render();

	if (KEYMANAGER->isToggleKey(VK_F8))
	{
		_pixel->render();
	}
<<<<<<< HEAD

	_zO->render();
=======
	//_zO->render();
>>>>>>> parent of 682375e (zorder ì¼ë‹¨êµ¬í˜„ ê°ì²´í™” í™•ì¸)
	_camera->render();
	_player->render();
	_enemy->render();
	//_boss->render();
<<<<<<< HEAD
}

//¼±ÅÃÁ¤·Ä ÇÔ¼ö
void firstStage::selectionSort()
{
	int minIndex;
	int i, j;

	// °´Ã¼¸¦ ´ãÀº º¤ÅÍÅ©±â¸¸ forÀ» µ¹·Á¼­ È®ÀÎ ! º¤ÅÍ³¡¿¡´Â Ç×»ó null°ªÀÌ Á¸ÀçÇØ¼­ -1 ÇØÁÜ!!!!

	for (i = 0; i < _vRender.size() - 1; i++)
	{
		//³»°¡ ºı´ë°¡¸® .
		//for ¹®¿¡ ¼­ ÇÏ³ª¾¿¿Ã¸®¸é¼­ È®ÀÎÁÜ min°ªÀº ±×´ë»ó
		minIndex = i;
		//for¹®¿¡¼­ j = ±× ´ÙÀ½ ´ë»ó 0 ,1 À»ºñ±³ÇÏ±âÀ§ÇØ¼­  ÀÌÁßÆ÷¹® °³³äÀ¸·Î Á¢±ÙÇÏÀÚ
		for (j = i + 1; j < _vRender.size(); j++) 
		{
			//j¶û minindex
			if (_vRender[j]->getPosY() < _vRender[minIndex]->getPosY())
			{ //·»´õÀÇ Y°ªÀ» °¡Á®¿Í¼­ ºñ±³ÇÏ¿© ½º¿Ò.
				//¹Ù²åÀ»¶§ ¾ê°¡ minÀÌ µÊ
				minIndex = j;
			}
		}


		swap(&_vRender[i], &_vRender[minIndex]); //render
	
	}
}

//Å¬·¡½º ½º¿Ò
void firstStage::swap(gameNode** a, gameNode** b)
{
	//gameNode 
	gameNode* temp = *a;
	*a = *b;
	*b = temp;

	//_player->render();
	//_enemy->render();
	//_boss->render();
=======
>>>>>>> parent of 682375e (zorder ì¼ë‹¨êµ¬í˜„ ê°ì²´í™” í™•ì¸)
}