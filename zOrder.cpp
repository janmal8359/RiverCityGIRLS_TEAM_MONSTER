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
	
	ZOrder();
}

void zOrder::render()
{
	draw();
}
void zOrder::ZOrder()
{
	_mobj.clear();
	//ÇÃ·¹ÀÌ¾î »ğÀÔ
	_mobj.insert(make_pair(_player->getShadowY(), 0));

	mapIdx = _mobj.size();

	_mobj.insert(make_pair(_enemy->getEnemySY(), 1));

	mapIdx = _mobj.size();
	


}
void zOrder::draw()
{
	int i = 0;

	for (_miobj = _mobj.begin(); _miobj != _mobj.end(); ++_miobj, i++)
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
