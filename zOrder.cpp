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
	_camera = new camera;
	_camera->init();
	_camera->setStage(SECOND_STAGE);

	_boss = new boss;
	_boss->setPlayerMemoryAddressLink(_player);
	_boss->setCameraMemoryAddressLink(_camera);
	_boss->init();

	_enemy = new enemy;
	_enemy->init();

	_player = new player;
	_player->init();
	_player->setCamera(_camera);
	_player->setBossMemoryAddressLink(_boss);

	_enemy->setPlayerMemoryLink(_player);				//�÷��̾� ����
	_enemy->setCameraMemoryLink(_camera);				//ī�޶� ����

	_pixel = new pixelCollisionClass;

	_pixel->init(0, 0, 0);
	_pixel->setPixelPlayer(_player);
	_pixel->setCAMERAMemoryAddressLink(_camera);		//ī�޶� �� ����



	_vRender.push_back(_player);
	_vRender.push_back(_enemy);
	_vRender.push_back(_boss);

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


	_pixel->setPixelPlayer(_player);
	_pixel->update();

	_enemy->update();
	_enemy->getEnemyState()->setEnemy(_enemy);

	selectionSort();
}

void zOrder::render()
{

	_camera->render();

	if (KEYMANAGER->isToggleKey(VK_F8))
	{
		_pixel->render();
	}

	for (_viRender = _vRender.begin(); _viRender != _vRender.end(); _viRender++)
	{
		(*_viRender)->render();
	}
}

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
	//gameNode 
	gameNode* temp = *a;
	*a = *b;
	*b = temp;
}

