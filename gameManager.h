#pragma once
#include "gameNode.h"
#include <string>
#include "progressBar.h"


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

	bool scriptStart;
	bool scriptEnd;
	RECT scriptRc;
	image* scriptImage;
	int _scriptIndex;
	int _txtIndex;
	vector<string> _vScript;
	string _txt;
	image* scriptSkip;
	bool _scriptSkip;

	image* kScript;
	image* mScript;
	image* scriptName;

	//progressBar* _skip;
	//float _currentGauge, _maxGauge;
	

	int _playerHP;

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
};

