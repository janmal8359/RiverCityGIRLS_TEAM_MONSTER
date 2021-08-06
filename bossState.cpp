#include "pch.h"
#include "bossState.h"


// Idle
HRESULT idleState::init()
{
	return S_OK;
}

void idleState::release()
{
}

void idleState::update()
{
}

void idleState::render()
{
}


// Walk
HRESULT walkState::init()
{
	return S_OK;
}

void walkState::release()
{
}

void walkState::update()
{
}

void walkState::render()
{
}


// Attack
HRESULT attackState::init()
{
	return S_OK;
}

void attackState::release()
{
}

void attackState::update()
{
}

void attackState::render()
{
}


// JumpAttack
HRESULT jumpState::init()
{
	return S_OK;
}

void jumpState::release()
{
}

void jumpState::update()
{
}

void jumpState::render()
{
}


// Sit
HRESULT sitState::init()
{
	return S_OK;
}

void sitState::release()
{
}

void sitState::update()
{
}

void sitState::render()
{
}


// Groggy
HRESULT groggyState::init()
{
	return S_OK;
}

void groggyState::release()
{
}

void groggyState::update()
{
}

void groggyState::render()
{
}


// Lose
HRESULT loseState::init()
{
	return S_OK;
}

void loseState::release()
{
}

void loseState::update()
{
}

void loseState::render()
{
}
