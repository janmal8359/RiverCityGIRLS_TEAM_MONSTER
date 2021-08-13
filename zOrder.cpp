#include "pch.h"
#include "zOrder.h"
#include "pixelCollisionClass.h"

zOrder::zOrder()
{
}


zOrder::~zOrder()
{
}

HRESULT zOrder::init()
{
	//_vRender.push_back(_player);
	//_vRender.push_back(_enemy);
	//_vRender.push_back(_boss);

	_player = new player;
	_camera = new camera;
	_boss = new boss;
	_enemy = new enemy;
	_pixel = new pixelCollisionClass;
	_objectManager = new objectManager;
	_enemyManager = new enemyManager;


	_camera->setStage((int)stageImg::FIRST_STAGE);

	_boss->setPlayerMemoryAddressLink(_player);
	_boss->setCameraMemoryAddressLink(_camera);
	_boss->init();

	//_enemy = new enemy;
	//_enemy->init();


	_enemyManager->init();
	_enemyManager->setSchoolGirl();

	_player->init();
	_player->setCamera(_camera);
	_player->setBossMemoryAddressLink(_boss);
	_player->setEnemyMemoryAddressLink(_enemy);
	

	_boss->setPlayerMemoryAddressLink(_player);
	_boss->setCameraMemoryAddressLink(_camera);


	_objectManager->init();
	_objectManager->setObject();



	_pixel->init(0, 0, 0);
	_pixel->setPixelPlayer(_player);
	_pixel->setCAMERAMemoryAddressLink(_camera);		//ī�޶� �� ����

	_player->setObjectManagerMemoryAddressLink(_objectManager);



	


	_camera->init();

	_boss->init();

	_enemy->init();

	_player->init();




	//for (_enemyManager->getVIGirl() = _enemyManager->getVGirl().begin(); _enemyManager->getVIGirl() != _enemyManager->getVGirl().end(); ++_enemyManager->getVIGirl())
//{
//	_player->setEnemyMemoryAddressLink((*_enemyManager->getVIGirl()));
//}
	for (int i = 0; i < _enemyManager->getVGirl().size(); )
	{
		_player->setEnemyManagerMemoryAddressLink(_enemyManager);
		_enemyManager->getVGirl()[i]->setPlayerMemoryLink(_player);

		++i;
	}
	//_enemy->setPlayerMemoryLink(_player);				//�÷��̾� ����
	//_enemy->setCameraMemoryLink(_camera);				//ī�޶� ����

	for (int i = 0; i < _objectManager->getVObject().size();)
	{
		_player->setObjectManagerMemoryAddressLink(_objectManager);
		_objectManager->getVObject()[i]->setPlayerMemoryAddrsLink(_player);

		++i;
	}


	//�־��ش�.
	_vRender.push_back(_player);
	//_vRender.push_back(_enemy);

	_vRender.push_back(_boss);
	_vRender.push_back(_objectManager);
	
	for (int i = 0; i < _objectManager->getVObject().size(); ++i)
	{
		_vRender.push_back(_objectManager->getVObject()[i]);
	}

	//_ef = new effect;
	//_ef->init(IMAGEMANAGER->addFrameImage("smash", "resources/IMG/effect/Boss smash.bmp", 960, 89, 10, 1, true, RGB(255, 0, 255)), 96, 89, 1, 0.5f);


	for (int i = 0; i < _enemyManager->getVGirl().size(); ++i)
	{
		_vRender.push_back(_enemyManager->getVGirl()[i]);
	}
	//_vRender.push_back(_enemyManager);
	//_vRender.push_back(_boss);


	return S_OK;
}

void zOrder::release()
{
}

void zOrder::update()
{
	_player->update();

	_player->getState()->setPlayer(_player);

	_boss->setPlayerMemoryAddressLink(_player);

	_boss->update();

	_objectManager->update();

	_pixel->setPixelPlayer(_player);
	_pixel->update();

	//_enemy->update();
	//_enemy->getEnemyState()->setEnemy(_enemy);

	_enemyManager->update();

	_camera->update();

	selectionSort();

	//EFFECTMANAGER->update();
	//
	//if (KEYMANAGER->isStayKeyDown(VK_LBUTTON))
	//{
	//	//_ef->startEffect(WINSIZEX / 2, WINSIZEY / 2);
	//	IMAGEMANAGER->addFrameImage("smash", "resources/IMG/effect/Boss smash.bmp", 960, 89, 10, 1, true, RGB(255, 0, 255));
	//	IMAGEMANAGER->frameRender("smash", getMemDC(), WINSIZEX / 2, WINSIZEY / 2);
	//}
	//
	//_ef->update();

	//zOrder();
}

void zOrder::render()
{
	
	
	_camera->render();


	if (KEYMANAGER->isToggleKey(VK_F8))
	{
		_pixel->render();
	}

	for (_viRender = _vRender.begin(); _viRender != _vRender.end(); ++_viRender)
	{
		(*_viRender)->render();
	}
	//EFFECTMANAGER->render();
	//_ef->render();

	char str[128];

	sprintf_s(str, "vecterSize : %d", _vRender.size());
	TextOut(getMemDC(), 1000, 100, str, strlen(str));

}

//void zOrder::ZOrder()
//{
//	//�������� ����ִ� em���� �����ͼ� �־��ִ� ����
//	//vector<enemy*> _vEnemy = _em->getVEnemy();
//
//	_mobj.clear();
//
//	//�÷��̾� ����
//	_mobj.insert(make_pair(_player->getShadowY(), 0));
//
//	mapIdx = _mobj.size();
//
//	//���� �߰� �Ǿ�����
//	//for (int i = 0; i < _vEnemy.size(); i++)
//	//{
//	//	(*_viRender)->render();
//	//}
//
//	_camera->render();
//
//	if (KEYMANAGER->isToggleKey(VK_F8))
//	{
//		_pixel->render();
//	}
//
//	for (_viRender = _vRender.begin(); _viRender != _vRender.end(); _viRender++)
//	{
//		(*_viRender)->render();
//	}
//}

void zOrder::selectionSort()
{
	int minIndex;
	int i, j;

	// ��ü�� ���� ����ũ�⸸ for�� ������ Ȯ�� ! ���ͳ����� �׻� null���� �����ؼ� -1 ����!!!!

	for (i = 0; i < _vRender.size() - 1; i++)
	{
		//���� ���밡�� .
		//for ���� �� �ϳ����ø��鼭 Ȯ���� min���� �״��
		minIndex = i;
		//for������ j = �� ���� ��� 0 ,1 �����ϱ����ؼ�  �������� �������� ��������
		for (j = i + 1; j < _vRender.size(); j++)
		{
			//j�� minindex
			if (_vRender[j]->getPosY() < _vRender[minIndex]->getPosY())
			{ //������ Y���� �����ͼ� ���Ͽ� ����.
				//�ٲ����� �갡 min�� ��
				minIndex = j;
			}
		}


		swap(&_vRender[i], &_vRender[minIndex]); //render

	}
}

void zOrder::swap(gameNode** a, gameNode** b)
{
	gameNode* temp = *a;
	*a = *b;
	*b = temp;
}

//void zOrder::draw()
//{
//	for (_miobj = _mobj.begin(); _miobj != _mobj.end(); ++_miobj)
//	{
//		if (_miobj->second == 0)
//		{
//			_player->render();
//		}
//		if (_miobj->second == 1)
//		{
//			_enemy->render();
//		}
//		if (_miobj->second == 2)
//		{
//			_boss->render();
//		}
//	}
//
//	//gameNode 
//	gameNode* temp = *a;
//	*a = *b;
//	*b = temp;
//}

