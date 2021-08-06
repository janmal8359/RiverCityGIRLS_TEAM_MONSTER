#include "pch.h"
#include "boss.h"
#include "bossState.h"

HRESULT boss::init()
{
	_state = idleState::getInstance();

	return S_OK;
}

void boss::release()
{
}

void boss::update()
{
}

void boss::render()
{
}
