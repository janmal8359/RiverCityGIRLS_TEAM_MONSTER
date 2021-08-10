#include "pch.h"
#include "gameManager.h"
#include "player.h"

gameManager::gameManager()
{
}

gameManager::~gameManager()
{
}

HRESULT gameManager::init()
{
	//플레이어 UI 프로필
	_playerProfile._image = IMAGEMANAGER->findImage("BATTLE_playerPortrait");
	_playerProfile._rc = RectMakeCenter(200, 70, _playerProfile._image->getWidth(), _playerProfile._image->getHeight());
	
	//플레이어 UI바
	_playerHPBar._image = IMAGEMANAGER->findImage("BATTLE_playerBar");
	_playerHPBar._rc = RectMakeCenter(450, 86, _playerHPBar._image->getWidth(), _playerHPBar._image->getHeight());

	//플레이어 HP
	_playerHP = 24;

	for (int i = 0; i < _playerHP; i++)
	{
		_playerHPPoint[i]._image = IMAGEMANAGER->findImage("BATTLE_HP");
		_playerHPPoint[i]._rc = RectMakeCenter(270+i*16, 53, _playerHPPoint[i]._image->getWidth(), _playerHPPoint[i]._image->getHeight());
	}
	
	//맵 자물쇠
	mapLocked = false;
	mapUnlocked = true;

	//대화 스크립트
	scriptStart = false;
	scriptEnd = true;
	scriptImage = IMAGEMANAGER->findImage("SCENE_dialogWindow");
	scriptRc = RectMakeCenter(WINSIZEX / 2, 650, scriptImage->getWidth(), scriptImage->getHeight());
	_scriptIndex = _txtIndex = 0;
	
	_vScript = TXTDATA->txtLoad("대화.txt");

	return S_OK;
}

void gameManager::release()
{
}

void gameManager::update()
{
	//플레이어 HP
	if (KEYMANAGER->isOnceKeyDown(VK_F3) && _playerHP > 0)
	{
		_playerHP -= 1;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_F4) && _playerHP < 24)
	{
		_playerHP += 1;
	}
	for (int i = 0; i < _playerHP; i++) {
		_playerHPPoint[i]._rc = RectMakeCenter(270 + i * 16, 53, _playerHPPoint[i]._image->getWidth(), _playerHPPoint[i]._image->getHeight());
	}

	//맵 이벤트
	/*if (KEYMANAGER->isOnceKeyDown() && !mapLocked && mapUnlocked)
	{
		mapLocked = true;
		mapUnlocked = false;
	}
	if (KEYMANAGER->isOnceKeyDown() && mapLocked && !mapUnlocked)
	{
		mapLocked = false;
		mapUnlocked = true;
	}*/

	//대화 스크립트
	if (KEYMANAGER->isOnceKeyDown(VK_F1) && !scriptStart && scriptEnd)
	{
		scriptStart = true;
		scriptEnd = false;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_F2) && mapLocked && !mapUnlocked)
	{
		scriptStart = false;
		scriptEnd = true;
	}
}

void gameManager::render()
{
	_playerHPBar._image->render(getMemDC(), _playerHPBar._rc.left, _playerHPBar._rc.top);
	_playerProfile._image->render(getMemDC(), _playerProfile._rc.left, _playerProfile._rc.top);
	for (int i = 0; i < _playerHP; i++) {
		_playerHPPoint[i]._image->render(getMemDC(), _playerHPPoint[i]._rc.left, _playerHPPoint[i]._rc.top);
	}

	if (scriptStart)
	{
		scriptPlay();
		IMAGEMANAGER->findImage("SCENE_skipOutlines1")->render(getMemDC(), 1070, 10);

		SetTextColor(getMemDC(), RGB(255, 255, 255));
		char str[1024];
		HFONT font, oldFont;
		RECT rcText = RectMake(200, WINSIZEY - 56, WINSIZEX - 350, 76);
		font = CreateFont(35, 0, 0, 0, 400, false, false, false,
			DEFAULT_CHARSET,
			OUT_STRING_PRECIS,
			CLIP_DEFAULT_PRECIS,
			PROOF_QUALITY,
			DEFAULT_PITCH | FF_SWISS,
			TEXT("휴먼굴림"));

		if (_txtIndex > 90)
		{
			rcText = RectMake(200, WINSIZEY - 76, WINSIZEX - 350, 76);
		}

		oldFont = (HFONT)SelectObject(getMemDC(), font);
		DrawText(getMemDC(), TEXT(_txt.c_str()), _txtIndex, &rcText,
			DT_LEFT | DT_WORDBREAK | DT_VCENTER);

		DeleteObject(font);

	}
	if (scriptEnd)
	{
		//IMAGEMANAGER->findImage("")
	}
}

void gameManager::scriptPlay()
{
	scriptImage->render(getMemDC(), scriptRc.left, scriptRc.top);

	_txt = _vScript[_scriptIndex];

	if (_txtIndex <= _txt.length())
	{
		_txtIndex++;
	}
	else if (_txtIndex >= _txt.length() && KEYMANAGER->isOnceKeyDown(VK_SPACE))
	{
		_scriptIndex++;
		_txtIndex = 0;
	}

	if (_txtIndex < _txt.length() && KEYMANAGER->isOnceKeyDown(VK_SPACE))
		_txtIndex = _txt.length();

	if (_scriptIndex >= _vScript.size())
	{
		scriptStart = false;
		scriptEnd = true;
	}
}