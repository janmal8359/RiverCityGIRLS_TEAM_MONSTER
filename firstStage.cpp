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

	_camera = new camera;
	_camera->init();
	_camera->setStage(0);
	
	_player = new player;
	_player->init();
	_player->setCamera(_camera);
	_player->setBossMemoryAddressLink(_boss);

	_enemy->setPlayerMemoryLink(_player);				//�÷��̾� ����
	_enemy->setCameraMemoryLink(_camera);				//ī�޶� ����

	_zO = new zOrder;
	_zO->init();
	
	_zO->setPlayer(_player);
	_zO->setBoss(_boss);
	_zO->setEnemy(_enemy);

	_isCheck = false;

	_pixel = new pixelCollisionClass;

	_pixel->init(0, 0, 0);
	_pixel->setPixelPlayer(_player);
	_pixel->setCAMERAMemoryAddressLink(_camera);		//ī�޶� �� ����



	//vrender ���Ϳ� ������ Ŭ������ �ִ´�.
	_vRender.push_back(_player);
	_vRender.push_back(_enemy);


	return S_OK; 
}

void firstStage::release()
{
}

void firstStage::update()
{
	//_player->update();

	_player->getState()->setPlayer(_player);

	_boss->setPlayerMemoryAddressLink(_player);

	_pixel->setPixelPlayer(_player);
	_pixel->update();

	//_enemy->update();
	_enemy->getEnemyState()->setEnemy(_enemy);

	//pixelCollision();

	_zO->update();

	//���� y���� �޾� ���� ����
	selectionSort();
}

void firstStage::render()
{
	_camera->render();

	if (KEYMANAGER->isToggleKey(VK_F8))
	{
		_pixel->render();
	}

	_zO->render();
	_camera->render();


	//_player->render();
	//_enemy->render();

	//���ӳ���� ��ü�� ��ӹ޴� ��ü�� ������ ����
	for (_viRender = _vRender.begin(); _viRender != _vRender.end(); _viRender++)
	{
		(*_viRender)->render();

	}
	//_boss->render();
}

//�������� �Լ�
void firstStage::selectionSort()
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

//Ŭ���� ����
void firstStage::swap(gameNode** a, gameNode** b)
{
	//gameNode 
	gameNode* temp = *a;
	*a = *b;
	*b = temp;

	//_player->render();
	//_enemy->render();
	//_boss->render();
}