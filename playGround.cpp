#include "pch.h"
#include "playGround.h"

playGround::playGround()
{
}


playGround::~playGround()
{
}

//�ʱ�ȭ�� ���⿡�� �ض�!!!
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
	
	
	return S_OK;
}

//�޸� ������ ����� �ض�!!!!
void playGround::release()
{
	gameNode::release();


}

//����ó���� ����ٰ�!
void playGround::update()
{
	gameNode::update();

	

	_player->update();

	_player->getState()->setPlayer(_player);

	_boss->update();

	_enemy->update();
	_enemy->getEnemyState()->setEnemy(_enemy);
	
}

//����� �׷����!!!
void playGround::render()
{
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//==============������ ���� �ǵ帮�� ���� ============

	_boss->render();

	_player->render();
	_enemy->render();


	//=============== �ؿ��� �ǵ������� ================
	_backBuffer->render(getHDC(), 0, 0);

}

