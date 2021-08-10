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
	
	//�� �ڹ���
	mapLocked = false;
	mapUnlocked = true;

	//��ȭ ��ũ��Ʈ
	scriptStart = false;
	scriptEnd = true;
	scriptImage = IMAGEMANAGER->findImage("SCENE_dialogWindow");
	scriptRc = RectMakeCenter(WINSIZEX / 2, 650, scriptImage->getWidth(), scriptImage->getHeight());
	_scriptIndex = _txtIndex = 0;
	
	_vScript = TXTDATA->txtLoad("Resource/��ȭ.txt");

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
	for (int i = 0; i < _playerHP; i++) {
		_playerHPPoint[i]._rc = RectMakeCenter(270 + i * 16, 53, _playerHPPoint[i]._image->getWidth(), _playerHPPoint[i]._image->getHeight());
	}

	//�� �̺�Ʈ
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

	//��ȭ ��ũ��Ʈ
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
		scriptImage->render(getMemDC(), scriptRc.left, scriptRc.top);

	}
	if (scriptEnd)
	{
		//IMAGEMANAGER->findImage("")
	}
}

void gameManager::scriptPlay()
{

	_txt = _vScript[_scriptIndex];

	if (_txtIndex <= _txt.length())
	{
		_txtIndex++;
	}
	else if (_txtIndex >= _txt.length() && KEYMANAGER->isOnceKeyDown(VK_RETURN))
	{
		_scriptIndex++;
		_txtIndex = 0;
	}

	if (_txtIndex < _txt.length() && KEYMANAGER->isOnceKeyDown(VK_RETURN))
		_txtIndex = _txt.length();

	if (_scriptIndex >= _vScript.size())
	{
		scriptStart = false;
		scriptEnd = true;
	}
}