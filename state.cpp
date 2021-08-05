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
	//방향을 플레이어에서 get으로 가져와서 설정해준다;
	_dir = _player->getDir();

	stateChange();
	ani();

	KEYANIMANAGER->update();
}

void state::render()
{
	_player->stateRender(_playerAni);
}
