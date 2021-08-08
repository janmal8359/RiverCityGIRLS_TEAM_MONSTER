#include "pch.h"
#include "boss.h"

HRESULT boss::init()
{
	_sx = WINSIZEX / 2;
	_sy = WINSIZEY / 2;

	bossAnim();

	_state = new idleState;
	_state->init();

	_bossImg = _state->getImg();
	_bShadowImg = IMAGEMANAGER->findImage("SHADOW");

	_bx = _sx;
	_by = _sy - _bossImg->getFrameHeight() / 2;

	_bossRc = RectMakeCenter(_bx, _by, _bossImg->getFrameWidth(), _bossImg->getFrameHeight());
	_bShadowRc = RectMakeCenter(_sx, _sy, _bShadowImg->getWidth(), _bShadowImg->getHeight());

	_speed = 0;

	_direction = DIRECTION::LEFT;

	return S_OK;
}

void boss::release()
{
}

void boss::update()
{
	_state->setBoss(this);

	_state->update();

	_bx = _sx;
	_by = _sy - _bossImg->getFrameHeight() / 2;

	_bossImg = _state->getImg();

	if (KEYMANAGER->isOnceKeyDown('1'))
	{
		_direction = DIRECTION::LEFT;
	}
	else if (KEYMANAGER->isOnceKeyDown('2'))
	{
		_direction = DIRECTION::RIGHT;
	}
}

void boss::render()
{
	_bShadowImg->render(getMemDC(), _bShadowRc.left, _bShadowRc.top);
	_state->render();

	//Rectangle(getMemDC(), _bossRc);
	//Rectangle(getMemDC(), _bShadowRc);
}

void boss::stateRender(animation* anim)
{
	_bossImg->aniRender(getMemDC(), _bossRc.left, _bossRc.top, anim);
}

void boss::bossAnim()
{
	KEYANIMANAGER->addCoordinateFrameAnimation("BOSS_idleL", "BOSS_idle", 11, 0, 7, false, true);
	KEYANIMANAGER->addCoordinateFrameAnimation("BOSS_idleR", "BOSS_idle", 12, 23, 7, false, true);
	KEYANIMANAGER->addCoordinateFrameAnimation("BOSS_walkL", "BOSS_walk", 9, 0, 7, false, true);
	KEYANIMANAGER->addCoordinateFrameAnimation("BOSS_walkR", "BOSS_walk", 10, 19, 7, false, true);
}
