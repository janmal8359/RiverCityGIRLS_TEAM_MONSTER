#include "pch.h"
#include "boss.h"
#include "player.h"

HRESULT boss::init()
{
	_sx = WINSIZEX / 2 + 151;
	_sy = WINSIZEY / 2;

	bossAnim();

	_state = new idleState;
	_state->init();

	_state->setBoss(this);

	_bossImg = _state->getImg();
	_bShadowImg = IMAGEMANAGER->findImage("SHADOW");

	_bx = _sx;
	_by = _sy - _bossImg->getFrameHeight() / 2;

	_bossRc = RectMakeCenter(_bx, _by, _bossImg->getFrameWidth(), _bossImg->getFrameHeight());
	_bShadowRc = RectMakeCenter(_sx, _sy, _bShadowImg->getWidth(), _bShadowImg->getHeight());

	_speed = 0;

	//_direction = DIRECTION::LEFT;

	//_isMove = true;

	return S_OK;
}

void boss::release()
{
}

void boss::update()
{
	_state->update();

	_bossImg = _state->getImg();

	_bx = _sx;
	_by = _sy - _bossImg->getFrameHeight() / 2;

	if (_isMove) move();

	if (abs(getAngle(_player->getShadowX(), _player->getShadowY(), _sx, _sy)) < PI / 2 || abs(getAngle(_player->getShadowX(), _player->getShadowY(), _sx, _sy)) > 3 * PI / 2)
	{
		_direction = DIRECTION::LEFT;
	}
	else if (abs(getAngle(_player->getShadowX(), _player->getShadowY(), _sx, _sy)) > PI / 2 && abs(getAngle(_player->getShadowX(), _player->getShadowY(), _sx, _sy)) < 3 * PI / 2)
	{
		_direction = DIRECTION::RIGHT;
	}

	_bossRc = RectMakeCenter(_bx, _by, _bossImg->getFrameWidth(), _bossImg->getFrameHeight());
	_bShadowRc = RectMakeCenter(_sx, _sy, _bShadowImg->getWidth(), _bShadowImg->getHeight());

	_state->setBoss(this);


}

void boss::render()
{
	_bShadowImg->render(getMemDC(), _bShadowRc.left, _bShadowRc.top);
	_state->render();

	char str[128];
	sprintf_s(str, "_sx : %.2f  _sy : %.2f", _sx, _sy);
	TextOut(getMemDC(), 10, 150, str, strlen(str));

	sprintf_s(str, "direction : %d", (int)_direction);
	TextOut(getMemDC(), 10, 300, str, strlen(str));
}

void boss::stateRender(animation* anim)
{
	_bossImg->aniRender(getMemDC(), _bossRc.left, _bossRc.top, anim);
}

void boss::bossAnim()
{
	KEYANIMANAGER->addCoordinateFrameAnimation("BOSS_idleL", "BOSS_idle", 11, 0, 10, false, true);
	KEYANIMANAGER->addCoordinateFrameAnimation("BOSS_idleR", "BOSS_idle", 12, 23, 10, false, true);
	KEYANIMANAGER->addCoordinateFrameAnimation("BOSS_walkL", "BOSS_walk", 19, 10, 10, false, true);
	KEYANIMANAGER->addCoordinateFrameAnimation("BOSS_walkR", "BOSS_walk", 0, 9, 10, false, true);
	//KEYANIMANAGER->addCoordinateFrameAnimation("BOSS_slapL", "BOSS_slap", 27, 14, 10, false, true);
	//KEYANIMANAGER->addCoordinateFrameAnimation("BOSS_slapR", "BOSS_slap", 0, 13, 10, false, true);
}

void boss::move()
{
	_bx -= cosf(getAngle(_player->getShadowX(), _player->getShadowY(), _sx, _sy)) * 3;
	_sx = _bx;

	_by -= -sinf(getAngle(_player->getShadowX(), _player->getShadowY(), _sx, _sy)) * 3;
	_sy = _by + _bossImg->getFrameHeight() / 2;
}
