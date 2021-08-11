#include "pch.h"
#include "zOrder.h"

zOrder::zOrder()
{
}


zOrder::~zOrder()
{
}

HRESULT zOrder::init()
{
	_player = new player;
	_player->init();

	_boss = new boss;
	_boss->init();

	_enemy = new enemy;
	_enemy->init();


	return S_OK;
}

void zOrder::release()
{

}

void zOrder::update()
{
	_player->update();
	_enemy->update();
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
	//	_mobj.insert(make_pair(_vEnemy[i]->getEy(),KEY*mapIdx,2))
	//}

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

	}



}
