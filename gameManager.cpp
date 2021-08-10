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

	//대화 스크립트
	scriptStart = false;
	scriptEnd = true;
	_scriptSkip = false;
	scriptImage = IMAGEMANAGER->findImage("SCENE_dialogWindow");
	scriptRc = RectMakeCenter(WINSIZEX / 2, 650, scriptImage->getWidth(), scriptImage->getHeight());
	_scriptIndex = _txtIndex = 0;
	scriptSkip = IMAGEMANAGER->findImage("SCENE_skipOutlines2");
	_vScript = TXTDATA->txtLoad("Resource/되냐.txt");
	//_vScript = TXTDATA->txtLoad("Resource/스크립트.txt");
	kScript = IMAGEMANAGER->findImage("SCENE_kyoko1");
	mScript = IMAGEMANAGER->findImage("SCENE_misuzu1");

	//맵 자물쇠
	mapLocked = false;
	mapUnlocked = true;

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
		_playerHP -=1;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_F4) && _playerHP < 24)
	{
		_playerHP +=1;
	}
	for (int i = 0; i < _playerHP; i++) 
	{
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

	if (!_scriptSkip)
	{
		if (KEYMANAGER->isOnceKeyDown(VK_RETURN))
			_scriptSkip = true;
	}
	if (_scriptSkip)
	{
		if (KEYMANAGER->isOnceKeyDown(VK_RETURN))
			_scriptSkip = false;
	}
	

	if (KEYMANAGER->isOnceKeyDown(VK_F2) && mapLocked && !mapUnlocked)
	{
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
		scriptImage->render(getMemDC(), scriptRc.left, scriptRc.top);
		scriptSkip->render(getMemDC(), 1070, 10); 

		SetBkMode(getMemDC(), TRANSPARENT);
		SetTextColor(getMemDC(), RGB(255, 255, 255));
		RECT rcText = RectMake(170, 600, 1000, 200);

		/*HFONT font2 = CreateFont(35, 0, 0, 0, 300, false, false, false,
			DEFAULT_CHARSET, OUT_STROKE_PRECIS, CLIP_DEFAULT_PRECIS,
			PROOF_QUALITY, DEFAULT_PITCH | FF_SWISS, TEXT("휴먼굴림"));*/

		HFONT font2 = CreateFont(30, 0, 0, 0, 300, false, false, false,
			HANGUL_CHARSET, OUT_STRING_PRECIS, CLIP_DEFAULT_PRECIS,
			PROOF_QUALITY, DEFAULT_PITCH | FF_SWISS, TEXT("바탕"));
		HFONT font2 = CreateFont(30, 0, 0, 0, 100, false, false, false, HANGUL_CHARSET, 0, 0, 0, 50, TEXT("휴먼굴림"));

		HFONT oldFont2 = (HFONT)SelectObject(getMemDC(), font2);

		DrawText(getMemDC(), TEXT(_txt.c_str()), _txtIndex, &rcText, DT_LEFT | DT_VCENTER | DT_WORDBREAK);

		SelectObject(getMemDC(), oldFont2);
		DeleteObject(font2);
	}
	if (scriptEnd)
	{
		//보스 스테이지 시작
	}
}

void gameManager::scriptPlay()
{
	_txt = _vScript[_scriptIndex];

	if (_scriptIndex == 0 || _scriptIndex == 1 || _scriptIndex == 3 || _scriptIndex == 5 || _scriptIndex == 7 || _scriptIndex == 9 || _scriptIndex == 10)
	{
		kScript->render(getMemDC(), 15, 200);
	}
	
	if (_scriptIndex == 2 || _scriptIndex == 4 || _scriptIndex == 6 || _scriptIndex == 8 || _scriptIndex == 11)
	{
		mScript->render(getMemDC(), 850, 200);
	}

	if (!_scriptSkip) {
		scriptSkip = IMAGEMANAGER->findImage("SCENE_skipOutlines2");
		if (_txtIndex <= _txt.length())
		{
			_txtIndex++;
		}
		else if (_txtIndex >= _txt.length())
		{
			_scriptIndex++;
			_txtIndex = 0;

			Sleep(700);
		}
	}
	else if (_scriptSkip)
	{
		scriptSkip = IMAGEMANAGER->findImage("SCENE_skipOutlines1");
		if (_txtIndex >= _txt.length())
		{
			_scriptIndex++;
			_txtIndex = 0;

			Sleep(200);
		}
		if (_txtIndex < _txt.length())
		{
			_txtIndex = _txt.length();
		}
	}
	if (_scriptIndex >= _vScript.size())
	{
		scriptStart = false;
		scriptEnd = true;
	}
}