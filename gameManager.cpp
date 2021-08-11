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
	//�÷��̾� UI ������
	_playerProfile._image = IMAGEMANAGER->findImage("BATTLE_playerPortrait");
	_playerProfile._rc = RectMakeCenter(200, 70, _playerProfile._image->getWidth(), _playerProfile._image->getHeight());
	
	//�÷��̾� UI��
	_playerHPBar._image = IMAGEMANAGER->findImage("BATTLE_playerBar");
	_playerHPBar._rc = RectMakeCenter(450, 86, _playerHPBar._image->getWidth(), _playerHPBar._image->getHeight());

	//�÷��̾� HP
	_playerHP = 24;

	for (int i = 0; i < _playerHP; i++)
	{
		_playerHPPoint[i]._image = IMAGEMANAGER->findImage("BATTLE_HP");
		_playerHPPoint[i]._rc = RectMakeCenter(270+i*16, 53, _playerHPPoint[i]._image->getWidth(), _playerHPPoint[i]._image->getHeight());
	}

	//��ȭ ��ũ��Ʈ
	scriptStart = false;
	scriptEnd = true;
	_scriptSkip = false;
	scriptImage = IMAGEMANAGER->findImage("SCENE_dialogWindow");
	scriptRc = RectMakeCenter(WINSIZEX / 2, 670, scriptImage->getWidth(), scriptImage->getHeight());
	_scriptIndex = _txtIndex = 0;
	scriptSkip = IMAGEMANAGER->findImage("SCENE_skipOutlines2");
	_vScript = TXTDATA->txtLoad("Resource/��ȭ.txt");
	kScript = IMAGEMANAGER->findImage("SCENE_kyoko1");
	mScript = IMAGEMANAGER->findImage("SCENE_misuzu1");
	scriptName = IMAGEMANAGER->findImage("SCENE_kyokoName");

	//�� �̺�Ʈ
	mapLocked = false;
	mapUnlocked = true;
	chainTop = IMAGEMANAGER->findImage("BATTLE_stageChainTop");
	chainBottom = IMAGEMANAGER->findImage("BATTLE_stageChainBottom");
	chainLeft = IMAGEMANAGER->findImage("BATTLE_stageChainLeft");
	chainRight = IMAGEMANAGER->findImage("BATTLE_stageChainRight");
	chainLock = IMAGEMANAGER->findImage("BATTLE_lockAppear");

	return S_OK;
}

void gameManager::release()
{
}

void gameManager::update()
{
	//�÷��̾� HP
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

	//��ȭ ��ũ��Ʈ
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
	
	//�� �̺�Ʈ
	if (KEYMANAGER->isOnceKeyDown(VK_F2) && !mapLocked)
	{
		mapLocked = true;
	}
	if (mapLocked && KEYMANAGER->isOnceKeyDown(VK_F2))
	{
		mapLocked = false;
	}

	_count++;
	if (_count % 30 == 0)
	{
		chainLock->setFrameX(_index);
		_index++;

		if (_index >= chainLock->getMaxFrameX()) _index = 6;
		_count = 0;
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
		scriptName->render(getMemDC(), 0, 610);

		SetBkMode(getMemDC(), TRANSPARENT);
		SetTextColor(getMemDC(), RGB(255, 255, 255));
		RECT rcText = RectMake(190, 630, 1070, 200);

		HFONT font = CreateFont(35, 0, 0, 0, 200, false, false, false,
			DEFAULT_CHARSET, OUT_STROKE_PRECIS, CLIP_DEFAULT_PRECIS,
			PROOF_QUALITY, DEFAULT_PITCH | FF_SWISS, TEXT("�޸ո���ü"));

		HFONT oldFont = (HFONT)SelectObject(getMemDC(), font);

		DrawText(getMemDC(), TEXT(_txt.c_str()), _txtIndex, &rcText, DT_VCENTER | DT_VCENTER | DT_WORDBREAK);

		SelectObject(getMemDC(), oldFont);
		DeleteObject(font);
	}
	if (scriptEnd)
	{
		//���� �������� ����
	}

	if (mapLocked)
	{
		eventMap();
	}
	if (!mapLocked)
	{
		//ī�޶� ������,.??
	}
}

void gameManager::scriptPlay()
{
	_txt = _vScript[_scriptIndex];

	if (_scriptIndex == 0 || _scriptIndex == 1 || _scriptIndex == 3 || _scriptIndex == 5 || _scriptIndex == 7 || _scriptIndex == 9 || _scriptIndex == 10)
	{
		if ( _scriptIndex == 5)
		{
			kScript = IMAGEMANAGER->findImage("SCENE_kyoko2");
		}
		if (_scriptIndex == 7 || _scriptIndex == 9 || _scriptIndex == 10)
		{
			kScript = IMAGEMANAGER->findImage("SCENE_kyoko3");
		}
		kScript->render(getMemDC(), 30, 150);
		scriptName = IMAGEMANAGER->findImage("SCENE_kyokoName");
	}
	
	if (_scriptIndex == 2 || _scriptIndex == 4 || _scriptIndex == 6 || _scriptIndex == 8 || _scriptIndex == 11)
	{
		mScript = IMAGEMANAGER->findImage("SCENE_misuzu1");
		if (_scriptIndex == 6 || _scriptIndex == 11)
		{
			mScript = IMAGEMANAGER->findImage("SCENE_misuzu2");
		}
		if (_scriptIndex == 8)
		{
			mScript = IMAGEMANAGER->findImage("SCENE_misuzu3");
		}
		mScript->render(getMemDC(), 850, 160);
		scriptName = IMAGEMANAGER->findImage("SCENE_misuzuName");
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

void gameManager::eventMap()
{
	chainTop->render(getMemDC(), 0, 0);
	chainBottom->render(getMemDC(), 0, WINSIZEY-40);
	chainLeft->render(getMemDC(), 0, 0);
	chainRight->render(getMemDC(), WINSIZEX-40, 0);

	//chainLock = IMAGEMANAGER->findImage("BATTLE_lockAppear");
	if (KEYMANAGER->isOnceKeyDown('1'))
	{
		chainLock = IMAGEMANAGER->findImage("BATTLE_lockDamage1");
	}
	else if (KEYMANAGER->isOnceKeyDown('2'))
	{
		chainLock = IMAGEMANAGER->findImage("BATTLE_lockDamage2");
	}
	else if (KEYMANAGER->isOnceKeyDown('3'))
	{
		chainLock = IMAGEMANAGER->findImage("BATTLE_lockDisappear");

		mapLocked = false;
	}
	
	chainLock->frameRender(getMemDC(), WINSIZEX / 2, 0);
}