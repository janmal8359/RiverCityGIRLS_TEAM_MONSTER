#include "pch.h"
#include "state.h"
#include "player.h"


HRESULT state::init()
{
	

	return S_OK;
}

void state::release()
{

}

void state::update()
{
	//������ �÷��̾�� get���� �����ͼ� �������ش�;
	_dir = _player->getDir();

	stateChange();
	ani();

	KEYANIMANAGER->update();
}

void state::render()
{
	_player->stateRender(_playerAni);
}
