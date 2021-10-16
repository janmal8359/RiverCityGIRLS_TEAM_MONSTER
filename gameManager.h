#pragma once
#include "gameNode.h"
#include <string>
#include "progressBar.h"



class pixelCollisionClass;

class player;

struct UIBar
{
	image* _image;
	RECT _rc;
	float _x, _y;
};

class gameManager : public gameNode
{
private:
	
	UIBar _playerProfile;
	UIBar _playerHPBar;
	UIBar _playerHPPoint[24];
	UIBar _playerHPBackground;

	bool mapLocked;
	bool mapUnlocked;
	image* chainTop;
	image* chainBottom;
	image* chainLeft;
	image* chainRight;
	image* chainLock;
	int _count, _index;

	// ��ũ��Ʈ
	bool scriptStart;			// ����
	bool scriptEnd;				// ��
	RECT scriptRc;				// ��Ʈ
	image* scriptImage;			// ����̹���
	int _scriptIndex;			// ��ũ��Ʈ �ε���
	int _txtIndex;				// �ؽ�Ʈ �ε���
	vector<string> _vScript;	// ��ũ��Ʈ ����
	string _txt;				// ���ڿ�
	image* scriptSkip;			// ��ŵ �̹���
	bool _scriptSkip;			// ��ŵ ����

	image* kScript;				// ����
	image* mScript;				// �̽���
	image* scriptName;			// ��ũ��Ʈ �̸�


	

	int _playerHP;

	player* _player;

	pixelCollisionClass* _pix;

public:
	gameManager();
	~gameManager();

	HRESULT init();
	void release();
	void update();
	void render();

	void scriptPlay();

	void eventMap();

	bool getScriptEnd() { return scriptEnd; }
	void setScriptEnd(bool end) { scriptEnd = end; }

	bool getScriptStart() { return scriptStart; }
	void setScriptStart(bool start) { scriptStart = start; }




	void setPixelM(pixelCollisionClass* pixel) { _pix = pixel; }

	void setPlayer(player* pl) { _player = pl; }
};

