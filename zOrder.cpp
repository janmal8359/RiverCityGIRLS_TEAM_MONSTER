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

	_enemy->setPlayerMemoryLink(_player);				//플레이어 연동
	_enemy->setCameraMemoryLink(_camera);				//카메라 연동

	_pixel = new pixelCollisionClass;

	_pixel->init(0, 0, 0);
	_pixel->setPixelPlayer(_player);
	_pixel->setCAMERAMemoryAddressLink(_camera);		//카메라 값 연동



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

	ZOrder();
}

void zOrder::render()
{
	draw();
}

void zOrder::ZOrder()
{
	//다중적을 담고있는 em에서 가져와서 넣어주는 역할
	//vector<enemy*> _vEnemy = _em->getVEnemy();

	_mobj.clear();

	//플레이어 삽입
	_mobj.insert(make_pair(_player->getShadowY(), 0));

	mapIdx = _mobj.size();

	//적이 추가 되었을때
	//for (int i = 0; i < _vEnemy.size(); i++)
	//{
	//	(*_viRender)->render();
	//}

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

	// 객체를 담은 벡터크기만 for을 돌려서 확인 ! 벡터끝에는 항상 null값이 존재해서 -1 해줌!!!!

	for (i = 0; i < _vRender.size() - 1; i++)
	{
		//내가 빡대가리 .
		//for 문에 서 하나씩올리면서 확인줌 min값은 그대상
		minIndex = i;
		//for문에서 j = 그 다음 대상 0 ,1 을비교하기위해서  이중포문 개념으로 접근하자
		for (j = i + 1; j < _vRender.size(); j++)
		{
			//j랑 minindex
			if (_vRender[j]->getPosY() < _vRender[minIndex]->getPosY())
			{ //렌더의 Y값을 가져와서 비교하여 스왑.
				//바꿨을때 얘가 min이 됨
				minIndex = j;
			}
		}


		swap(&_vRender[i], &_vRender[minIndex]); //render

	}
}

void zOrder::swap(gameNode** a, gameNode** b)
{
	_mobj.insert(make_pair(_enemy->getEnemySY(), 1));

	mapIdx = _mobj.size();
}

void zOrder::draw()
{
	for (_miobj = _mobj.begin(); _miobj != _mobj.end(); ++_miobj)
	{
		if (_miobj->second == 0)
		{
			_player->render();
		}
		if (_miobj->second == 1)
		{
			_enemy->render();
		}
		if (_miobj->second == 2)
		{
			_boss->render();
		}
	}

	//gameNode 
	gameNode* temp = *a;
	*a = *b;
	*b = temp;
}

